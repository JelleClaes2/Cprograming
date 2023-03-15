/*
  Pi kan benaderd worden door de volgende formule:

  PI = 4x(1-(1/3)+(1/5)-(1/7)+(1/9)-(1/11)+(1/13)-...)

  Schrijf een programma dat deze benadering uitrekent met instelbare lengte for-lus/while counting-lus.
  Bereken ook het verschil tussen uw benadering en het getal PI uit de math.h library van c (M_PI) en print deze uit.
*/

#include <stdio.h>
#include <math.h>

int main( void )
{
	double pi = 0;
	int lengtePiBerekening = 0;
	printf( "Geef de lengte van de gewenste PI berekening: " );
	(void)scanf( "%d", &lengtePiBerekening );
  int  noemer=1;
  for(int i=0;i<lengtePiBerekening;i++){
    pi = i%2==0 ? pi+(4*(1/(float)noemer)) : pi-(4*(1/(float)noemer));
    noemer+=2;
  }
	// HINT : maak gebruik van conditional operator voor de +/-

	printf( "PI = %f\n", pi );
	printf( "M_PI - PI = %f\n", M_PI - pi );

	return 0;
}
