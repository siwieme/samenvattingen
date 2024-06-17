#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv){
	int fds[2];
	pipe(fds);
	int pid1=fork();
	if (pid1==0){
		//CHILD1 -> factor
		close(fds[0]);
		dup2(fds[1],1);
		strcpy(argv[0],"factor");
		if (execvp("factor",argv)<0){
			perror(argv[0]);
			exit(1);
		}
		return 0;
	}
	int pid2=fork();
	if (pid2==0){
		//CHILD2 -> sort -t : -k1,2r
		close(fds[1]);
		dup2(fds[0],0);
		if (execlp("sort","sort","-t",":","-k1,2r",(char*)0)<0){
			perror(argv[0]);
			exit(1);
		}
		return 0;
	}
	close(fds[0]);
	close(fds[1]);
	waitpid(pid1,NULL,0);
	waitpid(pid2,NULL,0);
	return 0;
}