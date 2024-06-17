/* 

Schrijf een eigen versie van de opdracht cp waar twee argumenten op de opdrachtlijn
worden verwacht. Het eerste argument is het bronbestand en het tweede het
doelbestand. Wanneer de eerste parameter een directory is, wordt een foutboodschap
naar het scherm geschreven en stopt het programma met exit-status 1. Wanneer het
tweede argument een directory is, wordt opnieuw gestopt met een passende
foutboodschap en met exit-status 1.
Om na te gaan of een argument een directory is, kan je gebruikmaken van de
systeemaanroep stat. Om een programma te stoppen met exit-status 1 maak je best
gebruik van de bibliotheekfunctie exit die dan achter de schermen de systeemaanroep
_exit aanroept.

*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv) {
    // Controleren of er exact 2 argumenten zijn
    if (argc != 3) {
        fprintf(stderr, "Foutief aantal argumenten in: %s\n", argv[0]);
        exit(1);
    }

    // Controleren of bestand 1 een geldig bestand is
    int bestand1 = open(argv[1], O_RDONLY);
    if (bestand1 < 0) {
        perror(argv[1]);
        exit(1);
    }
    // Bestand inlezen
    char buffer[BUFSIZ];
    while (read(bestand1, buffer, sizeof(buffer)) > 0) {
        // Wegschrijven naar bestand 2
        int bestand2 = open(argv[2], O_WRONLY | O_CREAT);
        if (bestand2 < 0) {
            perror(argv[2]);
            exit(1);
        }
        write(bestand2, buffer, sizeof(buffer));
    }
}