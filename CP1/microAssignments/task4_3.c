/*
  Schrijf een programma dat een aantal gehele getallen leest en daarvan het gemiddelde en het grootste getal bepaalt en afdrukt. Als het getal 999 wordt ingegeven wordt het einde aangegeven en moet het programma dus stoppen met het afdrukken van het
  gemiddelde en het grootste getal. Het getal 999 mag dus niet meegerekend worden
*/
#include <stdio.h>
#include <limits.h>

int main( void )
{
    printf( "Dit programma leest een reeks gehele getallen in.\n" );
    printf( "Van deze reeks wordt het gemiddelde en het grootste getal afgedrukt.\n" );
    printf( "Van zodra het getal 999 wordt ingegeven wordt het programma gestopt.\n" );
    printf( "--------------------------------------------------------------------\n" );
    int geheelGetal = 0;
    int maxGetal = INT_MAX;
    int counter = 0;
    float som = 0.0f;
    int grootsteGetal =0;

    while( 1 )
    {
        (void)scanf( "%d", &geheelGetal );
        if(counter<1){
            grootsteGetal = geheelGetal;
        }
        if(geheelGetal == 999){
            break;
        }
        else if (geheelGetal > maxGetal){
            break;
        }
        else {
            som += geheelGetal;
            counter++;
            if(geheelGetal>grootsteGetal){
                grootsteGetal = geheelGetal;
            }
        }
        /*
            Check of het ingegeven getal 999 is.
            Indien dit niet het geval is check dan of het ingegeven getal groter is dan het grootste getal.
        */

        // Voeg het geheel getal toe aan de som van getallen en verhoog de counter.

        // Print de resultaten
        printf( "Het gemiddelde is %f\n", som / counter );
        printf( "Het grootste getal is %d\n", grootsteGetal );
    }
    printf( "\n" );
    return 0;
}
