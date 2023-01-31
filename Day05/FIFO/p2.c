#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
    int fd = 0;
    int nbytes_read = 0;
    unsigned char buff[128]; 
    
    fd = open("desdfifo", O_RDONLY);
    if(fd == -1)
    {
        perror("Open Error");
        exit(EXIT_FAILURE;)
    }

    nbytes_read = read(fd, buff, strlen(buff));
    if(nbytes_read == -1)
    {
        perror("Read Error");
        exit(EXIT_FAILURE);
    }
    
    printf("The buffer is: %s\n", buff);
    
    close(fd);
    if(fd == -1)
    {
        perror("Close Error");
        exit(EXIT_FAILURE);
    }
    return 0;
}