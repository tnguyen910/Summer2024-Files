#include <iostream>
#include "functions.h"

int main() {
    char board[8][8];
    chess chess(true);
    chess.initializeBoard(board);
    chess.printBoard(board);
    return 0;
}
