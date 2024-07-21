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
        char rowLetter = 'h'-i;
        std::cout << rowLetter << "   ";
        for (int j = 0; j<8; j++){
            std::string symbol = getSymbolStr(Board[i][j], UseSymbols);
            std::cout << symbol << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    std::cout << "    ";
    for (int i = 0; i<8; i++){
        std::cout << i+1 << " ";
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

pieceType getPieceFromChar(char ch){
    switch (ch) {
        case 'R':
        return Rook;
        break;

        case 'B':
        return Bishop;
        break;

        case 'N':
        return Knight;
        break;

        case 'K':
        return King;
        break;

        case 'Q':
        return Queen;
        break;

        default:
        return Error;
        break;
    }
}

char getCharFromPiece(pieceInstance piece){
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
    if (piece.IsWhite == false){
        ch = toupper(ch);
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
        if (piece.Type == Pawn) {
            str = str.substr(1,str.length()-1);
        }

        if (str[0] >= 'a' && str[0] <= 'h' && str[1] >= '1' && str[1] <= '8') {
            piece.FirstPos.first = 'h' - str[0];
            piece.FirstPos.second = str[1] - 1;
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
            piece.NewPos.first = 'h' - str[length-2];
            piece.NewPos.second = str[length-1] - 1;
        } else{
            throw ("Invalid notation.");
        }

        if(!validateMove(piece)){
            throw("Invalid move.");
                piece.Type = Error;
            }

    } catch (std::string err) {
        piece.Type = Error;
        std::cout << "Error on '" << str <<"': " << err;
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


// does not implement en passant or prevent checks
bool chess::validatePawnMove(pieceInstance &piece) {

    int pawnRow = (piece.IsWhite) ? 6 : 1;
    int rowOffset = (piece.IsWhite) ? -1: 1;

    char opp = (piece.IsWhite) ? 'A' : 'a';

    if (!piece.Capturing){
        if (Board[piece.NewPos.first][piece.NewPos.second] >= opp && Board[piece.NewPos.first][piece.NewPos.second] <= opp+25 ){ // if the spot is occupied by an opposite side, return false
            return false;
        }

        if (piece.FirstPos.first+rowOffset == piece.NewPos.first && piece.FirstPos.second == piece.NewPos.second) {
            return true;
        } else if (piece.FirstPos.first+rowOffset*2 == piece.NewPos.first && piece.FirstPos.second == piece.NewPos.second && piece.FirstPos.first == pawnRow) {
            return true;
        } else {
            return false;
        }
    } else if (piece.Capturing){
        if (Board[piece.NewPos.first][piece.NewPos.second] <= opp && Board[piece.NewPos.first][piece.NewPos.second] >= opp+25 ){ // if NewPos is not occupied by an opposing piece, return false
            return false;
        }

        if (piece.FirstPos.first+rowOffset == piece.NewPos.first && abs(piece.NewPos.second-piece.FirstPos.second)== 1) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

bool chess::validateMove(pieceInstance &piece) {
    switch (piece.Type){
        case Pawn:
            return validatePawnMove(piece);
            break;

        default:
            return false;
            break;
    }
}

void chess::movePieces(std::string str) {
    str+= ' ';
    int substrStart = 0;
    for (int i = 0; i<str.size(); i++){
        if (str[i] == ' ') {
            std::string move = str.substr(substrStart, i);
            pieceInstance currentPiece = parsePieceString(move);
            std::cout << move;
            if (currentPiece.Type == Error) {
                break;
            }
            if (!setPiece(currentPiece)){ // executes the board reshuffle if the piece move is valid, if not, breaks loop
                std::cout << "Error on '" << move <<"': Invalid position to move to.";
                break;
            }
        }
    }

}


void chess::executeTurn(){
    std::cout << "Input next move using chess algebraic notation (input !help for help with settings): ";
    std::string str;
    getline(std::cin, str);

    if (str == "settings") {

    }
    else {
        movePieces(str);
    }
}
