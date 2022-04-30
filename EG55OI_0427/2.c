#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#define SEMKEY 11121L 

int main(){
	int semid, nsems, rtn;
	union semun {
        int              val;    
        struct semid_ds *buf;    
        unsigned short  *array;  
        struct seminfo  *__buf;  
    } arg;

   	nsems=1;
	semid = semget (SEMKEY, nsems, 00666 | IPC_CREAT);
	if (semid < 0 ) {
		perror("hiba\n");
		exit(0);
	} else printf("id: %d\n",semid);
	
	arg.val=1;
	rtn = semctl(semid, 0, SETVAL, arg);
	printf("visszateres: %d , szemafor erteke: %d\n", rtn, arg.val);
}