#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main( void )
{
    // Fix it !
    int seed;
    printf( "Geef een geheel getal als seed : \n" );
    (void)scanf( "%d", &seed );
    srand( seed );
    char password[8] = { 0 };
    for( int i = 0; i < 7; i++ )
    {
        password[i] = 'a' + rand() % 26;
    }
    char guess[8];
    printf( "Gok het wachtwoord : " );
    (void)scanf( "%s", guess );
    while( strcmp( password, guess ) )
    {
        printf( "Your symbol is %d wrong\n", strcmp( password, guess ) );
        (void)scanf( "%s", guess );
    }
    printf( "Your password = %s\n", password );
    return 0;
}
