#include <iostream>
#include "functions.h"

bool chess::validateMove(pieceInstance &piece) {
    if (!(piece.NewPos.first < 8 && piece.NewPos.second < 8)) {
        return false;
    }

    switch (piece.Type){
        case Pawn:
            return validatePawnMove(piece);
            break;

        default:
            return false;
            break;
    }
}

// does not implement en passant or prevent checks
bool chess::validatePawnMove(pieceInstance &piece) {


    char boardPiece = Board[piece.FirstPos.first][piece.FirstPos.second];
    if( boardPiece >= 'A' && boardPiece <= 'Z'){
        piece.IsWhite = false;
    }

    pieceType test = getPieceFromChar(boardPiece);
    if( getPieceFromChar(boardPiece) != Pawn){
        return false;
    }


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
        if ((Board[piece.NewPos.first][piece.NewPos.second] <= opp && Board[piece.NewPos.first][piece.NewPos.second] >= opp+25 ) || Board[piece.NewPos.first][piece.NewPos.second] == '_'){ // if NewPos is not occupied by an opposing piece, return false
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


bool chess::possibleCapture(pieceInstance &piece){

    switch (piece.Type){
        case Pawn:
            return possibleCaptureByPawn(piece);
            break;

        default:
            return false;
            break;
    }
}

bool chess::possibleCaptureByPawn(pieceInstance &piece) {
    return false;
}
