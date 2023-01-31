/* Implementation of Message Queue Inter Process Communication
    This is program for Receiver Process */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

#define BUFF_SIZE 64
char buff[BUFF_SIZE];

/* 
    typedef struct msgq_attributes {
        int mq_flags;
        int mq_maxmsg;
        int mq_msgsize;
        int mq_curmsgs;
    } mq_attr;
 
    we don't need to declare this structure for attributes because 
    it is already declared in the header file 
*/

struct mq_attr desd_mq_attr;

int main()
{
    mqd_t desd_mq_desc; // message queue descriptor
    int mq_recv_er, mq_close_er;
    desd_mq_attr.mq_flags = 0;
    desd_mq_attr.mq_maxmsg = 4;
    desd_mq_attr.mq_msgsize = 64;
    desd_mq_attr.mq_curmsgs = 0;

    /* 
        If there's a message queue named desd_mq in the current directory then open it 
        otherwise if it's not there create it and then open it on read and write mode
        with user read and write permission mode.
        last argument is for attributes.

        mqd_t mq_open(const char* name, int oflag, mode_t mode, struct mq_attr *attr);

        Return value:-
        On success it returns an message queue descriptor for use by other message queue functons.
        On error it returns -1, with errno set.
    */
    desd_mq_desc = mq_open("/desd_mq", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &desd_mq_attr);
    if (desd_mq_desc == -1) {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }

    /*  */
    mq_recv_er = mq_receive(desd_mq_desc, buff, 64, 0);
    if (mq_recv_er == -1) {
          perror("mq_receive");
          exit(EXIT_FAILURE);
    }

    printf("Received Message :: %s\n", buff);

    mq_close_er = mq_close(desd_mq_desc);
    /* mq_close returns 0 on success and -1 when error is there set with errno */
    if (mq_close_er == -1) {
        perror("mq_close");
        exit(EXIT_FAILURE);
    }

    return 0;
}