#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
    char platform[100];
    char genre[100];
    int year;
    float sales;
} Game;

#define MAX_GAMES 1000

int main() {
    FILE *file = fopen("Videogames is Europe.csv", "r");
    if (file == NULL) {
        printf("Fout bij het openen van het CSV-bestand.\n");
        return 1;
    }

    Game *games = malloc(MAX_GAMES * sizeof(Game));
    if (games == NULL) {
        printf("Fout bij het toewijzen van geheugen.\n");
        fclose(file);
        return 1;
    }

    char line[1024];
    int gameCount = 0;

    // Overslaan van de koptekstregel
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) != NULL) {
        // Verwijderen van de newline-karakter aan het einde van de regel
        line[strcspn(line, "\n")] = '\0';

        // Tokenizen van de CSV-lijn
        char *token;
        token = strtok(line, ",");
        strcpy(games[gameCount].name, token);

        token = strtok(NULL, ",");
        strcpy(games[gameCount].platform, token);

        token = strtok(NULL, ",");
        strcpy(games[gameCount].genre, token);

        token = strtok(NULL, ",");
        games[gameCount].year = atoi(token);

        token = strtok(NULL, ",");
        games[gameCount].sales = atof(token);

        gameCount++;

        if (gameCount >= MAX_GAMES) {
            printf("Limiet voor het aantal games bereikt.\n");
            break;
        }
    }

    fclose(file);

    // Gebruik van de geparste gegevens
    for (int i = 0; i < gameCount; i++) {
        printf("Game %d:\n", i + 1);
        printf("  Naam: %s\n", games[i].name);
        printf("  Platform: %s\n", games[i].platform);
        printf("  Genre: %s\n", games[i].genre);
        printf("  Jaar: %d\n", games[i].year);
        printf("  Verkoopcijfers: %.2f\n", games[i].sales);
        printf("\n");
    }

    // Geheugen vrijgeven
    free(games);

    return 0;
}
