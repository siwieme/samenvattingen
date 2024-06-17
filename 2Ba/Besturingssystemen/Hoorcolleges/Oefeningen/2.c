#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char buffer[8192];
    for (int i=1; i<=8192; i*=2) {
        double start = clock();
        int fd=open("largefile",O_RDONLY);
        if (fd<0) {
            perror(argv[0]);
            return 1;
        }
        int totaal=0;
        int n = read(fd,buffer,i);
        while (n>0) {
            totaal += n;
            n=read(fd,buffer,i);
        }
        if (n<0) {
            perror(argv[0]);
            exit(1);
        }
        if (close(fd)<0) {
            perror(argv[0]);
            exit(1);
        }
        double stop=clock();
        printf("BUFSIZ=%5d TIME=%5.2f\n",i,(stop-start)/CLOCKS_PER_SEC);
    }
}