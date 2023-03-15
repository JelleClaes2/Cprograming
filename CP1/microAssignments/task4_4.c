/*
  Schrijf een programma dat de tafel van vermenigvuldiging van een in te lezen getal afdrukt, Van 1 tot 20 maal het getal. Zorg dat de getallen netjes onder elkaar staan .

  Voorbeeld:
  Invoer: 7
  Uitvoer:
  1 x 7 = 7
  2 x 7 = 14
  …
  20 x 7 = 140
*/
#include <stdio.h>

int main( void )
{
    int getal = 0;
    printf( "Invoer: " );
    (void)scanf( "%d", &getal );
    printf( "Uitvoer:\n" );
    for(int i=1; i<=20;i++){
        printf("%2d x %d = %3d\n",i,getal,i*getal);
    }



    return 0;
}
