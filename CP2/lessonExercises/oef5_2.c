#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Ok dus om dit te kunnen runnen maak een .txt file aan (die dat ik heb gebruikt is lyrics.txt met de lyrics van never gonna give you up in)
//Activeer het in shell met 'gcc -o reverse oef5_2.c'
//En run het dan met './reverse (.txt file) -o'
//de txt file gaat dan alles hebben omgedraaid <3 ur welcome, have a nice day

void reverseFile(const char *filename, int overwrite) {
  // Open het oorspronkelijke bestand
  FILE *originalFile = fopen(filename, "r");
  if (originalFile == NULL) {
    printf("Kon het bestand niet openen.\n");
    return;
  }

  // Bereken de grootte van het bestand
  fseek(originalFile, 0, SEEK_END);
  long fileSize = ftell(originalFile);
  rewind(originalFile);

  // Reserveer geheugen op de heap
  char *content = (char *)malloc((fileSize + 1) * sizeof(char));
  if (content == NULL) {
    printf("Kan geen geheugen reserveren.\n");
    fclose(originalFile);
    return;
  }

  // Lees de inhoud van het bestand
  fread(content, sizeof(char), fileSize, originalFile);
  fclose(originalFile);
  content[fileSize] =
      '\0'; // Voeg een null-terminator toe aan het einde van de inhoud

  // Open het nieuwe bestand (overschrijven indien nodig)
  FILE *newFile = fopen(filename, overwrite ? "w" : "a");
  if (newFile == NULL) {
    printf("Kon het bestand niet openen.\n");
    free(content);
    return;
  }

  // Plaats de inhoud achterstevoren in het bestand
  for (int i = fileSize - 1; i >= 0; i--) {
    fputc(content[i], newFile);
  }

  fclose(newFile);
  free(content);
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Geef een bestandsnaam als argument op.\n");
    return 1;
  }

  const char *filename = argv[1];
  int overwrite = 0;

  if (argc >= 3 && strcmp(argv[2], "-o") == 0) {
    overwrite = 1;
  }

  reverseFile(filename, overwrite);

  printf("Bestand is omgekeerd en opgeslagen.\n");

  return 0;
}
