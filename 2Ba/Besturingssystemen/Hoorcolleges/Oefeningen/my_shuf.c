#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char **argv) {
    int fd=open("/dev/random",O_RDONLY);
    int a;
    read(fd,&a,4);
    prinf("%d\n",a);
    close(fd);
    return 0;
}