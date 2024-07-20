#include <iostream>
#include "functions.h"

int main() {

    std::cout << "CONSOLE CHESS GAME: " << std::endl;
    std::cout << "View Chess Symbols? (Y/N): ";

    bool symbols = true;
    while (true){
        char symbolsIn;
        std::cin >> symbolsIn;

        if (symbolsIn == 'Y') {
            symbols = true;
            break;
        }

        else if (symbolsIn == 'N') {
            symbols = false;
            break;
        }
        else {
            std::cout << "Invalid Input";
        }

    }

    char board[8][8];
    chess chess(symbols);


    chess.initializeBoard();

    while(true){
        chess.printBoard();
        int x;
        std::cin >> x;
        if (x == 0){
            break;
        }
    }

    std::cout << "thanks for playing!";
    return 0;
}
