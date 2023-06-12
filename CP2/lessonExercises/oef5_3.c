#include <stdio.h>
#include <ctype.h>

// Alright there you go, another exercise done heheh.
//Ok dus om dit te laten werken moet je een .txt file hebben met of zonder hoofdletters en sommige dubbel spaties.
//In de shell typ 'gcc oef5_3.c -o oef5_3'
//en run het dan met ./oef5_3 (file.txt)'
//and look at the fruits of your labour.

void capitalizeSentences(FILE* file) {
    int capitalize = 1;  // Houdt bij of de volgende karakter een hoofdletter moet zijn

    while (!feof(file)) {
        char c = fgetc(file);

        if (capitalize && isalpha(c)) {
            c = toupper(c);
            capitalize = 0;
        }

        if (c == '.') {
            capitalize = 1;
        }

        printf("%c", c);
    }
}

void removeDoubleSpaces(FILE* file) {
    int prevChar = ' ';
    int currentChar;

    while ((currentChar = fgetc(file)) != EOF) {
        if (!(prevChar == ' ' && currentChar == ' ')) {
            printf("%c", currentChar);
        }
        prevChar = currentChar;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Geef een bestandsnaam als argument.\n");
        return 1;
    }

    FILE* file = fopen(argv[1], "r+");
    if (file == NULL) {
        printf("Kan het bestand niet openen.\n");
        return 1;
    }

    // Hoofdletters toevoegen aan de zinnen
    printf("Zinnen met hoofdletters:\n");
    capitalizeSentences(file);
    rewind(file);  // Terugkeren naar het begin van het bestand

    // Dubbele spaties verwijderen
    printf("\n\nZinnen zonder dubbele spaties:\n");
    removeDoubleSpaces(file);

    fclose(file);
    return 0;
}
