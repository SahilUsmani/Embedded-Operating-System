
#include<stdio.h>
#include <sys/types.h>
#include <unistd.h>
      
int main(void)
{
    pid_t process_id;
    pid_t parent_pid;

    process_id = getpid();
    parent_pid = getppid();

    printf("Process Id:: %d\n", process_id);
    printf("Parent Process Id:: %d\n", parent_pid);

    return 0;
}

    /*
    pid_t getpid(void);
    pid_t getppid(void);
    */