/*
  I have no f*cking clue.
*/
#include <stdio.h>
#include <stdlib.h>

void stateMachine( void );

int main( void )
{
    printf( "Welcome Stanley @ 427\n" );
    stateMachine();
    printf( "See you tomorrow Stanley !\n" );
    return 0;
}

enum state
{
    WACHT_OP_TOEVOER,
    LOOPBAND,
    BEWERKING,
    WACHT_OP_VRIJLOOP,
    FOUTMELDING,
    STOP
};

void stateMachine( void )
{
    enum state vorigeStatus = WACHT_OP_TOEVOER;
    enum state huidigeStatus = WACHT_OP_TOEVOER;
    enum state volgendeStatus = WACHT_OP_TOEVOER;
    while( huidigeStatus != STOP )
    {
        switch( huidigeStatus )
        {
            case WACHT_OP_TOEVOER:
                printf( "WACHT_OP_TOEVOER : druk op enter voor sensor te emuleren\n" );
                getchar();
                volgendeStatus = LOOPBAND;
                break;
            case LOOPBAND:
                printf( "LOOPBAND\n" );
                if( vorigeStatus == WACHT_OP_TOEVOER )
                {
                    volgendeStatus = BEWERKING;
                }
                else
                {
                    volgendeStatus = WACHT_OP_VRIJLOOP;
                }
                break;
            case BEWERKING:
                printf( "BEWERKING : voer steeds de gevraagde bewerking in\n" );
                char gevraagd = rand() % 26 + 'a';
                printf( "Press key %c : ", gevraagd );
                char uitgevoerd;
                (void)scanf( " %c", &uitgevoerd );
                if( uitgevoerd != gevraagd )
                {
                    volgendeStatus = FOUTMELDING;
                    break;
                }
                if( rand() % 42 == 7 )
                {
                    volgendeStatus = LOOPBAND;
                }
                if( rand() % 42 == 7 )
                {
                    volgendeStatus = STOP;
                }
                break;
            case WACHT_OP_VRIJLOOP:
                printf( "WACHT_OP_VRIJLOOP : sta op, strek je benen en ga even naar de meeting room.\n" );
                getchar();
                volgendeStatus = WACHT_OP_TOEVOER;
                break;
            case FOUTMELDING:
                printf( "THE END IS NEVER " );
                break;
            case STOP:
                printf( "Thank you for your work, " );
                break;
        }
        vorigeStatus = huidigeStatus;
        huidigeStatus = volgendeStatus;
    }
}
