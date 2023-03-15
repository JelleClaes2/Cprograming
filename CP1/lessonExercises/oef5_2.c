/*
  Schrijf een programma dat de gebruiker om een karakter vraagt en als dit karakter een letter is dit karakter omzet naar lower case als het een upper case karakter is en vice versa. 

  Maak gebruik van de tolower() en toupper() functie.
  https://cplusplus.com/reference/cctype/tolower/
  https://cplusplus.com/reference/cctype/toupper/
*/

#include <stdio.h>
#include <ctype.h>
char convertCharacter(char character);
int main( void )
{
	char c1 = 0;
	char c2 = 0;

	printf( "Geef een karakter: " );
	(void)scanf( "%c", &c1 );

	c2 = convertCharacter( c1 );
	if( c2 > c1 )
	{
		printf( "Het karakter %c in lower case is %c.\n", c1, c2 );
	}
	else if( c2 < c1 )
	{
		printf( "Het karakter %c in upper case is %c.\n", c1, c2 );
	}
	else
	{
		printf( "Het karakter kan niet omgezet worden naar lower of upper case.\n" );
	}

	return 0;
}

char convertCharacter(char character){
  if(isupper(character) > 0){
    character=tolower(character);
  }
  else {
    character=toupper(character);
  }
  return character;
}
