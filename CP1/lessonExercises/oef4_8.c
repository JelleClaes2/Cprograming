/*
  Schrijf een programma dat de faculteit (!) berekent van een positief geheel getal ingegeven door de gebruiker. Maak gebruik van een FOR-Loop. Zorg er ook voor dat er eerst gecontroleerd wordt of n een getal > 1. Gebruik voor het resultaat van de
  berekening een long unsigned int type. Controleer telkens voor je het nieuwe resultaat berekent of je long unsigned int niet overflowed, maak hiervoor gebruik van de constante:

  ULONG_MAX uit <limits.h>.

  Faculteit is een wiskundige operatie:  6! = 6*5*4*3*2*1
  Of algemeen:                           n! = n*(n-1)*(n-2)*(n-3)*(n-4) …
*/
#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main( void )
{
	int geheelGetal = 0;
  uint64_t resultaat=1;

	// TODO : doe minstens 1 keer
  do{
	  printf( "Geef een geheel getal groter dan 1 in: " );
	  (void)scanf( "%d", &geheelGetal );
  }
  while(geheelGetal<=1);
	// TODO : en herhaal zolang geheelGetal <= 1
  for(int i=1;i<=geheelGetal;i++){
  //for(int i=geheelGetal;i>1;i--){
    if((uint64_t)i > ULONG_MAX / resultaat){
      printf( "Faculteit te groot om te berekenen!\n" );
      break;
    }
    else{
      resultaat *=i;
      
    }
  }
	// HINT : zolang ( ULONG_MAX / resultaat ) >= het getal dat je erbij wil vermenigvuldigen, zal de vermeningvuldiging niet overflowen. Bij ( (uint64_t)n > ULONG_MAX / resultaat ) --> printf( "Faculteit te groot om te berekenen!\n" ) en break

	printf( "De faculteit van %d = %lu\n", geheelGetal, resultaat );

	return 0;
}
