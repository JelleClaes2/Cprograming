#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Result {
    char *index;
    char *name;
    char *url;
};

struct Spells {
    int count;
    struct Result *results;
};

// ;D

int main(void) {
    struct Spells spellList;

    FILE *filePointer = fopen("Spells.json", "r"); // Open file for reading
    if (filePointer == NULL) // Check if file is succesfully opened
    {
        perror("File opening failed"); // Print error
        return -1;                     // Stop program
    }
    char buffer[1024];    // Prepare a line buffer
    char *parsing = NULL; // Prepare helper pointer for strsep
    int counter = 0;      // Prepare helper counter for printing
    char check[6] = "count";
    while (!feof(filePointer)) // Keep reading file till EndOfFile is reached
    {
        if (fgets(buffer, sizeof(buffer), filePointer) ==
            NULL) // Read one line (stops on newline or eof), will return NULL on
            // eof or fail
        {
            fclose( filePointer );
            break; // Stop reading
        }

        parsing = buffer; // Point to buffer (reset)
        char *token = strsep(&parsing, "\"");
        while (token) // If token exists
        {

            token = strsep(&parsing, "\""); // Find next token
            //  printf("%s\n", buffer);
            if (token != NULL) {
                if (strcmp(token, "count") == 0) {
                    char *num = strtok(&parsing[2], ",");
                    spellList.count = atoi(num);
                    spellList.results = (struct Result*)calloc(spellList.count, sizeof(struct Result));
                    printf("count = %d\n", spellList.count);
                    printf("-------------------\n");
                } else if (strcmp(token, "index") == 0) {
                    char *index = strtok(&parsing[2], ",");

                    spellList.results[counter].index = (char*)calloc(strlen(index), sizeof(char));
                    strcpy(spellList.results[counter].index, index);
                    printf("index = %s\n", spellList.results[counter].index);
                } else if (strcmp(token, "name") == 0) {
                    char *name = strtok(&parsing[2], ",");

                    spellList.results[counter].name = (char*)calloc(strlen(name), sizeof(char));
                    strcpy(spellList.results[counter].name, name);
                    printf("name = %s\n", spellList.results[counter].name);
                } else if (strcmp(token, "url") == 0) {
                    char *url = strtok(&parsing[2], ",");

                    spellList.results[counter].url = (char*)calloc(strlen(url), sizeof(char));
                    strcpy(spellList.results[counter].url, url);
                    printf("url = %s\n", spellList.results[counter].url);
                    printf("-------------------\n");
                    counter ++;
                }
            }
        }
    }
    for(int i =0; i < spellList.count; i++ ){
        free(spellList.results[i].index);
        free(spellList.results[i].name);
        free(spellList.results[i].url);

    }
    free(spellList.results);
    return 0;
}