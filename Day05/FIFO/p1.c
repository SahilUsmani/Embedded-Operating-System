#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int fd = 0;
    int nbytes_write = 0;
    fd = open("desdfifo", O_WRONLY);
    if(fd == -1)
    {
        perror("Open Error");
        exit(EXIT_FAILURE);
    }

    nbytes_write = write(fd, "Hello Desd\n", strlen("Hello Desd\n"));
    if(nbytes_write == -1)
    {
        perror("Write Error");
        exit(EXIT_FAILURE);
    }
    
    close(fd);
    if(fd == -1)
    {
        perror("Close Error");
        exit(EXIT_FAILURE);
    }
    return 0;
}