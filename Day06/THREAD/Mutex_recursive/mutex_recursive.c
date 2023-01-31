/* We're using recursive type mutex to avoid deadlock */



#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *Inc_Thread(void *data);
void *Dec_Thread(void *data);

int count = 0;
pthread_mutex_t lock; // declaraing mutex
pthread_mutexattr_t mutexat; //declaring mutex attribute 

int main(void)
{
    pthread_t thread_inc, thread_dec;
    
    printf("In Main\n");
    /* int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
    void *(*start_routine) (void *), void *arg);*/
    
    pthread_mutexattr_init(&mutexat); // initializing mutex attribute
    pthread_mutexattr_settype(&mutexat, PTHREAD_MUTEX_RECURSIVE); // setting the type of mutex attribute mutexat as recursive type mutex
    pthread_mutex_init(&lock, &mutexat);

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
        //pthread_mutex_lock(&lock);
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
        pthread_mutex_lock(&lock); // when we give lock here it goes into a deadlock but because we're using recursive type mutex it won't
        count--;
        printf("Dec :: %d\n", count);
        pthread_mutex_unlock(&lock);
    }
}