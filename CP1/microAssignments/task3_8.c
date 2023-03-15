#include <stdio.h>

int main( void )
{
    char character = 0;
    printf( "Geef een letter in: " );
    (void)scanf( "%c", &character );
    if( !(( character >= 'A' && character <= 'Z' ) || ( character >= 'a' && character <= 'z' ) ))
    {
        printf( "Dat is geen letter !\n" );
    }
    return 0;
}
