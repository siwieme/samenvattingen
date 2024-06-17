#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int argc, char** argv){
	srand(getpid());
	int fd=open("large_file",O_CREAT|O_WRONLY);
	if (fd<0){
		perror(argv[0]);
		return 1;
	}
	for(int i=0;i<10*1024*1024;i++){
		char ch=rand()%26+'a';
		int n=write(fd,&ch,1);
		if (n!=1){
			perror(argv[0]);
			return 1;
		}
	}
	if (close(fd)<0){
		perror(argv[0]);
		return 1;
	}
	return 0;
}