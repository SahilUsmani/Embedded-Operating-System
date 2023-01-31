#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *Inc_Thread(void *data);
void *Dec_Thread(void *data);

int count = 0;
pthread_mutex_t lock;

int main(void)
{
    pthread_t thread_inc, thread_dec;
    
    printf("In Main\n");
    /* int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
    void *(*start_routine) (void *), void *arg);*/
    
    pthread_mutex_init(&lock, NULL);

    pthread_create(&thread_inc, NULL, Inc_Thread, NULL);
    pthread_create(&thread_dec, NULL, Dec_Thread, NULL);
    
    sleep(1);
    pthread_mutex_destroy(&lock);
    return 0;
}

void *Inc_Thread(void *data)   //taking void pointer as return type so that it can be typecasted
{
    while(1)
    {
        pthread_mutex_lock(&lock);
        count++;
        printf("Inc :: %d\n", count);
        pthread_mutex_unlock(&lock);
    }
}

void *Dec_Thread(void *data)   //taking void pointer as return type so that it can be typecasted
{
    while(1)
    {
        pthread_mutex_lock(&lock);
        count--;
        printf("Dec :: %d\n", count);
        pthread_mutex_unlock(&lock);
    }
}