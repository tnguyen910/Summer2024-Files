#include <iostream>
#include <vector>
#include "functions.h"

int main (){
    return 0;
}
std::vector< std::vector<char> > initializeBoard(){
    std::vector< std::vector<char> > chessBoard;

    //fill white pieces
    std::vector<char> row1  { 'R', 'K', 'B', 'Q', 'K', 'B', 'K', 'R' };

    //fill empty rows
    for (int i = 2; i<6; i++) {
        std::vector<char> emptyRow;
        for (int j = 0; j<8; j++) {
            emptyRow.push_back('0');
        }
        chessBoard.push_back(emptyRow);
    }
    return chessBoard;
}
