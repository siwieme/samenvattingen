# Deel II - Compileren in de Shell

* Tekstverwerker openen:
    * `nano <bestand>`: opent een bestand in de nano-tekstverwerker
    * `nano`: opent een nieuw bestand in de nano-tekstverwerker
    * `vscode <bestand>`: opent een bestand in Visual Studio Code

* Bestand opslaan:
    * `Ctrl + O`: opslaan
    * `Enter`: bevestigen
    * `Ctrl + X`: afsluiten

* Bestand compileren:
    * `gcc <bestand>.c -o <bestand>`: compileert een C-bestand
    * `./<bestand>`: voert een gecompileerd bestand uit

* Wat is dynamische linking?
    * Automatisch laden van bibliotheken
    * Bibliotheken worden pas geladen wanneer ze nodig zijn
    * Bibliotheken worden gedeeld tussen programma's
    * Kleinere bestanden
* Wat is statische linking?
    * Bibliotheken worden in het programma geplaatst
    * Bibliotheken worden niet gedeeld tussen programma's
    * Bibliotheken worden altijd geladen
    * Grotere bestanden

* `nm <bestand>`: toont de symbolen in een bestand
* `ldd <bestand>`: toont de dynamische bibliotheken die een bestand gebruikt