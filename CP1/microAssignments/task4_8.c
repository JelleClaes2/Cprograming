/*
    Optimaliseer door een normale while te gebruiken !
    --------------------------------------------------
  Een geheel getal n is deelbaar door 9 als de som van zijn digits deelbaar is door 9.
  Maak een programma dat dit test, maak de som van ieder digit en test of het geheel deelbaar is door 9.

  n = 621594
  som = 4+9+5+1+2+6=27 à 27 % 9 = 0 dus 621594 is deelbaar door 9.
  Hint:   gebruik de % om de digits af te zonderen à 621594 % 10 = 4
          gebruik de / om de digit te verwijderen à 621594 / 10 = 62159
*/
#include <stdio.h>

int main( void )
{
    int som = 0;
    int geheelGetal = 0;
    printf( "Geef een geheel getal in: " );
    (void)scanf( "%d", &geheelGetal );

    int tmpGetal = geheelGetal;
    som += tmpGetal % 10;
    tmpGetal /= 10;
    while( tmpGetal != 0 ){
        som += tmpGetal % 10;
        tmpGetal /= 10;
    }

    printf( "Het getal %d is %s door 9\n", geheelGetal, ( som % 9 == 0 ) ? "deelbaar" : "niet deelbaar" );

    return 0;
}
