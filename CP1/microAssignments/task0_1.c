/*
  Print de inhoud van de variabele text als tekst. Gebruik de correcte format specifier.
  Het is dus NIET de bedoeling dat je printf("Hello World\n") schrijft.
*/

#include <stdio.h>

int main( void )
{
    char text[] = "Hello World"; //Dit is een "String of characters"

    printf( "%s\n", text );
    return 0;
}