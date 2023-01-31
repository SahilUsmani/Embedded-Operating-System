#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


int main(int argc, const char* argv[])
{
    int fd_source = 0;
    int fd_destination = 0;
    char buff[128];
    ssize_t nbytes_read = 0;
    ssize_t nbytes_write = 0;
    int ret_cls_src = 0;
    int ret_cls_dst = 0;

    if (argc==1) { /* Error Handling if there is only one argument passed */
        fprintf(stderr, "Usage: %s <source file> <destination file>\n ", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (argc==2) {  /* Error Handling if there is only two argument passed */
         fprintf(stderr, "Usage: %s %s <destination file>\n ", argv[0], argv[1]);
         exit(EXIT_FAILURE);
    }

    /* 
    - Opening source file in read only flag.
    - open system call returns a file descriptor, here it is named fd_source.
    */
    fd_source = open(argv[1], O_RDONLY);
    if (fd_source == -1) { /* Error Handling for opening of source file */
        printf("Error No. :: %d\n", errno);
        perror("Source File Open Error");
        exit(EXIT_FAILURE);
    }
    
    /* 
    - Using read system call tor read the contents of source file into a buffer named buff.
    - read system call returns no of bytes successfully read 
    */
    nbytes_read = read(fd_source, buff, 128);
    if (nbytes_read == -1) { /* Error Handling for reading of source file */
        perror("Source File Read Error");
        exit(EXIT_FAILURE);
    }

    /* 
    - Opening destination file in write only flag and create if pathname doesn't exist flag.
    - After create giving it permission mode for user read & write, group read & write and others read only.
    - open system call returns a file descriptor, here it is named fd_destination 
    */
    fd_destination = open(argv[2], O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_destination == -1) { /* Error Handling for opening of destination file */
        perror("Destination File Open Error");
        exit(EXIT_FAILURE);
    }

    /* 
    - Using write system call tor writing the contents of source file which is in a buffer named buff
      into the destination file.     
    - write system call returns no of bytes successfully written.
    */
    nbytes_write = write(fd_destination, buff, strlen(buff));
    if (nbytes_write == -1) { /* Error Handling for wrinting of destination file */
        perror("Destination File Write Error");
        exit(EXIT_FAILURE);
    }

    /*
    - Using close system call close the source file.
    - It returns 0 in success and -1 if there's an error.
    */
    ret_cls_src = close(fd_source);
    if (-1 == ret_cls_src) { /* Error Handling for closing of source file */
        perror("Source File Close Error");
        exit(EXIT_FAILURE);
    }

    /*
    - Using close system call close the destination file.
    - It returns 0 in success and -1 if there's an error.
    */
    ret_cls_dst = close(fd_destination);
    if (-1 == ret_cls_dst) { /* Error Handling for closing of destination file */
        perror("Destination File Close Error");
        exit(EXIT_FAILURE);
    }
   
    return 0;
}