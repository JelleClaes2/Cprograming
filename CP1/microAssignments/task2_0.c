/*
 Zorg ervoor dat het getal 41 en 42 wordt geprint door de decrement operator (--) op de juiste positie te plaatsen.
*/
#include <stdio.h>

int main( void )
{
    int getal = 42;
    int tweedeGetal = getal--; // Voeg de decrement operator toe bij de variabele getal.
    printf( "Getal = %d & tweedeGetal = %d\n", getal, tweedeGetal );
    return 0;
}
