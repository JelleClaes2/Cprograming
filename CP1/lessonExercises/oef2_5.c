/*
  Schrijf een programma dat de gebruik vraagt om het aantal seconden in te geven. Het programma berekent dan hoeveel dagen, uren, minuten en seconden dit is.
*/
#include <stdio.h>
#include <stdint.h>

int main( void )
{
	uint64_t aantalSeconden = 0;
	uint16_t dagen = 0;
	uint8_t uren = 0;
	uint8_t minuten = 0;
	uint8_t seconden = 0;
	uint16_t rest = 0;

	printf( "Geef het aantal seconden: " );
	(void)scanf( "%ld", &aantalSeconden );

	// Bereken het aantal dagen
	dagen = aantalSeconden/86400; // Bereken aantal dagen m.b.v. aantalSeconden
	rest = aantalSeconden%86400;  // Bereken de restwaarde dat niet in een dag past
	printf( "Dagen = %d\n", dagen );

	// Bereken het aantal uren
	uren = rest/3600; // Bereken aantal uren m.b.v. aantalSeconden die resteren
	rest = rest%3600; // Bereken de restwaarde dat niet in een uur past
	printf( "Uren = %d\n", uren );

	// Bereken het aantal minuten
	minuten = rest/60; // Bereken aantal minuten m.b.v. aantalSeconden die resteren
	printf( "Minuten = %d\n", minuten );

	// Bereken het aantal seconden
	seconden = rest%60; // Bereken de restwaarde dat niet in een minuut past
	printf( "Seconden = %d", seconden );

	return 0;
}
