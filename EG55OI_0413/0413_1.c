#include stdio.h
#include unistd.h
#include stdlib.h
#include sysfile.h
#include systypes.h
#include sysstat.h
#include fcntl.h
#include string.h

int main()
{
	int fd, ret;
	char buf[32];
	char buf2;

	buf[0]=0;


    ret=mkfifo(EG55OI, 00666);
	if (ret == -1) {
	    perror(Mkfifo error);
	    exit(-1);
	}

	ret=fork();
	if(ret==-1){
		perror(Fork error);
		exit(-1);
	}

	if(ret==0){
		printf(%d a gyerek PID-jen,getpid());
		fd=open(EG55OI,O_WRONLY);
		if (fd == -1) {
	    	perror(Open error);
	    	exit(-1);
		}

		strcpy(buf,Drahos Alinka);
		printf(%d Iras a FIFO-ba %sn,getpid(), buf);
		write(fd,buf,strlen(buf));
		close(fd);
		exit(0);
	}
	else{
		printf(%d a szulo PID-jen,getpid());
		fd=open(EG55OI,O_RDONLY);
		if (fd == -1) {
	    	perror(Open error);
	    	exit(-1);
		}
		printf(%d Olvasok... n%d ,getpid(), getpid());
		while (read(fd, &buf2, 1)  0) {
		 	printf(%c,buf2);
	   	}
	   	printf(n%d Kiolvasva. n,getpid());
		close(fd);

		unlink(EG55OI);
		exit(0);
	}

	
}