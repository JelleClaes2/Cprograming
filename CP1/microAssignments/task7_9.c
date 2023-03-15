#include <stdio.h>
#include <string.h>

#define MAXWOORDEN 64
#define MAXLETTERS 64

int main( void )
{
    char zin[MAXWOORDEN][MAXLETTERS];
    printf( "Geef me een zin met kleine letters en eindig met \"over\" : " );
    int woord = 0;
    char hoofdletter=0;
    char kleineletter=0;
    do
    {
        (void)scanf( " %s", zin[woord++] );
    } while( strcmp( zin[woord - 1], "over" ) != 0 );

    //Zet voor elk woord in de zin de eerste letter om in een hoofdletter


    for( int i = 0; i < woord - 1; i++ )
    {
        kleineletter =zin[i][0];
        hoofdletter=kleineletter-32;
        zin[i][0]=hoofdletter;
        printf( "%s ", zin[i] );
    }
    printf( "\n" );
    return 0;
}
