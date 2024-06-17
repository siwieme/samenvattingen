
/*

De shell-opdracht "du -b arg1 arg2 ..." schrijft voor ieder bestand dat als parameter op de opdrachtlijn werd meegegeven, 
de grootte in bytes, gevolgd door een tab en gevolgd door de naam van het bestand naar het scherm.
Wanneer de parameter een directory is, wordt voor ieder bestand de directory (en diens eventuele subdirectory's) 
de grootte in bytes naar het scherm geschreven.

Om in C de inhoud (bestanden en/of directories) van een directory te bekomen, 
kan je gebruikmaken van de bibliotheekfunctie scandir. 
Als selector kies je NULL en als comparator gebruik je alphasort.

int scandir (const char *dirname, struct dirent ***namelist, int (*select)(const struct dirent *), int (*compar)(const struct dirent **, const struct dirent **));

Met de laatste twee parameters ingevuld wordt dit

int scandir (const char *dirname, struct dirent ***namelist, NULL, alphasort);

*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

typedef struct stat stat;

int main(int argc, char **argv) {
    // Check if the user has provided a directory or files
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }
    for (int i=0; i<argc; i++) {
        // Checking if the argument is a directory
        
    }
    return 0;
}