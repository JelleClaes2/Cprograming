/*
  Schrijf een programma dat een plaats vraagt aan de gebruiker en bepaald welke prijs overeenkomt met de ingegeven plaats.

   Plaats    Prijs
  ================
    1        1000
    2         250
    3         100
    4          50
    5          50
    > 5         0

  Maak hierbij gebruik van de conditionele operator (? :).
*/

#include <stdio.h>

int main( void )
{
	int plaats = 0;
	int prijs = 0;

	printf( "Geef een plaats in: " );
	(void)scanf( "%d", &plaats );

  if(plaats == 1){
    prijs = 1000;
  } else if (plaats ==2){
    prijs = 250;
  } else if (plaats == 3){
    prijs = 100;
  } else if (plaats == 4 || plaats ==5){
    prijs = 50;
  } else {
    prijs = 0;
  }
	printf( "De prijs voor plaats %d = %d\n", plaats, prijs );

	return 0;
}
