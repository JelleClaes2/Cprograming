#include <stdio.h>
#include <stdint.h>

char dag[][10] = { "Maandag", "Dinsdag", "Woensdag", "Donderdag", "Vrijdag", "Zaterdag", "Zondag", "NoRepeat" };

// Fix it !
void printDagen( uint8_t data )
{
    for( uint8_t i = 0; i < 8; i++ )
    {
        if( data & ( 1 << i ) )
        {
            printf( "%s, ", dag[i] );
        }
    }
}

int main( void )
{
    uint8_t alarmSetting;
    printf( "Geef een hexadecimaal code voor alarm " );
    (void)scanf( "%hhx", &alarmSetting );
    printf( "Alarm herhaalt elke " );
    printDagen( alarmSetting );
    return 0;
}
