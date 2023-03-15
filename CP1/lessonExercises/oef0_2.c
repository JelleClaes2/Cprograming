//  Maak een programma dat de variabelen getal, character en kommagetal print
#include <stdio.h>

int main()
{
	int getal = 69;
	char character = 'a';
	double kommagetal = 9.99999;

	printf( "getal = %d\t character = %c\t\t kommagetal = %.5f\n",               getal, character,kommagetal );

	return 0;
}