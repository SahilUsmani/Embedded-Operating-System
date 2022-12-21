/* Write a pthread program to create 3 threads to print Hello */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <unistd.h>

#define handle_error_en(en, msg) \
               do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)

#define handle_error(msg) \
               do { perror(msg); exit(EXIT_FAILURE); } while (0)

void *Hello_01(void *data);
void *Hello_02(void *data);
void *Hello_03(void *data);

int main()
{
    int s = 0;

    pthread_t thread_01;
    pthread_t thread_02;
    pthread_t thread_03;

    /*
    
    For THREAD CREATION use below function:- 

    int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
                          void *(*start_routine) (void *), void *arg);

    In the 1st argument we're passing the address of pthread_t thread_01 etc.

    In the 2nd argument we're passing NULL as we don't want to pass any attributes.

    In the 3rd argument we're passing start routine which is our function(which will be used to do operation for threads)

    In the 4th argument we're passing NULL as our function is not taking any arguments

    

    */

    s = pthread_create(&thread_01, NULL, Hello_01, NULL);
    if(s != 0)
    {
        handle_error_en(s, "pthread_create");
    }
    s = pthread_create(&thread_02, NULL, Hello_02, NULL);
     if(s != 0)
    {
        handle_error_en(s, "pthread_create");
    }
    s = pthread_create(&thread_03, NULL, Hello_03, NULL);
     if(s != 0)
    {
        handle_error_en(s, "pthread_create");
    }

    /*
    Joining with each thread using below function :- 

    int pthread_join(pthread_t thread, void **retval);

    In the 1st argument we are passing our variable for thread id

    In the 2nd argument we're passing NULL because we don't want any return value that's why NULL
    
    NOTE:-

        Joining with a thread that has previously been joined results in undefined behavior.
    */

    

    s = pthread_join(thread_01, NULL);
    if(s != 0)
    {
        handle_error_en(s, "pthread_join");
    }

    s = pthread_join(thread_02, NULL);
    if(s != 0)
    {
        handle_error_en(s, "pthread_join");
    }

    s = pthread_join(thread_03, NULL);
    if(s != 0)
    {
        handle_error_en(s, "pthread_join");
    }



    return 0;
}

void *Hello_01(void *data)
{
    printf("Hello! This is thread 01\n");
}

void *Hello_02(void *data)
{
    printf("Hello! This is thread 02\n");
}

void *Hello_03(void *data)
{
    printf("Hello! This is thread 03\n");
}
