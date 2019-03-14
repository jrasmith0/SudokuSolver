/**
 * Thread Pooling done way over-complicated
 * 
 * (c) EAJM 2019 
 */

// Max threads ... this is relative
#define MAX_THREADS 1000
typedef void *threadPool;
typedef void (*fn)(void *);
threadPool createThreadPool(int size);
void dispatchThread(threadPool source, fn dispatchFn, void *arg);
void destroyThreadPool(threadPool toDestroy);
