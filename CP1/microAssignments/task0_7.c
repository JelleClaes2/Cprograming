/*
  Print de inhoud van de variabele character af als een hexadecimaal getal. Zorg ervoor dat het getal vooraf gegaan wordt met 0x.
  Gebruik de correcte format specifier.
*/
#include <stdio.h>

int main( void )
{
    char character = 'p';

    printf( "%#x\n", character );
    return 0;
}