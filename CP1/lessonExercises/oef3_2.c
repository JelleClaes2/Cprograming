/*
  Maak een programma dat de volgende geluidsassociatie weergeeft op basis van de input van de gebruiker.

  Loudness in Decibels (dB)    Perception
  ==========================================
  50 or lower                  Quiet
  51-70                        Intrusive
  71-90                        Annoying
  91-110                       Very annoying
  above 110                    Uncomfortable
  ==========================================

  Je stelt de volgende vraag aan de gebruiker:
  Geef het geluidsniveau (dB) in:

  Het antwoord van het programma moet 1 van de 5 percepties zijn op basis van de classificatie in de linkse kolom.
*/

#include <stdio.h>

int main( void )
{
	int geluidsniveau = 0;

	printf( "Geef het geluidsniveau (dB) in: " );
	(void)scanf( "%d", &geluidsniveau );

	if(geluidsniveau<=50)
	{
		printf( "Quiet" );
	}
	else if(geluidsniveau>50 && geluidsniveau<=70)
	{
		printf( "Intrusive" );
	}
	else if(geluidsniveau>70 && geluidsniveau<=90)
	{
		printf( "Annoying" );
	}
	else if(geluidsniveau>90 && geluidsniveau<=110)
	{
		printf( "Very annoying" );
	}
	else
	{
		printf( "Uncomfortable" );
	}

	return 0;
}
