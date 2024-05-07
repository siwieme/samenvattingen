#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int fds[2];
    pipe(fds);
    int pid1=fork();
    if (pid1==0) {
        //CHILD1
        close(fds[0]); // Close read end
        dup2(fds[1],1); // Redirect stdout to write end
        
        if (execlp("tail","tail","-c","100",argv[1],(char*)0)<0) {
            perror(argv[0]);
            exit(1);
        }

        return 0;
    }
    int pid2=fork();
    if (pid2==0) {
        //CHILD2
        close(fds[1]); // Close write end
        dup2(fds[0],0);
        if (execlp("wc","wc","-l",(char*)0)<0) {
            perror(argv[0]);
            exit(1);
        }
        return 0;
    }
    waitpid(pid2,NULL,0);
    waitpid(pid1,NULL,0);
    return 0;
}