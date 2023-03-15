#include <stdio.h>

int main( void )
{
    char character = 0;

    printf( "Geef een karakter in: " );
    (void)scanf( "%c", &character );

    if( (character >= 'A' && character <= 'Z') || (character >= 'a' && character <= 'z') ) // Hint : er missen de juiste haakjes
    {
        printf( "Het character %c is een letter", character );
    }
    else if ( character >= '0' && character <= '9' )
    {
        printf( "Het character %c is een cijfer", character );
    }
    else
    {
        printf( "Het character %c is geen letter noch cijfer", character );
    }

    return 0;
}
