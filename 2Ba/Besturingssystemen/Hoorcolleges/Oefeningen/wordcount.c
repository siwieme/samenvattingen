/* Schrijf een eigen programma word count dat het aantal woorden telt per lijn uit een bestand*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc!=2) {
        fprintf(stderr, "Foutief aantal argumenten in %s\n", argv[0]);
        return 1;
    }
    FILE* f = fopen(argv[1], "r");
    if (!f) {
        perror(argv[1]);
        return 1;
    }
    char line[1024];
    while (fgets(line, 1024, f)) {
        int count = 0;
        char* word = strtok(line, " \t\n");
        while (word) {
            count++;
            word = strtok(NULL, " \t\n");
        }
        printf("%d\n", count);
    }
    fclose(f);
    return 0;
}