#include <stdio.h>
#include "threadPool.h"

threadPool mainThreadPool;

void print(int i) {
    sleep(1);
    printf("%i\n", i);
    if (i == 299) {
        destroyThreadPool(mainThreadPool);
    }
}

int main(void)  
{
    mainThreadPool = createThreadPool(500);
    int j = 0;
    while(1) {
        if (j == 0) {
            for (int i = 0; i < 300; i++) {
                dispatchThreadPool(mainThreadPool, print, i);
            }
            j = 1;
        }
    }
    return 0;
}
