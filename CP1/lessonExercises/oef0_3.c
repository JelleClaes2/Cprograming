/*
  Schrijf een programma dat de onderstaande constanten afdrukt in de terminal:
  const double x = 123.451234512345;const double y = 123.451234512300;
  Bekijk de output goed, kan je dit verklaren?
*/
#include <stdio.h>

int main()
{
	const double x = 123.451234512345;
	const double y = 123.451234512300;

	printf( "x = %.12f\n", x);
	printf( "y = %.12f\n", y);

	return 0;
}
