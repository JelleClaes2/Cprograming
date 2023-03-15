/*
  Fix it !
*/
#include <stdio.h>

enum orientation
{
    NORTH,
    EAST,
    SOUTH,
    WEST
};

int main( void )
{
    enum orientation ship[] = { NORTH, NORTH, SOUTH, SOUTH, WEST, EAST, SOUTH, SOUTH, EAST, EAST };
    int x = 5;
    int y = 5;

    for( size_t i = 0; i < sizeof( ship ) / sizeof( enum orientation ); i++ )
    {
        switch( ship[i] )
        {
            case NORTH:
                y++;
                break;
            case EAST:
                x++;
                break;
            case SOUTH:
                y--;
                break;
            case WEST:
                x--;
                break;
        }
        printf( "position = (%d, %d)\n", x, y );
    }
    printf( "End position = (%d, %d)\n", x, y );

    return 0;
}
