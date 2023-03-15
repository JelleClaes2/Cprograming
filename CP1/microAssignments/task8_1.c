/*
  Fix it!
*/

#include <stdio.h>

int main( void )
{
    printf( "Hello President\n" );
    char input;
    while( 1 )
    {
        printf( "Wilt u de bom lanceren ? [j/n] " );
        (void)scanf( " %c", &input );
        switch( input )
        {
            case 'j':
            case 'J':
            case 'y':
            case 'Y':
                printf( "\n     _.-^^---....,,--       \n _--                  --_  \n<                        >)\n|                         | \n \\._                   _./  \n    ```--. . , ; .--'''       \n          | |   |             \n       .-=||  | "
                        "|=-.   \n       `-=#$%&%$#=-'   \n          | ;  :|     \n _____.,-#%&$@%#&#~,._____\n" );
                return 1;
            case 'n':
            case 'N':
            case 'c':
            case 'C':
                return 0;
        }
    }
    return -1;
}
