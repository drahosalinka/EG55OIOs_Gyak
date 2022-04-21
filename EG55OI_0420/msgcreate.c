#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define MSGKEY 654321L

struct msgbuf1 {
	long mtype;
	char mtext[512];
} sendbuf;

int main()
{
	int msgid;		
	key_t key = MSGKEY;	
	int msgflg= 11121 | IPC_CREAT;		
	int ret, msgsz;

	
	msgid = msgget(key, msgflg);
 	if (msgid == -1) {
                perror("hiba");
                exit(-1);
        }
	printf("id letrejott: %d, %x\n", msgid,msgid);

	sendbuf.mtype = 1;  
 	strcpy(sendbuf.mtext,"Egyik uzenet");
	msgsz = strlen(sendbuf.mtext) + 1;
    ret = msgsnd(msgid, &sendbuf, msgsz, 0);

	printf("1. visszaadott: %d\n", ret);
	printf("kikuldott uzenet: %s\n", sendbuf.mtext);

	strcpy(sendbuf.mtext,"Masik uzenet");
	msgsz = strlen(sendbuf.mtext) + 1;
    ret = msgsnd(msgid, &sendbuf, msgsz, 0);
	printf("2. visszaadott: %d\n", ret);
	printf("kikuldott uzenet: %s\n", sendbuf.mtext);

	exit(0);
}