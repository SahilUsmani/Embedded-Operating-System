
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t id; // Return Datatype of fork() API is Process ID
    int fd[2];
    int ret_pipe = 0;
    unsigned char buff [128];
    ssize_t nbytes_read;
    ssize_t nbytes_write;
    //Return dataype of read() API is number of bytes successfully read
    
    ret_pipe = pipe(fd);
    if(ret_pipe = -1)
    {
        perror("Pipe Error");
        exit(EXIT_FAILURE);
    }
    id = fork();
    if (id == -1) {
        perror("fork error");
        exit(EXIT_FAILURE);
    }

    if(0==id)
    {
        //child
        close(fd[1]);   // closing write option for child process
        nbytes_read = read(fd[0], buff, 6);    // using read() API to read the data sent from parent
        printf("No of bytes successfully read:: %ld\n", nbytes_read);
        printf("Parent sent:: %s\n", buff);
        close(fd[0]);   // closing read option for child process
    }
    else
    {
        //parent
        close(fd[0]);
        nbytes_write = write(fd[1],"Hello\n", 6);
        printf("No of bytes successfully write:: %ld\n", nbytes_write);
        close(fd[1]);
    }
    
    return 0;
}