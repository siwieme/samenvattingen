/*

Schrijf een C-programma met als naam watchfile.c dat één argument, een bestand, op de
opdrachtlijn verwacht. Het programma loopt in een oneindige lus en schrijft telkens een
boodschap naar het scherm wanneer het bestand dat op de opdrachtlijn werd
meegegeven werd gewijzigd. Wanneer er geen argument werd opgegeven of het
argument is geen gewoon bestand wordt een foutboodschap getoond en wordt het
programma afgesloten met exit-status 1.


*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    // Controleren of er exact 1 argument is
    if (argc != 2) {
        fprintf(stderr, "Foutief aantal argumenten in: %s\n", argv[0]);
        exit(1);
    }

    struct stat fileInfo;
    time_t lastModifiedTime;

    // Controleren of bestand een geldig bestand is
    if (stat(argv[1], &fileInfo) != 0) {
        perror(argv[1]);
        return 1;
    }
    if (!S_ISREG(fileInfo.st_mode)) {
        fprintf(stderr, "Argument is geen gewoon bestand\n");
        return 1;
    }

    // Laatst gewijzigde tijd van het bestand
    lastModifiedTime = fileInfo.st_mtime;

    // Controleren of er wijzigingen optreden in het bestand
    while (1) {
        if (stat(argv[1], &fileInfo) != 0) {
            perror(argv[1]);
            return 1;
        }
        if (lastModifiedTime != fileInfo.st_mtime) {
            printf("Bestand %s is gewijzigd\n", argv[1]);
            lastModifiedTime = fileInfo.st_mtime;
        }
        sleep(1);
    }
    return 0;
}