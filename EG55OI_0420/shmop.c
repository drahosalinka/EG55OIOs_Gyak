#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHMKEY 11121L

int main()
{
	int shmid;
	key_t key = SHMKEY;
	int size=512;
	int shmflg;
	struct vmi {
		int  hossz;
		char szoveg[size-sizeof(int)];
	} *segm;
	

	shmflg = 0;	

	if ((shmid=shmget(key, size, shmflg)) < 0) {
	    perror("hiba\n");
	    exit(-1);
	}


	shmflg = 00666 | SHM_RND;
	segm = (struct vmi *)shmat(shmid, NULL, shmflg);

	if (segm == (void *)-1) {
		perror("hiba\n");
		exit(-1);
	}

	if (strlen(segm->szoveg) > 0) 
		printf("Regi szoveg: %s\n",segm->szoveg);
 
	printf("Uj: \n");
	scanf("%[^\n]", segm->szoveg);
	printf("uj szoveg: %s\n",segm->szoveg);
	segm->hossz=strlen(segm->szoveg);
	
	shmdt(segm);

	exit(0);
}