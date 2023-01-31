/* Write a pthread c program to find the minimum value in the integer list */


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

#define handle_error_en(en, msg) \
                do {errno = en; perror(msg); exit(EXIT_FAILURE);} while(0)


int main()
{
    pthread_t min_thread = 0;
    int s = 0;
    int num_int;

    printf("How many integers you want in the list :: ");
    scanf("%d", &num_int);

    int num_list[num_int];
    printf("Enter the numbers for the list\n");

    for (int i = 0; i <= (num_int-1); i++) {
        printf("Enter the number for index %d of the list :: ", i);
        scanf("%d", num_list[i]);
    }

    s = pthread_create(&min_thread, NULL, minimum, NULL)
    if (s != 0) {
        handle_error_en(s, "pthread_create");
    }

    s = pthread_join(min_thread, NULL);
    if (s != 0) {
        handle_error_en(s, "pthread_join");
    }

    return 0;
}

void *minimum(void *data)
{
    
}
