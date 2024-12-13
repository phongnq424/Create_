#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

int x1, x2, x3, x4, x5, x6;
int w, v, y, z, ans;
sem_t semA, semB, semC, semD, semE, semF;

void *processA(void* mess)
{
    w = x1 * x2;
    sem_post(&semA);
}

void *processB(void* mess)
{
    v = x3 * x4;
    sem_post(&semB);
}

void *processC(void* mess)
{
    sem_wait(&semB);
    y = v * x5;
    sem_post(&semB); sem_post(&semC);
}

void *processD(void* mess)
{
    sem_wait(&semB);
    z = v * x6;
    sem_post(&semB); sem_post(&semD);
}

void *processE(void* mess)
{
    sem_wait(&semA); sem_wait(&semC);
    y = w * y;
    sem_post(&semA); sem_post(&semC); sem_post(&semE);
}

void *processF(void* mess)
{
    sem_wait(&semA); sem_wait(&semD);
    z = w * z;
    sem_post(&semF);
}

void *processG(void* mess)
{
    sem_wait(&semE); sem_wait(&semF);
    ans = y + z;
    sem_post(&semE); sem_post(&semF);
}

int main()
{
    printf("Nhap x1, x2, x3, x4, x5, x6: \n");
    scanf("%d %d %d %d %d %d", &x1, &x2, &x3, &x4, &x5, &x6);
    sem_init(&semA, 0, 0);
    sem_init(&semB, 0, 0);
    sem_init(&semC, 0, 0);
    sem_init(&semD, 0, 0);
    sem_init(&semE, 0, 0);
    sem_init(&semF, 0, 0);
    pthread_t pA, pB, pC, pD, pE, pF, pG;
    pthread_create(&pA, NULL, processA, NULL);
    pthread_create(&pB, NULL, processB, NULL);
    pthread_create(&pC, NULL, processC, NULL);
    pthread_create(&pD, NULL, processD, NULL);
    pthread_create(&pE, NULL, processE, NULL);
    pthread_create(&pF, NULL, processF, NULL);
    pthread_create(&pG, NULL, processG, NULL);
    while (ans == 0) {}
    printf("Ket qua cuoi cung: %d\n", ans);
}