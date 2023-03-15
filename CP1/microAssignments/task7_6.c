#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

int main( void )
{
    // Fix it !
    int seed;
    printf( "Geef een geheel getal als seed : \n" );
    (void)scanf( "%d", &seed );
    srand( seed );
    char username[] = "admin";
    char password[] = "1234567890abcdef";
    printf( "Your username = %s\n", username );
    for( int i = 0; i < 16; i++ )
    {
        uint8_t randomSymbol = rand() % ( 26 + 26 + 10 );
        if( randomSymbol < 26 )
        {
            password[i] = 'A' + randomSymbol;
        }
        else if( randomSymbol < (26 + 26) )
        {
            password[i] = 'a' + randomSymbol - 26;
        }
        else
        {
            password[i] = '0' + randomSymbol - 26 - 26;
        }
    }
    printf( "Your password = %.15s\n", password );
    return 0;
}
