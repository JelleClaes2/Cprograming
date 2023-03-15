/*
  Implementeer de functie spookyElements(). Deze functie roept de functies drawSkeleton(), drawWitch() en drawPumpkin() op. Het aantal keer dat deze functies worden opgeroepen wordt bepaald door de functie parameters van de functie spookyElements().
*/

#include <stdio.h>
#include <stdint.h>

void spookyElements( uint8_t skeletons, uint8_t witches, uint8_t pumpkins );
void drawSkeleton();
void drawWitch();
void drawPumpkin();

int main( void )
{
    printf( "Hoeveel skeletten, heksen en pompoenen wil je tonen? " );

    uint8_t skeletten = 0;
    uint8_t heksen = 0;
    uint8_t pompoenen = 0;
    (void)scanf( "%hhu %hhu %hhu", &skeletten, &heksen, &pompoenen );

    spookyElements( skeletten, heksen, pompoenen );
    return 0;
}

void spookyElements(uint8_t skeletons, uint8_t witches, uint8_t pumpkins)
{
    for(int i=0; i<skeletons;i++){
        drawSkeleton();
    }
    for(int i=0;i<witches;i++){
        drawWitch();
    }
    for(int i=0;i<pumpkins;i++){
        drawPumpkin();
    }
}

void drawSkeleton()
{
    printf( "\n\n" );
    printf( "    .-.             \n" );
    printf( "   (o.o)            \n" );
    printf( "    (n)             \n" );
    printf( "  .-=\"=-.  \\)     \n" );
    printf( " // =T= \\\\,/      \n" );
    printf( "() ==|== ()         \n" );
    printf( " \\  =\"=           \n" );
    printf( " /)(0V0)            \n" );
    printf( "   // \\\\          \n" );
    printf( "  //   \\\\         \n" );
    printf( " ()     ()          \n" );
    printf( "  \\\\    ||        \n" );
    printf( "   \\'   '|         \n" );
    printf( "==\"     \"==       \n" );
}

void drawWitch()
{
    printf( "\n\n" );
    printf( "      ___                                            \\--/          \n" );
    printf( "   .'   `\"-._                                     /`-'  '-`\\      \n" );
    printf( "  / ,        `'-_.-.                             /          \\      \n" );
    printf( " / /`'.       ,' _  |                           /.'|/\\  /\\|'.\\   \n" );
    printf( "`-'    `-.  ,' ,'\\/                                  \\/           \n" );
    printf( "          \\, ,'  ee`-.                                             \n" );
    printf( "          / ./  ,(_   \\      ,                                     \n" );
    printf( "         (_/\\\\\\ \\__|`--'     ||                                 \n" );
    printf( "         ///\\\\|     \\        ||                                  \n" );
    printf( "         ////||-./`-.}    .--||                                     \n" );
    printf( "            /     `-.__.-`_.-.|                                     \n" );
    printf( "            |      '._,-'`|___}    `;                               \n" );
    printf( "            /   '.        |/ || ,;'`                                \n" );
    printf( "            |     '.__,.-`   || ':,                                 \n" );
    printf( "            |       |        || ,;'                                 \n" );
    printf( "            /       /     _,.||oOoO.,_                              \n" );
    printf( "           |        |     \\-.O,o_O..-/                             \n" );
    printf( "          /         /     /          \\                             \n" );
    printf( "         |         /     /            \\                            \n" );
    printf( "         |         |    |      ,       |                            \n" );
    printf( "         /         |    \\   ) (     )  /                           \n" );
    printf( "        |           \\   ,'.(:, ),: (_.'.                           \n" );
    printf( "       /            /'.' =\"`\"\"=\"=\"==\"= '.                     \n" );
    printf( "      `'\"---'-.__.'\"\"\"`    ` \"\" \"\" `\"\"                    \n" );
}

void drawPumpkin()
{
    printf( "\n\n" );
    printf( "                    .-'\\                            \n" );
    printf( "                   \\:. \\                           \n" );
    printf( "                   |:.  \\                           \n" );
    printf( "                   /::'  \\                          \n" );
    printf( "                __/:::.   \\                         \n" );
    printf( "        _.-'-.'`  `'.-'`'._\\-\"`\";.-'-,            \n" );
    printf( "     .`;    :      :     :      :   : `.             \n" );
    printf( "    / :     :      :                 :  \\           \n" );
    printf( "   /        :/\\          :   /\\ :     :  \\        \n" );
    printf( "  ;   :     /\\ \\   :     :  /\\ \\      :   ;      \n" );
    printf( " .    :    /  \\ \\          /  \\ \\          .     \n" );
    printf( " ;        /_)__\\ \\ :     :/_)__\\ \\    :    ;     \n" );
    printf( ";         `-----`' : ,   :`-----`'          ;        \n" );
    printf( "|    :      :       / \\         :     :     |       \n" );
    printf( "|                  / \\ \\ :            :     |      \n" );
    printf( "|    :      :     /___\\ \\:      :           |      \n" );
    printf( "|    :      :     `----`'       :           |        \n" );
    printf( ";        |;-.,__   :     :   __.-'|   :     ;        \n" );
    printf( " ;    :  ||   \\ \\``/'---'\\`\\` /  ||        ;     \n" );
    printf( "  .    :  \\\\   \\_\\/       \\_\\/   //   '   .    \n" );
    printf( "   ;       \'._    /\\     /\\ _.-'/   :   ;         \n" );
    printf( "    \\   :   `._`'-/ /\\._./ /\\  .'  :    /         \n" );
    printf( "     `\\  :     `-.\\/__\\__\\/_.;'   :   /`         \n" );
    printf( "       `\\  '   :   :        :   :  /`               \n" );
    printf( "         `-`.__`        :   :__.'-`                  \n" );
    printf( "               `-..`.__.'..-                         \n" );
}
