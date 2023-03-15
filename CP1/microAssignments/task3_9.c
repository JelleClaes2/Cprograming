#include <stdio.h>

int main( void )
{
    int getal = 0;
    printf( "Geef een geheel getal in : " );
    (void)scanf( "%d", &getal );
    /* herleid volgende condities tot 1 expressie m.b.v. logical operators */

    if ((0<getal && getal<100)||getal==1000) {
        printf("YES !\n");
    }

    return 0;
}
