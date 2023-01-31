#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{
    //int fd_file = 0; // file descriptor for opening file
    int fd_fifo = 0; // file descriptor for opening fifo
    int nbytes_read = 0; // ret value for read fifo
    int cls_ret_fifo = 0; // ret value for close fifo
    char buff[29960];
    int count = 0;

    
    fd_fifo = open("sahilfifo", O_RDONLY);

    if (fd_fifo == -1) {// error handling for fifo opening
        perror("Fifo Opening Error");
        exit(EXIT_FAILURE);
    }

    nbytes_read = read(fd_fifo, buff, sizeof(buff));
    if (nbytes_read == -1) {
        perror("Read Error");
        exit(EXIT_FAILURE);
    }
    

    // calculating the occurrence of letter 's'
   for(int i=0; i<=(strlen(buff) - 1); i++) {
        if (buff[i] == 's') {
            count++;
        }
   }
    
    printf("The occurrence of the character s is :: %d\n", count);
    
    cls_ret_fifo = close(fd_fifo);

    if (cls_ret_fifo == -1) { // error handling for closing of fifo
        perror("Fifo CLosing Error");
        exit(EXIT_FAILURE);
    }
    return 0;


}