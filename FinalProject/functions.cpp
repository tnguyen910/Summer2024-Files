#include <cctype>
#include <iostream>
#include <ostream>
#include "functions.h"

void chess::initializeBoard(){

    //fill pieces
    char row1[8] =  { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R' };

    for (int i = 0; i<8; i++){
        //fill black pieces
        Board[0][i] = row1[7-i];

        // fill white pieces
        Board[7][i] = row1[i]+32;

        //fill pawns
        Board[1][i] = 'P';
        Board[6][i] = 'P'+32;

        for (int j = 2; j<6; j++) {
            Board[j][i] = '_';
        }
    }
    return;
}

std::string chess::getCurrentTurn() {
     if (IsWhiteTurn) {
          return "White";
     } else{
          return "Black";
     }
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
        return "\u265E";
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
void chess::printBoard(bool useSymbol){
    for (int i = 0; i<8; i++){
        std::cout << 8-i << "   ";
        for (int j = 0; j<8; j++){
            std::string symbol = getSymbolStr(Board[i][j], UseSymbols);
            std::cout << symbol << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "    ";
    for (int i = 0; i<8; i++){
        char colLetter = i+'a';
        std::cout << colLetter << " ";
    }
    std::cout << std::endl << std::endl;
}

bool chess::setUseSymbols(bool b)  {
    UseSymbols = b;
    return b;
}

bool validatePosition(std::string str) {
    if (!(str[0] >= 'a' && str[0] <= 'h')){
        return false;
    }
    if (!(str[1] >= 1 && str[0] <= 8)) {
        return false;
    }
    return true;
}

pieceType chess::getPieceFromChar(char ch){
    switch (ch) {
        case 'R':
        case 'r':
        return Rook;
        break;

        case 'B':
        case 'b':
        return Bishop;
        break;

        case 'N':
        case 'n':
        return Knight;
        break;

        case 'K':
        case 'k':
        return King;
        break;

        case 'Q':
        case 'q':
        return Queen;
        break;

        case 'P':
        case 'p':
        return Pawn;
        break;

        default:
        return Error;
        break;
    }
}

char chess::getCharFromPiece(pieceInstance piece){
    char ch;
    switch (piece.Type) {
        case Pawn:
        ch = 'P';
        break;

        case Rook:
        ch = 'R';
        break;

        case Bishop:
        ch = 'B';
        break;

        case Knight:
        ch = 'N';
        break;

        case King:
        ch = 'K';
        break;

        case Queen:
        ch = 'Q';
        break;

        default:
        ch = '_';
        break;
    }
    if (piece.IsWhite){
        ch = tolower(ch);
    }
    return ch;
}

pieceInstance chess::parsePieceString(std::string str){
     std::string original = str;
    pieceInstance piece;
    try {
        int size = str.size();
        if (str.size() < 2 || str.size() >5) { //Validate Min Size
            throw ("Invalid Input");
        }

        // EX: Ng1xf3 -> continue

        int i = 0;
        piece.Type = (str[0] >= 'A'  && str[0] <= 'Z') ? getPieceFromChar(str[0]) : Pawn;

        // Ex: Ng1xf3 -> piece.Type = Knight;

        if (piece.Type == Error){
            throw ("Invalid piece type");
        }

        //Handle original position
        if (piece.Type != Pawn) {
            str = str.substr(1,str.length()-1);
        }
        // Ex: Ng1xf3 -> changes to g1xf3

        int length = str.length();
        if (str[length-2] >= 'a' && str[length-2] <= 'h' && str[length-1] >= '1' && str[length-1] <= '8') { //set new position
            piece.NewPos.first = '8' - str[length-1];
            piece.NewPos.second = str[length-2] - 'a';
            str = str.substr(0, length-2);
            length = str.length();
        } else{
            throw ("Invalid notation.");
        }

        // Ex: g1xf3 -> Newpos = (row: 6, column 0)
        // g1xf3 changes to g1x

        if (str[length-1] == 'x'){ // mark if there is an "x" symbolizing a take, remove x
            piece.Capturing = true;
            str.erase(str.end()-1);
            length = str.length();
        } else if (length > 2) {
            throw ("Invalid notation.");
        }
        // Ex: g1x -> changes to g1, capturing -> true
        if(length == 2){
            if (str[0] >= 'a' && str[0] <= 'h' && str[1] >= '1' && str[1] <= '8') {
                piece.FirstPos.first = '8' - str[1] ;
                piece.FirstPos.second = str[0] - 'a';
            } else {
                throw("Invalid notation. ");
            }
        } else if (length ==1) {
            if (str[0] >= 'a' && str[0] <= 'h') {
                piece.FirstPos.second = str[0] - 'a';
            } else {
                throw("Invalid notation. ");
            }

            if(!possibleInferedMove(piece)){
                throw("Invalid move.");
            }
        } else if (length == 0) {
            if(!possibleInferedMove(piece)){
                throw("Invalid move.");
            }
        } else {
            throw("Invalid notation.");
        }

        if(!validateMove(piece)){
            throw("Invalid move.");
                piece.Type = Error;
        }

    } catch (char const* err) {
        piece.Type = Error;
        std::cout << "Error on '" << original <<"': " << err << std::endl;
        return piece;
    }

    return piece;

}

void chess::setPiece(pieceInstance &piece) {
    Board[piece.FirstPos.first][piece.FirstPos.second] = '_';
    Board[piece.NewPos.first][piece.NewPos.second] = getCharFromPiece(piece);
}

void chess::movePieces(std::string str) {
    str += ' ';
    int substrStart = 0;
    for (int i = 0; i<str.size(); i++){
        if (str[i] == ' ') {

            // "b5d5 d5e5 "
            std::string move = str.substr(substrStart, i-substrStart);
            pieceInstance currentPiece = parsePieceString(move);
            if (currentPiece.Type == Error) {
                break;
            }

            std::cout <<CurrentMove << ". "<< move << std::endl;
            CurrentMove++;
            Moves.push_back(move);
            setPiece(currentPiece);
            IsWhiteTurn = (IsWhiteTurn) ? false : true;
            substrStart = i+1;
        }
    }

}


bool chess::executeTurn(){
     start:
     std::cout << "Input next move using chess algebraic notation (!settings): ";
     std::string str;
     getline(std::cin, str);

     for (int i = 0; i<20; i++){
          std::cout << std::endl;
     }

     std::cout << "======= Chess =======" << std::endl << std::endl;


    if (str == "!settings") {
        bool end = settings();
        if (end){
            return true;
        }
        std::cout << std::endl;
        for (int i = 0; i<20; i++){
               std::cout << std::endl;
          }
        std::cout << "======= Chess =======" << std::endl << std::endl;
        printBoard();
        std::cout << "Next to Move: " << getCurrentTurn() << std::endl ;
        goto start;
    }
    else {
        movePieces(str);
        std::cout << std::endl;
        std::cout << "======= Chess =======" << std::endl << std::endl;
    }
    return false;
}

void chess::printAllMoves(){
     std::cout << "===== All Previous Moves =====" << std::endl;
     for (int i = 0; i < Moves.size(); i++){
          std::cout << i+1 << ". " << Moves[i] << std::endl;
     }
     std::cout << "==============================" << std::endl;

     std::cout << "Press Enter to Continue";
     std::string x;
     getline(std::cin, x);
}

bool chess::settings () {
    std::cout << "=====  Settings Menu  =====" << std::endl;
    std::cout << "0. End  " << std::endl;
    std::cout << "1. Toggle Symbols" << std::endl;
    std::cout << "2. Show all previous moves." << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << std::endl;
    std::cout << "Input Argument: ";
    int arg;
    std::cin >> arg;
    std::cin.ignore();

    switch (arg) {
     case 0:
          return true;
          break;
     case 1:
          UseSymbols = (UseSymbols) ? false : true;
          break;
     case 2:
          printAllMoves();
          break;
     default:
          std::cout << "Invalid";
          break;
    }
    return false;

}
