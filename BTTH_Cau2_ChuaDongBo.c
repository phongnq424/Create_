#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>
int *a;
int count = 0;
int n;

void *processPush(void* mess)
{
    while (1)
    {
        if (count  < n)
        {
            count++;
            a[count] = rand();
            printf("So phan tu sau khi them vao: %d\n", count);
        }
    }
}

void *processPop(void* mess)
{
    while (1)
    {
        if (count > 0)
        {
            count--;
            if (count > 0)
                printf("So phan tu trong a sau khi lay ra la: %d\n", count);
            else    
                printf("Nothing in array a\n");
        }
    }
}

int main()
{
    printf("Nhap n: ");
    scanf("%d", &n);
    a = (int*)malloc(n * sizeof(int));
    srand((unsigned)time(NULL));
    pthread_t pA, pB;
    pthread_create(&pA, NULL, &processPush, NULL);
    pthread_create(&pB, NULL, &processPop, NULL);
    while (1) {}
    return 0;
}