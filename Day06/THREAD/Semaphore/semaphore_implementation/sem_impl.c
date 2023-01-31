/*
    Implementation of SEMAPHORES
*/

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_01();
void *thread_02();
void *thread_03();

int a, b;
sem_t sem_lock;
sem_t sem_lock1;
sem_t sem_lock2;

int main()
{
    pthread_t t1_id, t2_id, t3_id;
    sem_init(&sem_lock, 0, 2);
    sem_init(&sem_lock1, 0, 0);
    sem_init(&sem_lock2, 0, 0);


    pthread_create(&t1_id, NULL, thread_01, NULL);
    pthread_create(&t2_id, NULL, thread_02, NULL);
    pthread_create(&t3_id, NULL, thread_03, NULL);

    sleep(1);

    pthread_join(t1_id, NULL);
    pthread_join(t2_id, NULL);
    pthread_join(t3_id, NULL);

    sem_destroy(&sem_lock);
    sem_destroy(&sem_lock1);

    return 0;   
}

void *thread_01()
{
    sem_wait(&sem_lock);
    printf("Enter the values for a and b :: \n");
    scanf("%d %d", &a, &b);
    sem_post(&sem_lock1);
}

void *thread_02()
{
    int c = 0;
    sem_wait(&sem_lock1);
    c = a + b;
    printf("Sum :: %d\n", c);
    sem_post(&sem_lock2);
}

void *thread_03()
{
    sem_wait(&sem_lock2);
    printf("in th3 \n");
    sem_post(&sem_lock);
}