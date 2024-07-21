#include <cctype>
#include <iostream>
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
    pieceInstance piece;
    try {

        if (str.size() < 4) { //Validate Min Size
            throw ("Invalid Input");
        }

        int i = 0;
        piece.Type = (str[0] >= 'A'  && str[0] <= 'Z') ? getPieceFromChar(str[0]) : Pawn;

        if (piece.Type == Error){
            throw ("Invalid piece type");
        }

        //Handle original position
        if (piece.Type != Pawn) {
            str = str.substr(1,str.length()-1);
        }

        if (str[0] >= 'a' && str[0] <= 'h' && str[1] >= '1' && str[1] <= '8') {
            piece.FirstPos.first = '8' - str[1] ;
            piece.FirstPos.second = str[0] - 'a';
        // } else if (str[0] >= 'a' && str[0] <= 'h' && str[1] == 'x') {
        //     if (!validCapture) { // sets new first position if valid capture, return false and throw if not
        //         throw ("Invalid move.");
        //     }
        } else{
            throw ("Invalid first location");
        }

        int length;

        if(str[2] == 'x'){ //Check for capture and validate length
            piece.Capturing = true;
            if (str.length()==5){
                length = 5;
            } else{
                throw ("Invalid notation");
            }
        } else {
            if (str.length()==4){
                length = 4;
            } else{
                throw ("Invalid notation");
            }
        }



        if (str[length-2] >= 'a' && str[length-2] <= 'h' && str[length-1] >= '1' && str[length-1] <= '8') { //set new position
            piece.NewPos.first = '8' - str[length-1];
            piece.NewPos.second = str[length-2] - 'a';
        } else{
            throw ("Invalid notation.");
        }

        if(!validateMove(piece)){
            throw("Invalid move.");
                piece.Type = Error;
            }

    } catch (char const* err) {
        piece.Type = Error;
        std::cout << "Error on '" << str <<"': " << err << std::endl;
        return piece;
    }

    return piece;

}

bool chess::validSlot(pieceInstance &piece){
    char ch = Board[piece.NewPos.first][piece.NewPos.second];
    if (piece.IsWhite && (ch >= 'a' && ch <= 'z')) {
        return false;
    }
    if (!piece.IsWhite && (ch >= 'A' && ch <= 'Z')) {
        return false;
    }
    return true;
}



bool chess::setPiece(pieceInstance &piece) {
    if (validSlot(piece)) {
        Board[piece.FirstPos.first][piece.FirstPos.second] = '_';
        Board[piece.NewPos.first][piece.NewPos.second] = getCharFromPiece(piece);
        return true;
    }
    return false;

}

void chess::movePieces(std::string str) {
    str += ' ';
    int substrStart = 0;
    for (int i = 0; i<str.size(); i++){
        if (str[i] == ' ') {

            // "b5d5 d5e5 "
            std::string move = str.substr(substrStart, i-substrStart);
            pieceInstance currentPiece = parsePieceString(move);
            std::cout << move << std::endl;
            if (currentPiece.Type == Error) {
                break;
            }
            setPiece(currentPiece);
            substrStart = i+1;
        }
    }

}


bool chess::executeTurn(){

    std::cout << "Input next move using chess algebraic notation (!settings): ";
    std::string str;
    getline(std::cin, str);

    if (str == "!settings") {
        bool end = settings();
        if (end){
            return true;
        }
    }
    else {
        movePieces(str);
    }
    return false;
}

bool chess::settings () {
    std::cout << "=====  Settings Menu  =====" << std::endl;
    std::cout << "0. End  " << std::endl;
    std::cout << "1. Toggle Symbols" << std::endl;
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
        default:
            std::cout << "Invalid";
            break;
    }
    return false;

}
