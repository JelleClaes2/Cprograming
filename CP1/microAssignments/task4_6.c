/*
    FIX IT !
	--------
  Schrijf een programma dat de gebruiker vraagt om een geheel getal in te geven in het interval [-30,30]. Op basis van het ingegeven getal genereerd het getal onderstaande ouput:

  Geef een geheel getal in, in het interval [-30, 30]:
  -15
  getal=-15
  ...............***************|..............................   -15
  Geef een geheel getal in, in het interval [-30, 30]:
  9
  getal=9
  ..............................|*********.....................   9
  Geef een geheel getal in, in het interval [-30, 30]:
  0
  getal=0
  Indien het getal niet in het interval ligt moet het programma stoppen.
*/

#include <stdio.h>

int main( void )
{
    int geheelGetal = 0;

    while( 1 )
    {
        printf( "Geef een geheel getal in het interval [-30, 30]:\n" );
        (void)scanf( "%d", &geheelGetal );

        if( geheelGetal < -30 || geheelGetal > 30 ){
            break;
        }

        int startValue = ( geheelGetal < 0 ) ? geheelGetal - 1 : 0;
        int endValue = ( geheelGetal < 0 ) ? 0 : geheelGetal + 1;


        for(int i= -30; i <= 30;i++ ){
            if( i == 0 )
            {
                printf( "|" );
            }
            else if( i > startValue && i < endValue )
            {
                printf( "*" );
            }
            else
            {
                printf( "." );
            }
        }

        printf( "\n" );
    }


    return 0;
}
