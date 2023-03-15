/*
    Loop zo vaak als de gebruiker opgeeft.
*/
#include <stdio.h>
#include <stdint.h>

int main( void )
{
    uint8_t getal = 0;

    printf( "Geef een geheel getal : " );
    (void)scanf( "%hhu", &getal );

    printf( "me " );
    // Loop dit!
    for(int i=getal;i>0;i--)
    {
        printf( ">" );
    }
    printf( " you\n" );

    return 0;
}
