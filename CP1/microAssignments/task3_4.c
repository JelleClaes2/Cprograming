#include <stdio.h>

int main( void )
{
    int getal = 0Xf00d; //<-- hexadecimal !
    int gok;
    printf( "Raad eens : " );
    (void)scanf( "%d", &gok );
    /* indien de gok te laag is */
    if (getal>gok){
        printf("Het getal is hoger !\n");
    }
        /* anders indien de gok te hoog is */
    else if(getal<gok){
        printf("Het getal is lager !\n");
    }
        /* anders */
    else{
        printf("Juist !\n");
    }
    return 0;
}
