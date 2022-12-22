/* Write a Pthread C program to swap two numbers */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>

void *swap(void *data);

typedef struct inputs {  // using typdef
    int var1;
    int var2;
}arguments;


int main()
{
    pthread_t thread_01;
    int s = 0;

    arguments arg;

    printf("Enter the 1st number :: ");
    scanf("%d", &arg.var1);
    printf("Enter the 2nd number :: ");
    scanf("%d", &arg.var2);

    printf("The 1st number is :: %d\n", arg.var1);
    printf("The 2nd number is :: %d\n", arg.var2);

    s = pthread_create(&thread_01, NULL, swap, (void *)&arg);

    /*  
    Error handling for pthread_create
    - On success, pthread_create() returns 0; 
      on error, it returns an error number, and the contents of *thread are undefined.
    */
    if (s != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    s = pthread_join(thread_01, NULL);

    /*
    Error handling for pthread_join
    - On success, pthread_join() returns 0; on error, it returns an error number.
    */
    if (s != 0) { 
       perror("pthread_join");
       exit(EXIT_FAILURE);
    }

    // checking the swap functionality outside of thread
    printf("\nInside Main after thread termination\n");
    printf("The 1st number is :: %d\n", arg.var1);
    printf("The 2nd number is :: %d\n", arg.var2);
    return 0;
}

void *swap(void *data)
{
    arguments *my_inputs;
    int temp = 0;

    my_inputs = (arguments *)data;

    // swap algorithm
    temp = my_inputs->var1;
    my_inputs->var1 = my_inputs->var2;
    my_inputs->var2 = temp;

    printf("\nInside thread\n");
    printf("The variables are now swapped\n");
    printf("The 1st number is :: %d\n", my_inputs->var1);
    printf("The 2nd number is :: %d\n", my_inputs->var2);
}