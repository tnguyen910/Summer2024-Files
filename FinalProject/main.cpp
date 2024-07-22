#include <iostream>
#include "functions.hpp"

int main() {

     std::cout << "CONSOLE CHESS GAME: " << std::endl;
     std::cout << "View Chess Symbols? (Y/N): ";

     bool symbols = true;
     while (true){
     std::string symbolsIn;
     getline(std::cin, symbolsIn);

     if (symbolsIn == "Y") {
          symbols = true;
          break;
     }

     else if (symbolsIn == "N") {
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
     for (int i = 0; i<20; i++){
          std::cout << std::endl;
     }
     std::cout << "======= Chess =======" << std::endl << std::endl ;
     chess.printBoard();

     std::cout<< "First move: " << chess.getCurrentTurn() << "." << std::endl;
     while (true){
          bool end = chess.executeTurn();
          if (end){
               break;
          }
          chess.printBoard();
          std::cout<< "Next to move: " << chess.getCurrentTurn() << "." << std::endl;

     }

     std::cout << "thanks for playing!";
     return 0;
}
