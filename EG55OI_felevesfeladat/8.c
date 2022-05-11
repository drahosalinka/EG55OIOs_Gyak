#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <time.h>

void findMax(int array[], int start, int end, int pipefd);

int main() {
	int array[1000];
	srand(time(0));
	int max = 0;
	int pipefd[2];
	int solutions[10];
	pid_t pid[10];
	
	if(pipe(pipefd) < 0) {
		perror("pipe");
		exit(-1);
	}

	int i;
	for(i = 0; i < 999; i++) {
        	array[i] = rand();
	}
	for(i=0;i<10;i++) {
        	if(pid[i] = fork() == 0) {
			findMax(array, i*100, (i+1)*100 -1, pipefd[1]);
			exit(-1);
		}
	}
	sleep(10);
	for(i=0;i<10;i++) {
		read(pipefd[0], &solutions[i], sizeof(int));
		printf("%d\n", solutions[i]);
	}
	if(fork() == 0) {
   		findMax(solutions, 0, 9, pipefd[1]);
        	exit(-1);
     	}
	printf("\n");
	sleep(10);
	read(pipefd[0], &max, sizeof(int));
	close(pipefd[0]);
	close(pipefd[1]);
     	printf("%d\n", max);
     	return 0;
}

void findMax(int array[], int start, int end, int pipefd) {
	int max = 0;
	int j;
	for(j = start; j < end; j++) {
        	if(array[j] > max) {
			max = array[j];
		}
	}
	write(pipefd, &max, sizeof(int));
}