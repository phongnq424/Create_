#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
int sells = 0, products = 0;
sem_t sem1, sem2;

void *processA(void* mess)
{
    while (1)
    {
        sem_wait(&sem1);
        sells++;
        printf("Sell: %d\n", sells);
        sem_post(&sem2);
    }
}
void *processB(void* mess)
{
    while (1)
    {
        sem_wait(&sem2);
        products++;
        printf("Product: %d\n", products);
        sem_post(&sem1);
    }
}

int main()
{
    pthread_t pA, pB;
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, 1169);
    pthread_create (&pA, NULL, &processA, NULL);
    pthread_create (&pB, NULL, &processB, NULL);
    while (1) {}
    return 0;
}