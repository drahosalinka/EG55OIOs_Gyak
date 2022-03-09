#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void) {

	char bemenet[20];

	do{
		scanf("%s", bemenet);
		system(bemenet);

	}while(bemenet != CTRL-\);

}
