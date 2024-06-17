#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    // checken voor het aantal argumenten
    if (argc != 3) {
        fprintf(stderr, "Foutief aantal argumenten in: %s\n", argv[0]);
        return 1;
    }
    int fd_src = open(argv[1], O_RDONLY);
    int fd_dest = open(argv[2], O_WRONLY | O_CREAT);
    if (fd_src < 0 | fd_dest < 0) {
        perror(argv[0]);
        return 1;
    }
    char buffer[BUFSIZ];
    int n=read(fd_src,buffer,BUFSIZ);
    while (n>0) {
        write(fd_dest,buffer,n);
        n=read(fd_src,buffer,BUFSIZ);
    }
    if (n<0) {
        perror(argv[0]);
        return 1;
    }
    close(fd_src);
    close(fd_dest);
    return 0;
}