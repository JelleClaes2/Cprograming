#include <stdio.h>

int main( void )
{
    int i = 0;
    int j = 0;
    int direction = 0;
    printf("Geef een geheel getal in: ");
    (void) scanf("%d", &i);
    printf( "Proficiat om vol te houden tot hier.\nDeze is gratis, want de testen lukken altijd :-)\nProbeer eens in de code te vinden waar je\n de snelheid van de muis kan instellen.\n\n\n" );
    while( i )
    {
        for( i = 0 ; i < 2048 ; i++ )
        {
            printf( "\r" );
        }
        printf( "|" );
        for( i = 0 ; i < j ; i++ )
        {
            printf( " " );
        }
        if( direction == 0 )
        {
            printf( "__oO" );
            j++;
            if( j > 32 )
            {
                direction = 1;
            }
        }
        else
        {
            printf( "Oo__" );
            j--;
            if( j <= 0 )
            {
                direction = 0;
            }
        }
        for(  ; i <= 32; i++ )
        {
            printf( " " );
        }
        printf( "|" );
    }
    return 0;
}
