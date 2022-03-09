#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {

	pid_t pid;
	int status;

	if((pid = fork()) < 0) perror("fork hiba");
		else if(pid == 0)
			status /= 0;

	if(wait(&status) != pid) perror("wait hiba");

	return 0;
}
