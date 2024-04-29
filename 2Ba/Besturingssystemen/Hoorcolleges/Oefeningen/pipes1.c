#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char** argv){
	int fd_P_C1[2];
	int fd_P_C2[2];
	int fd_C1_C2[2];
	pipe(fd_P_C1);
	pipe(fd_P_C2);
	pipe(fd_C1_C2);
	int pid1=fork();
	if (pid1 ==0){
		//CHILD1
		close(fd_P_C1[1]);
		close(fd_P_C2[0]);
		close(fd_P_C2[1]);
		close(fd_C1_C2[0]);
		int g1;
		read(fd_P_C1[0],&g1,sizeof(int));
		printf("%d has been received in Child1!\n",g1);
		close(fd_P_C1[0]);
		g1*=2;
		write(fd_C1_C2[1],&g1,sizeof(int));
		close(fd_C1_C2[1]);
		return 0;
	}
	int pid2=fork();
	if (pid2==0){
		//CHILD2
		close(fd_P_C1[0]);
		close(fd_P_C1[1]);
		close(fd_P_C2[1]);
		close(fd_C1_C2[1]);
		int g2,g3;
		read(fd_P_C2[0],&g2,sizeof(int));
		close(fd_P_C2[0]);
		printf("%d has been received by Child2!\n",g2);
		read(fd_C1_C2[0],&g3,sizeof(int));
		close(fd_C1_C2[0]);
		printf("The result from child2 is %d!\n",g2+g3);
		return 0;
	}
	close(fd_C1_C2[0]);
	close(fd_C1_C2[1]);
	close(fd_P_C1[0]);
	close(fd_P_C2[0]);
	int getal_C1=5;
	int getal_C2=7;
	write(fd_P_C1[1],&getal_C1,sizeof(int));
	write(fd_P_C2[1],&getal_C2,sizeof(int));
	close(fd_P_C1[1]);
	close(fd_P_C2[1]);
	waitpid(pid1,NULL,0);
	waitpid(pid2,NULL,0);
	return 0;
}