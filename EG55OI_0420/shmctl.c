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
	int rtn;
	int cmd;
	struct shmid_ds shmid_ds; 

	shmflg = 0;
	if ((shmid=shmget(key, size, shmflg)) < 0) {
	    perror("hiba\n");
	    exit(-1);
	}

	do{
		printf("\nParancs:\n");
		printf("0. status\n");
		printf("1. torles\n> ");
		scanf("%d",&cmd);
	} while (cmd < 0 || cmd > 1);

	switch (cmd)
	{
	    case 0:
		rtn = shmctl(shmid, IPC_STAT, &shmid_ds);
		printf("merete: %d\n",shmid_ds.shm_segsz);
		printf("Utolso processz pid-je: %d\n",shmid_ds.shm_lpid);
		break;
	    case 1:
		rtn = shmctl(shmid, IPC_RMID, NULL);
		printf("torolve. Visszateresi ertek: %d\n", rtn);
	}

	exit(0);

}