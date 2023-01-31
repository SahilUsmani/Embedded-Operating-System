#include <stdio.h>
#include <pthread.h>

void *add(void *data);

int main(void)
{
    pthread_t thread_1;
    printf("In Main\n");
    /* int pthread_create(pthread_t *thread, const pthread_attr_t *attr, 
    void *(*start_routine) (void *), void *arg);*/
    printf("Before thread\n");
    pthread_create(&thread_1, NULL, add, NULL);// 
    pthread_join(thread_1, NULL); //after doing this the function add was executing
    printf("After thread joining\n");


}

void *add(void *data)   //taking void pointer as return type so that it can be typecasted
{
    int a = 10;
    int b = 20;
    int sum = 0;

    sum = a + b;
    printf("Value of sum is %d\n", sum);
}