#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY 11121L

int main()
{
	int shmid;
	key_t key = SHMKEY;
	int size=512;
	int shmflg;	

	shmflg = 0;
	if ((shmid=shmget(key, size, shmflg)) < 0) {
	   printf("Szegmens keszitese...\n");
	   shmflg = 00666 | IPC_CREAT;
	   if ((shmid=shmget(key, size, shmflg)) < 0) {
	      perror("hiba\n");
	      exit(-1);
	   }
	} else printf("Van mar ilyen\n");

	printf("\nazonositoja %d: \n", shmid);

	exit(0);
}