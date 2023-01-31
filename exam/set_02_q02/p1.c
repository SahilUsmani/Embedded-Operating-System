
#include "p.h"
extern sem_t semlock;
extern sem_t semlock1;
char *send;
int main()
{
    int fd_file = 0;
    int read_ret = 0;
    int shm_desc = 0;
    int ftr_err = 0;
    int ret_cls = 0;
    char buff[30000];


    sem_init(&semlock1,1,1);
    sem_init(&semlock,1,0);
    fd_file = open("/usr/include/stdio.h", O_RDONLY);

    if (fd_file == -1) {
        perror("Open File Error");
        exit(EXIT_FAILURE);
    }

    read_ret = read(fd_file, buff, sizeof(buff));

    if (read_ret == -1) {
        perror("Read File Error");
        exit(EXIT_FAILURE);
    }

sem_wait(&semlock1);
    shm_desc = shm_open("/sahilshm", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    if (shm_desc == -1) { // error handling for opening and creating shared memory
        perror("shm_open");
        exit(EXIT_FAILURE);
    }

    ftr_err = ftruncate(shm_desc, sizeof(buff));
    if (ftr_err == -1) { // error handling for ftruncate
        perror("ftruncate");
        exit(EXIT_FAILURE);
    }

    send = (char *)mmap(NULL, sizeof(buff), PROT_READ | PROT_WRITE, MAP_SHARED, shm_desc, 0);

    // for(int i = 0; i <= 29950; i++)
    // {
    //     *send = buff[i];
    //     printf("%c", *send);
    // }
sem_post(&semlock);
    ret_cls = close(fd_file);
    if (ret_cls == -1) {
        perror("Close File Error");
        exit(EXIT_FAILURE);
    }

    return 0;


}