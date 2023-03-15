/*
  Maak gebruik van de juiste arthimetic operators om te berekenen hoe vaak 5 in een gegeven getal past en hoeveel de restwaarde is.
*/
#include <stdio.h>

int main( void )
{
    int getal = 0;
    int aantalKeer = 0;
    int restWaarde = 0;

    printf( "Geef 1 geheel getal in: " );
    (void)scanf( "%d", &getal );

    aantalKeer = getal / 5;
    restWaarde = getal %5;

    printf( "%d / 5 = %d.%d\n", getal, aantalKeer, restWaarde * 2 );

    return 0;
}
