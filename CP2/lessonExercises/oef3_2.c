#include <stdio.h>
#include <string.h>

void strtok_custom(char *str, const char *delim, char **result, int numberOfTokens) {
    int count = 0;
    char *token = strtok(str, delim);

    while (token != NULL && count < numberOfTokens - 1) {
        result[count] = token;
        count++;
        token = strtok(NULL, delim);
    }

    // Als er nog tokens zijn na het einde van de ragged array,
    // worden ze samengevoegd tot één string en opgeslagen als het laatste element.
    if (token != NULL) {
        result[count] = strcat(token, strtok(NULL, ""));
    }
}

int main() {
    char *result[5];
    char str[] = "Deze - string - dient - opgedeeld - te worden - op basis van - de meegegeven - delimiter.";

    strtok_custom(str, "-", result, 5);

    for (int i = 0; i < 5; i++) {
        printf("%s\n", result[i]);
    }

    return 0;
}
