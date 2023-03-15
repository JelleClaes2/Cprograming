/*
  Maak een programma dat bepaalt of een character ingegeven door de gebruiker een hoofdletter is of een kleine letter is.

  Voorbeeld
  =========
  Geef een karakter in: B
  Het character B is Upper Case

  Geef een karakter in: t
  Het character t is Lower Case

  Geef een karakter in: &
  Het character & is geen letter
*/

#include <stdio.h>
#include <ctype.h>

int main( void )
{
	char character = 0;

	printf( "Geef een karakter in: " );
	(void)scanf( "%c", &character );

  if(isalpha(character)==0){
    printf( "Het character %c is geen letter", character );
  }
  else if(isupper(character)>0){
    printf( "Het character %c is Upper Case", character );
  } else{
    printf( "Het character %c is Lower Case", character );
  } 
    


	return 0;
}
