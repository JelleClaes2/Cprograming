/*
  Zorg ervoor dat onderstaande code correct wordt uigevoerd.
*/

#include <stdio.h>
#include <stdint.h>
#include <math.h>

double spookyIndex( uint8_t ghosts, uint8_t vampires, uint8_t zombies );

int main( void )
{
    uint8_t geesten = 0;
    uint8_t vampieren = 0;
    uint8_t zombies = 0;

    printf( "Geef het aantal geesten, vampieren en zombies: " );
    (void)scanf( "%hhu %hhu %hhu", &geesten, &vampieren, &zombies );

    printf( "De spooky index van %d geesten, %d vampieren en %d zombies = %f\n", geesten, vampieren, zombies, spookyIndex( geesten, vampieren, zombies ) );

    return 0;
}

double spookyIndex( uint8_t ghosts, uint8_t vampires, uint8_t zombies )
{
    return pow( ghosts, vampires ) / (double) ( zombies == 0 ? 1 : zombies );
}
