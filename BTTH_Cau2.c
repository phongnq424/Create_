#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
sem_t sem1;
sem_t sem2;
sem_t busy;
int *a;
int count = 0;

void *processPush(void* mess)
{
    while (1)
    {
        sem_wait(&sem2);
        sem_wait(&busy);
        count++;
        a[count] = rand();
        printf("So phan tu sau khi them vao: %d\n", count);
        sem_post(&sem1);
        sem_post(&busy);
    }
}

void *processPop(void* mess)
{
    while (1)
    {
        sem_wait(&sem1);
        sem_wait(&busy);
        count--;
        if (count > 0)
            printf("So phan tu trong a sau khi lay ra la: %d\n", count);
        else    
            printf("Nothing in array a\n");
        sem_post(&sem2);
        sem_post(&busy);
    }
}

int main()
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    srand((unsigned)time(NULL));
    sem_init(&sem1, 0, 0);
    sem_init(&sem2, 0, n);
    sem_init(&busy, 0, 1);
    pthread_t pA, pB;
    pthread_create(&pA, NULL, &processPush, NULL);
    pthread_create(&pB, NULL, &processPop, NULL);
    while (1) {}
    return 0;
}