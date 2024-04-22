#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct stat stat;

int main(int argc, char** argv) {
    for (int i=1; i<argc; i++) {
        int fd = open(argv[i], O_RDONLY);
        if (fd<0) {
            perror(argv[i]);
            continue;
        }
        struct stat s;
        if (fstat(fd, &s)<0) {
            perror(argv[i]);
            close(fd);
            continue;
        }
        if (S_ISREG(s.st_mode))
            printf("%d\t%s\n", s.st_size, argv[i]);
        close(fd);
    }
}