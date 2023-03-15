#include <stdio.h>

int main( void )
{
    int getal = 0;
    printf( "Geef een geheel getal in : " );
    (void)scanf( "%d", &getal );
    printf( "Het getal is %s\n", getal % 2==0 ? "even" : "oneven" );
    return 0;
}
