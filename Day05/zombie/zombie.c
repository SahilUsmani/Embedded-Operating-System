
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc,const char *argv[])
{
    int fd = 0;
    pid_t id;
    pid_t ret_wait;
    // unsigned int ret_sleep;
    id = fork();
    if(id == 0)
    {
        // child process
        printf("Child process\n");
        printf("PId:: %d    PPId:: %d   Ret:: %d\n", getpid(), getppid(), id);
        printf("Zombie state started for 20 secs\n");
    }
    else
    {
        // parent process
        printf("Parent process\n");
        printf("PId:: %d    PPId:: %d   Ret:: %d\n", getpid(), getppid(), id);
        // ret_wait = wait(NULL);
        // if(ret_wait == -1)
        // {
        //     perror("Wait Error");
        // }
        sleep(20);
        printf("Zombie state finished.\n");
    }
    return 0;
}