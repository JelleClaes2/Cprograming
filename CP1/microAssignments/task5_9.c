/*
  Fix it !
  --------
    Er was een feestje tussen de skeletten en ze hebben alle ronde haakjes gestolen op regel 20 ! Zet je ze terug ?
*/

#include <stdio.h>
#include <stdint.h>

double JackSkellington( unsigned long jack, float skellington );
uint64_t Skeletor( uint32_t tree, uint16_t two, uint8_t one );
float OneEyedWilly( uint8_t one, float eyed, long willy );
unsigned TheBigLeBoneSki( int the, short big, int le, long bone, char ski );
void klikKlak( void );

int main( void )
{
    double skeletons = 0;
    // -------- The skeletons stole the round brakets ! Can you put them back ?
    skeletons = JackSkellington( Skeletor( TheBigLeBoneSki( 1, 2, 3, 4, 5), 6, 7), OneEyedWilly( 8, OneEyedWilly( 9, OneEyedWilly( 10, 11, Skeletor( TheBigLeBoneSki( 12, 13, 14, 15, 16), 17, 18)), Skeletor( TheBigLeBoneSki( 19, 20, 21, 22, 23), 24, 25)), Skeletor( TheBigLeBoneSki( 26, 27, 28, 29, 30), 31, 32)));
    // -------- End of skeleton theft !
    printf( "Spooky, Scary Skeletons %.5lf\n", skeletons );
    klikKlak();
    return 0;
}

double JackSkellington( unsigned long jack, float skellington )
{
    return (double)( jack + skellington ) / jack;
}

uint64_t Skeletor( uint32_t tree, uint16_t two, uint8_t one )
{
    return (uint64_t)( tree << (one & 0xF) ) | two;
}

float OneEyedWilly( uint8_t one, float eyed, long willy )
{
    return eyed + willy * (float)willy / one;
}

unsigned TheBigLeBoneSki( int the, short big, int le, long bone, char ski )
{
    return the + ( ( bone / ski ) * ( le + big ) );
}

void klikKlak( void )
{
    printf( "                                          .-. _)/\n                                         (0,0) .\\\n                                          (u)   ()\n     .-.                           _\\)  .-=\"=-.//\n    (o,o)                        "
            "    \\,//==\\===\n     (e)                              ()  =====            .-.\n   .-=\"=-.  \\(_           .-.         _____ =,=           (a.a)\n  //==I==\\\\,/            (d.b)       ()--___(0V0)  (/_     (=)\n ()  =\"=  ()             "
            " (u)        ||()----'      \\, ___.=\"==-._\n  \\`(0V0)               .-=\"-.       |' \\\\           ()---` ==\\==\\\\\n /|) ||\\\\              //==/=\\\\    ==\"   \\'                   =\"= ()\n     || \\\\  ==.       () ==== ()_/_    "
            "==\"               ____(0V0) \\`\n     ()  ()    \\,      `\\\"=      `                      ()---` // (|\\\n    //  //      \\\\ ___(0);`               \\)/ .-.       ||    //\n   '/  '/        ()---'  \\\\                /,(o,o)      |'   "
            "()\n   \"== \"==                \\\\              ()  (w)     ==\"     \\\\\n                           ()      /_ ___  \\\\,=\",              \\`\n        .-.               //       '-()-()   =/=\\\\            ==\"\n       (o.o)           "
            "  '/         //\\\\||  ==== ()           .-.   \\(_\n        (n)              \"==       /`  \\\\|  =\"=  `|          (-.-)  ,/\n      .-=\"=-.  \\)                ==\"    `(0V0)    '--         (-)  ()\n     // =T= \\\\,/                    "
            "                        .-=\"=.//\n    () ==|== ()         Happy                              //==I==`\n     \\  =\"=                    Halloween              _\\__()  ===\n     /)(0V0)                                 \\) .-.   -' `   "
            "(0V0)\n       // \\\\                                 //(e.e)        // //\n      //   \\\\      .-.  \\)                  ()  (=)        // //\n     ()     ()    (o.o) ,|                   \\\\.=\"=.      () ()\n      \\\\    ||     (m)  "
            "()               ()   ==/==\\\\      \\\\ \\\\\n       \\'   '|     =\"=//                //\\\\  ===  ()       \\` \\`\n     ==\"     \"==  //=T=   ()           /`  \\(0V0) _/      ==\" ==\"\n                 _\\` === //\\\\        ==\"    "
            "  || (|\\      ,==\n  (/_   .-.       /\\ (0V0)  `\\                ||          .\\\n   \\,  (o.o)           \\\\    \"==              ()   /_____  \\\\\n    ()  (=)             ()   ==.      .==      \\\\  ` '--()  ()\n     \\\\.=\"=-.  "
            "(|/     //     /,     ,/         \\`       \\\\ ||\n       ==|==\\\\,/      '/     //     //         ==\"        \\\\||      \\)/\n        ===  ()       \"==   ()     ()            .-.      (0A0)    ,/\n        =.=                  \\\\   "
            "//            (a,a)      =\"=    ()\n       (0V0)____              \\\\ //              (o)        ==\\= //\n        \\\\ ----()\\            (0A0)       \\(/  .-=\"=.        .==='\n         \\\\      `\\            =,=          "
            "\\,//==/=\\\\     //  (w)\n          ()       \"==        =====          () ==== ()   ()  (o'o)\n         //                  .==I==.            =\"=  |'    `\\  '-'\n        '/                 //  (=)  \\\\     ____(0V0)/|\\     /|)\n      "
            "  \"==               ()  (d'b)  ()   ()----`//\n                           \\`  '-'  `/     \\\\   //\n                          /|\\       /\\\\     \\` ()\n                                          ==\"   \\\\\n                            "
            "                     \\`\n                                               ==\"\n" );
}
