/*
  Laat de toetsen overeenkomen met de juiste keyboard mappings.
*/
#include <stdio.h>
#include <string.h>

enum orientation
{
    UP='w',
    DOWN='s',
    LEFT='a',
    RIGHT='d'
};

int main( void )
{
    int x = 5;
    int y = 5;

    char wasd_keys[100];
    printf( "Gebruik je wasd-toetsen om de beweging aan te geven en druk enter om uit te voeren : " );
    (void)scanf( "%s", wasd_keys );

    for( size_t i = 0; i < strlen( wasd_keys ); i++ )
    {
        switch( wasd_keys[i] )
        {
            case UP:
                y++;
                break;
            case DOWN:
                y--;
                break;
            case RIGHT:
                x++;
                break;
            case LEFT:
                x--;
                break;
        }
        printf( "position = (%d, %d)\n", x, y );
    }
    printf( "End position = (%d, %d)\n", x, y );

    return 0;
}
