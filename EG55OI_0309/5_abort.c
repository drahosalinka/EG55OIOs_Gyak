#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

	pid_t pid;
	int status;	

	if((pid = fork()) < 0) perror("fork hiba");
		else if(pid == 0)
			abort();

	if(wait(&status) != pid) perror("wait hiba");
	if(WIFSIGNALED(status))
		printf("Abnormális befejeződés, a szignál sorszáma = %d\n", WTERMSIG(status));

	return 0;
}
