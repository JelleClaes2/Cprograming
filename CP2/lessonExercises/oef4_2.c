#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token {
    char *word;
    struct token *next;
};

void strtok_custom(char *str, const char *delim, struct token **result) {
    struct token *current = NULL;
    char *token = strtok(str, delim);

    while (token != NULL) {
        struct token *new_token = malloc(sizeof(struct token));
        new_token->word = strdup(token);
        new_token->next = NULL;

        if (*result == NULL) {
            *result = new_token;
            current = *result;
        } else {
            current->next = new_token;
            current = current->next;
        }

        token = strtok(NULL, delim);
    }
}

void replace_word(struct token *result, const char *word, const char *new_word) {
    struct token *current = result;
    while (current != NULL) {
        if (strcmp(current->word, word) == 0) {
            free(current->word);
            current->word = strdup(new_word);
        }
        current = current->next;
    }
}

void free_tokens(struct token *result) {
    struct token *current = result;
    while (current != NULL) {
        struct token *temp = current;
        current = current->next;
        free(temp->word);
        free(temp);
    }
}

int main() {
    struct token *result = NULL;
    char str[] = "Deze - string - dient - opgedeeld - te worden - op basis van - de meegegeven - delimiter.";

    strtok_custom(str, "-", &result);

    // Afdrukken van de tokens
    struct token *current = result;
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }

    // Vervangen van een woord
    replace_word(result, "opgedeeld", "gesplitst");

    printf("\nTokens na vervanging:\n");
    current = result;
    while (current != NULL) {
        printf("%s\n", current->word);
        current = current->next;
    }

    // Het vrijgeven van geheugen
    free_tokens(result);

    return 0;
}
