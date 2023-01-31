/* 
Implementation of Shared Memory Inter Process Communication
This is sender program
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>        /* For mode constants */
#include <fcntl.h>           /* For O_* constants */
#include <unistd.h>
#include <sys/types.h> 

int *count_r;
int main()
{
    int shm_desc = 0; // shared memory descriptor
    int ftr_err = 0;

    /*
    This is the API for creating or opening shared memory objects.

    int shm_open(const char *name, int oflag, mode_t mode);

        - Here, 1st argument is "/name_of_shared_memory_object"
            ()
    */
    shm_desc = shm_open("/desdshm", O_CREAT | O_RDWR, 00600);
    if (shm_desc == -1) {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    ftr_err = ftruncate(shm_desc, sizeof(int));
    if (ftr_err == -1) {
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    /*
    void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

    */
    count_r = (int *)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, shm_desc, 0);
    while(1)
    {
        printf("Received Count :: %d\n", (*count_r));
        sleep(1);
    }

    return 0;
}