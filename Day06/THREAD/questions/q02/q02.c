/* Write a Pthread C program to find the sum of n integers */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

#define handle_error_en(en, msg) \
                do{ errno = en; perror(msg); exit(EXIT_FAILURE);} while(0)

void *sum_of_int(void *);

int main()
{
    pthread_t thread_01 = 0;
    int num = 0;
    int s = 0;

    printf("Enter the Number :: ");
    scanf("%d", &num);

    s = pthread_create(&thread_01, NULL, sum_of_int, (void *)&num);

    if (s != 0) { // error handling for pthread_create
        handle_error_en(s, "pthread_create");
    }

    /* if don't want to pass arguments from pthread_create() to thread use this -
        pthread_create(&thread_01, NULL, sum_of_int, NULL);
        if (s != 0) {
        handle_error_en(s, "pthread_create");
        }
    */

    s = pthread_join(thread_01, NULL);
    if (s != 0) { // error handling for pthread_join
        handle_error_en(s, "pthread_join");
    }

    return 0;
}


/*

Code if we don't want to pass any arguments from pthread_create() to our thread

void *sum_of_int(void *data)
{
    int num = 0;
    int i = 0;
    int sum = 0;
    printf("Enter the number\t");
    scanf("%d", &num);

    for(i=1; i<=num; i++)
    {
        sum = sum + i;
    }

    printf("The sum is :: %d\n", sum);

}
*/


/* If we want to pass the argument from pthread_create() to our thread */

void *sum_of_int(void * data)
{
    int i = 0;
    int sum = 0;
    int *var = (int *)data;

    for(i=1; i <= *var; i++)
    {
        sum = sum + i;
    }

    printf("The sum of integers upto %d is :: %d\n", *var, sum);

}

