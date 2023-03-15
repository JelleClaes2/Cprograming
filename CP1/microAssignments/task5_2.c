/*
  Declareer de functie candy(int numberOfCandy) waarbij de functie parameter aangeeft hoe vaak het woord Candy geprint wordt.

  Voorbeeld
  =========
  Hoeveel keer moet candy geprint worden? 4
  Candy
  Candy
  Candy
  Candy
*/

#include <stdio.h>

void candy( int numberOfCandy );

int main( void )
{
    printf( "Hoeveel keer moet candy geprint worden? " );

    int aantalKeerPrinten = 0;
    (void)scanf( "%d", &aantalKeerPrinten );

    candy( aantalKeerPrinten );

    return 0;
}

void candy(int numberOfCandy)
{
    for(int i=numberOfCandy;i>0;i--){
        printf("Candy\n");
    }
}
