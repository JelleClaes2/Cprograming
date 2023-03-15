#include <stdio.h>
#include <string.h>

int main( void )
{
    // Fix it !
    char string[40];
    printf( "Bedenk een woord " );
    (void)scanf( "%s", string );
    printf( "Het omgekeerde woord is " );
    for( int i = strlen( string ) -1 ; i >= 0; i-- )
    {
        printf( "%c", string[i] );
    }
    printf( "\n" );
    return 0;
}
