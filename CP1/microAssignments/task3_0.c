#include <stdio.h>

int main( void )
{
    int getal = 0;
    printf( "Geef een geheel getal in : " );
    (void)scanf( "%d", &getal );
    if((getal % 2) == 0)
    {
        printf( "Het getal is even\n" );
    }// Indien getal is deelbaar door 2 (modulo met 2 moet dan 0 zijn)
    else{
        // Anders
        printf( "Het getal is oneven\n" );
    }
    return 0;
}
