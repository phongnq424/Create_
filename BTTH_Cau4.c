#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
int x = 0;
pthread_mutex_t mutex;

void *processA(void* mess)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        x = x + 1;
        if (x == 20) x = 0;
        printf("A: %d\n",x);
        pthread_mutex_unlock(&mutex);
    }
}
void *processB(void* mess)
{
    while (1)
    {
        pthread_mutex_lock(&mutex);
        x = x + 1;
        if (x == 20) x = 0;
        printf("B: %d\n", x);
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{
    pthread_t pA, pB;
    pthread_create (&pA, NULL, &processA, NULL);
    pthread_create (&pB, NULL, &processB, NULL);
    while (1) {}
    return 0;
}