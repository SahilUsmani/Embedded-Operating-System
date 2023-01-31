#include "p.h"
char *recv;
extern sem_t semlock;
extern sem_t semlock1;

// struct sem_data{
//     extern sem_t semlock,
//     extern sem_t semlock1,
//     char buff[9000],
//     int count
// };
int main()
{
    int fd_file = 0;
    int read_ret = 0;
    int shm_desc = 0;
    int ftr_err = 0;
    int ret_cls = 0;
    char buff[30000];
    int count = 0;


    // fd_file = open("/usr/include/stdio.h", O_RDONLY);

    // if (fd_file == -1) {
    //     perror("Open File Error");
    //     exit(EXIT_FAILURE);
    // }

    // read_ret = read(fd_file, buff, sizeof(buff));

    // if (read_ret == -1) {
    //     perror("Read File Error");
    //     exit(EXIT_FAILURE);
    // }
sem_wait(&semlock);
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


    recv = (char *)mmap(NULL, sizeof(buff), PROT_READ | PROT_WRITE, MAP_SHARED, shm_desc, 0);

    while(*recv != '\0')
    {
        printf("%c\n", *recv);
        if(*recv == 's')
        {
            count++;
        }
    }
sem_post(&semlock1);
   // printf("%c\n", *recv);



    ret_cls = close(fd_file);
    if (ret_cls == -1) {
        perror("Close File Error");
        exit(EXIT_FAILURE);
    }

    return 0;


}