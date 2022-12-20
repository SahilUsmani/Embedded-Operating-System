#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>

      
int main(void)
{
    pid_t id;

    printf("Before using Fork\n\n");
    id = fork();
    printf("After using Fork\n");

    printf("PId:: %d    PPId:: %d   Ret:: %d\n", getpid(), getppid(), id);

    if(0==id)
    {
        printf("This is Child Process\n");
    }
    else
    {
        printf("This is Parent Process\n\n");
    }

    return 0;
}


 // pid_t fork(void);