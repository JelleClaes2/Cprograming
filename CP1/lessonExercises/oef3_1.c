/*
  Maak een programma dat het gemiddelde berekend van 5 getallen, tussen de 0 en 20, die door de gebruiker worden ingegeven. Het programma print "Geslaagd" indien het gemiddelde groter of gelijk aan 10 is, anders print het "Niet geslaagd".
*/

#include <stdio.h>

int main( void )
{
	float getal[5] = { 0, 0, 0, 0, 0 };
	for( int i = 0; i < 5; i++ )
	{
		printf( "Geef getal %d in: ", i );
		(void)scanf( "%f", &getal[i] );
	}

	float getal1 = getal[0];
	float getal2 = getal[1];
	float getal3 = getal[2];
	float getal4 = getal[3];
	float getal5 = getal[4];
	float gemiddelde = 0.0;

	//===============================================================
	// Bereken het gemiddelde en schrijf de conditie voor het if statement.
	/*_*/

  gemiddelde = (getal1+getal2+getal3+getal4+getal5)/5; 
	if( gemiddelde>=10 )
	{
		printf( "Geslaagd %.2f\n", gemiddelde );
	}
	else
	{
		printf( "Niet geslaagd %.2f\n", gemiddelde );
	}
	//===============================================================
	return 0;
}
