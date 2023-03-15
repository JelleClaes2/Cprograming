#include <stdio.h>

int main( void )
{
    int getal = 0;
    int aantal_cijfers = 0;
    printf( "Geef een geheel getal in : " );
    (void)scanf( "%d", &getal );

    /* test of het getal niet groter is dan 10000 */
    if(getal>=10000){
        printf( "Het getal is te groot !" );
        return 0;
    }


        /*voer een reeks van testen uit, of gebruik een gelinkte conditionele operator voor :
            tussen de 0 en 10 --> 1 cijfer
            tussen de 10 en 100 --> 2 cijfers
            tussen de 100 en 1000 --> 3 cijfers
            tussen de 1000 en 10000 --> 4 cijfers
        */
    else if (0<=getal && getal<10){ aantal_cijfers = 1;}
    else if (10<=getal && getal<100){ aantal_cijfers = 2;}
    else if (100<=getal && getal<1000){ aantal_cijfers = 3;}
    else {aantal_cijfers = 4;}
    printf( "Het getal bestaat uit %d cijfers", aantal_cijfers );

    return 0;
}
