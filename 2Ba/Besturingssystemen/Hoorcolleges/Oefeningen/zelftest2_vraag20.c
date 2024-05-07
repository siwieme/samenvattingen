#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    if (argc <= 1) {
        fprintf(stderr, "Fout aantal argumenten\n");
        exit(1);
    }
    for (int i=1; i<argc; i++) {
        int fd=open(argv[i],O_RDONLY);
        if (fd<0) {
            perror(argv[i]);
            continue;
        }
        if (lseek(fd,-100,SEEK_END)<0) {
            perror(argv[i]);
            continue;
        }
        char buffer[BUFSIZ];
        int n=read(fd,buffer,100);
        if (n<0) {
            perror(argv[i]);
            continue;
        }
        int teller=0;
        for (int i=0; i<n; i++) {
            if (buffer[i]=='\n') {
                teller++;
            }
        }
        printf("%d\t%s\n",teller,argv[i]);
        close(fd);
    }
    return 0;
}