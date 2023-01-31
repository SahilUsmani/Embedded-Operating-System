#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *addition(void *data);
void *subtraction(void *data);
void *multiplication(void *data);
void *division(void *data);

int main(void)
{
    pthread_t thread_sum;
    pthread_t thread_diff;
    pthread_t thread_mul;
    pthread_t thread_div;

    printf("Inside Main\n");

    pthread_create(&thread_sum, NULL, addition, NULL);
    pthread_create(&thread_diff, NULL, subtraction, NULL);
    pthread_create(&thread_mul, NULL, multiplication, NULL);
    pthread_create(&thread_div, NULL, division, NULL);

    pthread_join(thread_sum, NULL);
    pthread_join(thread_diff, NULL);
    pthread_join(thread_mul, NULL);
    pthread_join(thread_div, NULL);

    return 0;
}

void *addition(void *data)
{
    printf("Entry inside Sum\n");
    int num_1 = 20;
    int num_2 = 10;
    int sum = 0;

    sum = num_1 + num_2;

    printf("Value of Sum:: %d\n", sum);
}

void *subtraction(void *data)
{
    printf("Entry inside Difference\n");
    int num_1 = 20;
    int num_2 = 10;
    int diff = 0;

    diff = num_1 + num_2;

    printf("Value of Difference:: %d\n", diff);
}

void *multiplication(void *data)
{
    printf("Entry inside Product\n");
    int num_1 = 20;
    int num_2 = 10;
    int mul = 0;

    mul = num_1 + num_2;

    printf("Value of Product:: %d\n", mul);
}

void *division(void *data)
{
    printf("Entry inside Division\n");
    int num_1 = 20;
    int num_2 = 10;
    int div = 0;

    div = num_1 + num_2;

    printf("Value of Division:: %d\n", div);
}