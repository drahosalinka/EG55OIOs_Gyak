#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

void kezelo(int i) {
	if(i == SIGINT){
		printf("%d", SIG_DFL);
	}

	if(i == SIGQUIT){
		printf("Visszatérési érték: %d", SIGQUIT);
	}
}

void main() {
	signal(SIGINT, &kezelo);
	signal(SIGQUIT, &kezelo);
}
