#include <iostream>
#include "functions.h"

void chess::initializeBoard(char (&board)[8][8]){
    //fill pieces
    char row1[8] =  { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };

    for (int i = 0; i<8; i++){
        //fill black pieces
        board[0][i] = row1[7-i];

        // fill white pieces
        board[7][i] = row1[i]+32;

        //fill pawns
        board[1][i] = 'P';
        board[6][i] = 'P'+32;

        for (int j = 2; j<6; j++) {
            board[j][i] = '_';
        }
    }
    return;
}

std::string chess::getSymbolStr(char ch, bool useSymbol){
    if (!useSymbol) {
        std::string a = "";
        a += ch;
        return a;
    }
    switch (ch) {

        case '_':
        return "_";
        break;

        case 'p':
        return "\u265F";
        break;

        case 'r':
        return "\u265C";
        break;

        case 'b':
        return "\u265D";
        break;

        case 'n':
        return "\u265A";
        break;

        case 'k':
        return "\u265A";
        break;

        case 'q':
        return "\u265B";
        break;

        case 'P':
        return "\u2659";
        break;

        case 'R':
        return "\u2656";
        break;

        case 'B':
        return "\u2657";
        break;

        case 'N':
        return "\u2658";
        break;

        case 'K':
        return "\u2655";
        break;

        case 'Q':
        return "\u2654";
        break;

        default:
        return "_";
    }
}
void chess::printBoard(char (&board)[8][8], bool useSymbol){
    for (int i = 0; i<8; i++){
        char rowLetter = 'h'-i;
        std::cout << rowLetter << "   ";
        for (int j = 0; j<8; j++){
            std::string symbol = getSymbolStr(board[i][j], UseSymbols);
            std::cout << symbol << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "    ";
    for (int i = 0; i<8; i++){
        std::cout << i+1 << " ";
    }
}

bool chess::setUseSymbols(bool b)  {
    UseSymbols = b;
    return b;
}
