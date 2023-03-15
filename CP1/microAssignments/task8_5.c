/*
  Voorzie de juiste enum buiten de main, zodat de code kan compileren en zonder de main aan te passen.
*/

#include <stdio.h>
//--
enum chess {
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
    PAWN
};
//--

int main( void )
{
    enum chess board[8][8];
    board[0][0] = ROOK;
    board[0][1] = KNIGHT;
    board[0][2] = BISHOP;
    board[0][3] = QUEEN;
    board[0][4] = KING;
    board[0][5] = BISHOP;
    board[0][6] = KNIGHT;
    board[0][7] = ROOK;
    board[1][0] = PAWN;
    board[1][1] = PAWN;
    board[1][2] = PAWN;
    board[1][3] = PAWN;
    board[1][4] = PAWN;
    board[1][5] = PAWN;
    board[1][6] = PAWN;
    board[1][7] = PAWN;
    printf( "Board initialized.\n" );
    return 0;
}
