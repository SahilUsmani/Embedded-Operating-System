/* Write a Pthread C program to find the sum of n integers */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

void *sum_of_int(void *);

int main()
{
    pthread_t thread_01 = 0;
    int num = 0;
    int s = 0;

    printf("Enter the Number :: ");
    scanf("%d", &num);

    s = pthread_create(&thread_01, NULL, sum_of_int, (void *)&num);

    /*  
    Error handling for pthread_create
    - On success, pthread_create() returns 0; 
      on error, it returns an error number, and the contents of *thread are undefined.
    */

    if (s != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    /* if don't want to pass arguments from pthread_create() to thread use this -
        pthread_create(&thread_01, NULL, sum_of_int, NULL);
        if (s != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
        }
    */

    s = pthread_join(thread_01, NULL);

    /*
    Error handling for pthread_join
    - On success, pthread_join() returns 0; on error, it returns an error number.
    */

    if (s != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
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

