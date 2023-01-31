#include <stdio.h>
 #include <unistd.h>


int main(void)
{
    int fd_pipe1[2];
    int fd_pipe2[2];
    int id_fork;
    int ret_pipe1;
    int ret_pipe2;

    ret_pipe1 = pipe(fd_pipe1);
    if(-1 == ret_pipe1)
    {
        perror("PIPE 01 Error");
        exit(EXIT_FAILURE);
    }

    ret_pipe2 = pipe(fd_pipe2);
    if(-1 == ret_pipe2)
    {
        perror("PIPE 02 Error");
        exit(EXIT_FAILURE);
    }

    id_fork = fork()

    if(id_fork == -1)
    {

    }
    else
    {
        close()
    }
    

}
