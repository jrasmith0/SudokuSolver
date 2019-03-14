#include <pthread.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include "threadPool.h"

typedef struct _func {
	void (*fn)(void *);
	void *arg;
	struct func *next;
} func_t;

typedef struct _threadPool {
	int threadPoolSize;
	int threadQueueSize;
	int stop;
	int cannotAccept;
	pthread_t *threads;
	func_t *threadQueueHead;
	func_t *threadQueueTail;
	pthread_mutex_t threadQueueLock;
	pthread_cond_t threadQueueNotEmpty;
	pthread_cond_t threadQueueEmpty;
} threadPool_t;

void *do_work(threadPool p) {
	threadPool_t *pool = (threadPool_t *)p;
	func_t *queue;
	int i;

	while (1) {
		pool->threadQueueSize = pool->threadQueueSize;
		pthread_mutex_lock(&(pool->threadQueueLock));
		while (pool->threadQueueSize == 0) {
			if (pool->stop) {
				pthread_mutex_unlock(&(pool->threadQueueLock));
				pthread_exit(NULL);
			}
			pthread_mutex_unlock(&(pool->threadQueueLock));
			pthread_cond_wait(&(pool->threadQueueNotEmpty), &(pool->threadQueueLock));
			if (pool->stop) {
				pthread_mutex_unlock(&(pool->threadQueueLock));
				pthread_exit(NULL);
			}
		}
		queue = pool->threadQueueHead;
		pool->threadQueueSize--;
		if (pool->threadQueueSize == 0) {
			pool->threadQueueHead = NULL;
			pool->threadQueueTail = NULL;
		} else {
			pool->threadQueueHead = queue->next;
		}
		if (pool->threadQueueSize == 0 && !pool->stop) {
			pthread_cond_signal(&(pool->threadQueueEmpty));
		}
		pthread_mutex_unlock(&(pool->threadQueueLock));
		(queue->fn)(queue->arg);
		free(queue);
	}
}

threadPool createThreadPool(int size) {
	threadPool_t *pool;
	if (size <= 0 || size > MAX_THREADS) {
		return NULL;
	}
	pool = (threadPool_t *)malloc(sizeof(threadPool_t));
	pool->threads = (pthread_t *)malloc(sizeof(pthread_t) * size);
	pool->threadPoolSize = size;
	pool->threadQueueSize = 0;
	pool->threadQueueHead = NULL;
	pool->threadQueueTail = NULL;
	pool->stop = 0;
	pool->cannotAccept = 0;

	if (pthread_mutex_init(&pool->threadQueueLock, NULL)) {
		return NULL;
	}
	if (pthread_cond_init(&(pool->threadQueueEmpty), NULL)) {
		return NULL;
	}
	if (pthread_cond_init(&(pool->threadQueueNotEmpty), NULL)) {
		return NULL;
	}

	for (int i = 0; i < size; i++) {
		if (pthread_create(&(pool->threads[i]), NULL, do_work, pool)) {
			return NULL;
		}
		printf("\n");
	}
	return (threadPool)pool;
}

void dispatchThreadPool(threadPool p, fn work, void *arg) {
  	threadPool_t *pool = (threadPool_t *) p;
	func_t * queue;
	int k = pool->threadQueueSize;
	queue = (func_t*) malloc(sizeof(func_t));
	if(queue == NULL) {
		return NULL;
	}
	queue->fn = work;
	queue->arg = arg;
	queue->next = NULL;
	pthread_mutex_lock(&(pool->threadQueueLock));
	if(pool->cannotAccept) {
		free(queue);
		return NULL;
	}
	if(pool->threadQueueSize == 0) {
		pool->threadQueueHead = queue;
		pool->threadQueueTail = queue;
		pthread_cond_signal(&(pool->threadQueueNotEmpty));
	} else {
		pool->threadQueueTail->next = queue;
		pool->threadQueueTail = queue;
	}
	pool->threadQueueSize++;
	pthread_mutex_unlock(&(pool->threadQueueLock));
}

void destroyThreadPool(threadPool toDestroy) {
	threadPool_t *pool = (threadPool_t *) toDestroy;
	free(pool->threads);
	pthread_mutex_destroy(&(pool->threadQueueLock));
	pthread_cond_destroy(&(pool->threadQueueNotEmpty));
	pthread_cond_destroy(&(pool->threadQueueEmpty));
	return;
}
