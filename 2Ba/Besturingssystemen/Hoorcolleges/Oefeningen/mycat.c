#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char buffer[BUFSIZ];
	if (argc==1){
		int n=read(0,buffer,BUFSIZ);
		while (n!=0){
			write(1,buffer,n);
			n=read(0,buffer,BUFSIZ);
		}
		if (n<0){
			perror(argv[0]);
			exit(1);
		}
	}
	else {
		for (int i=1;i<argc;i++){
			if (strcmp(argv[i],"-")==0){
				int n=read(0,buffer,BUFSIZ);
				while(n>0){
					write(1,buffer,n);
					n=read(0,buffer,BUFSIZ);
				}
				if (n<0){
					perror(argv[0]);
					continue;
				}
			} else {
				int fd=open(argv[i],O_RDONLY);
				if  (fd<0){
					perror(argv[i]);
					close(fd);
					continue;
				}
				int n=read(fd,buffer,BUFSIZ);
				while (n>0){
					write(1,buffer,n);
					n=read(fd,buffer,BUFSIZ);
				}
				if (n<0){
					perror(argv[0]);
					continue;
				}
				close(fd);
			}
		}
	}
	return 0;
}

