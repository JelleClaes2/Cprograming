/*
  Fix it !
  --------
    Normaal groeit de pompoen exponentieel. Echter werkt het niet door kleine foutjes.
    HINT : Jack-o'-lantern fluistert je lokaal "scoOoOoOope"...
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main( void )
{
    int seeds = 0;
    int i=0;
    printf( "Geef het aantal pompoen zaadjes : " );
    (void)scanf( "%d", &seeds );

    uint64_t pumpkin = 0;
    uint64_t previousPumpkin = 0;
    for(i = 0; i < 10; i++ )
    {
        //int seeds;
        //uint64_t previousPumpkin;
        pumpkin = pow( seeds, i );
        if( pumpkin < previousPumpkin )
        {
            break;
        }
        previousPumpkin = pumpkin;
        printf( "%d ^ %d = %lu\n", seeds, i, pumpkin );
    }

    if( i != 10 )
    {
        printf( "Pumpkin BOOM !!! Overflow, de berekening %d ^ %d past niet meer in een 64 bit\n", seeds, i );
    }
    else
    {
        printf( "Pompoen groeide uit tot %0#18lx in het geheugen\n", pumpkin );
    }
    return 0;
}
