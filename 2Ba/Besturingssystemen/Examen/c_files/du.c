#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct stat Stat;

int main(int argc, char **argv) {
    // Check if the user has provided a directory or files
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    for (int i=0; i<argc; i++) {
        // Checking if the argument is a directory
        Stat s;
        if (stat(argv[i], &s) == -1) {
            perror("stat");
            exit(1);
        }
        if (S_ISDIR(s.st_mode)) {
            printf("Directory: %s\n", argv[i]);
            // Open the directory
            int fd = open(argv[i], O_RDONLY);
            if (fd == -1) {
                perror("open");
                exit(1);
            }
            // Read the directory
            char buf[1024];
            int n;
            while ((n = read(fd, buf, sizeof(buf))) > 0) {
                write(1, buf, n);
            }
            if (n == -1) {
                perror("read");
                exit(1);
            }
        } else {
            printf("File: %s\n", argv[i]);
        }
    }
    return 0;
}
