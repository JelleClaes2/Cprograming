#include <stdio.h>

#define SIZE 150

int main(){
    char naam[SIZE];
    printf("Geef voor en achternaam: ");
    fgets(naam,SIZE,stdin);
    printf("Ingegeven gebruikersnaam: %s",naam);
}