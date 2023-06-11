#include <stdio.h>
#include <string.h>

char *strtok_custom(char *str, const char *delimiters) {
    static char *nextToken = NULL; // Statische variabele om de volgende token te behouden

    if (str != NULL) {
        nextToken = str; // Eerste oproep, stel de volgende token in op de start van de string
    } else if (nextToken == NULL) {
        return NULL; // Er is geen string en er is geen volgende token, geef NULL terug
    }

    // Zoek het begin van het volgende token
    char *startToken = nextToken;
    while (*startToken != '\0' && strchr(delimiters, *startToken) != NULL) {
        startToken++;
    }

    if (*startToken == '\0') {
        return NULL; // Geen volgend token gevonden, geef NULL terug
    }

    // Zoek het einde van het token
    char *endToken = startToken + 1;
    while (*endToken != '\0' && strchr(delimiters, *endToken) == NULL) {
        endToken++;
    }

    // Markeer het einde van het token met een null-karakter en update de volgende token
    if (*endToken != '\0') {
        *endToken = '\0';
        nextToken = endToken + 1;
    } else {
        nextToken = NULL; // Geen volgend token meer
    }

    return startToken;
}

int main() {
    char str[] = "Dit is een voorbeeldzin";
    const char delimiters[] = " ";
    char *token;

    // Eerste oproep om het eerste token te verkrijgen
    token = strtok_custom(str, delimiters);

    // Loop door alle tokens
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok_custom(NULL, delimiters);
    }

    return 0;
}

