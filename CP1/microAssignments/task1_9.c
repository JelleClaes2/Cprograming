/*
    Zorg ervoor dat deze "standaard integer" types werken.
*/
#include <stdio.h>
#include <stdint.h>

int main( void )
{
    int64_t bryan = 064;
    int8_t wout = 062;
    uint16_t bart = 041;
    printf( "The answer to life the universe and everything = %c%c%c\n", (char)bryan, (char)wout, (char)bart );
    return 0;
}
