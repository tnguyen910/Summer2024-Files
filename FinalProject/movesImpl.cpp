#include "functions.hpp"
#include <iostream>

bool chess::validateMove(pieceInstance &piece) {
  if (!(piece.NewPos.first < 8 && piece.NewPos.second < 8)) {
    return false;
  }

  switch (piece.Type) {
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
  if (boardPiece >= 'A' && boardPiece <= 'Z') {
    piece.IsWhite = false;
  }

  pieceType test = getPieceFromChar(boardPiece);
  if (getPieceFromChar(boardPiece) != Pawn) {
    return false;
  }

  int pawnRow = (piece.IsWhite) ? 6 : 1;
  int rowOffset = (piece.IsWhite) ? -1 : 1;

  char opp = (piece.IsWhite) ? 'A' : 'a';

  if (!piece.Capturing) {
    if (Board[piece.NewPos.first][piece.NewPos.second] != '_') { // if the spot is occupied by an opposite side, return
                        // false
      return false;
    }

    if (piece.FirstPos.first + rowOffset == piece.NewPos.first &&
        piece.FirstPos.second == piece.NewPos.second) {
      return true;
    } else if (piece.FirstPos.first + rowOffset * 2 == piece.NewPos.first &&
               piece.FirstPos.second == piece.NewPos.second &&
               piece.FirstPos.first == pawnRow) {
      return true;
    } else {
      return false;
    }
  } else if (piece.Capturing) {
    if ((Board[piece.NewPos.first][piece.NewPos.second] <= opp &&
         Board[piece.NewPos.first][piece.NewPos.second] >= opp + 25) ||
        Board[piece.NewPos.first][piece.NewPos.second] ==
            '_') { // if NewPos is not occupied by an opposing piece, return
                   // false
      return false;
    }

    if (piece.FirstPos.first + rowOffset == piece.NewPos.first &&
        abs(piece.NewPos.second - piece.FirstPos.second) == 1) {
      return true;
    } else {
      return false;
    }
  }
  return false;
}

bool chess::validateKnightMove(pieceInstance &piece){

    char currentSlot = Board[piece.FirstPos.first][piece.FirstPos.second];
    char newSlot = Board[piece.NewPos.first][piece.NewPos.second];
    if (currentSlot >= 'A' && currentSlot <= 'Z') {
        piece.IsWhite = false;
    }

    if (getPieceFromChar(currentSlot) != Knight) {
      return false;
    }

    char opp = (piece.IsWhite) ? 'A' : 'a';

    if(!piece.Capturing){
        if (newSlot >= opp && newSlot <= opp+25) { // return false if the piece is occupied by the oppsoite side
            return false;
        }


    }



    return false;
}


// inference for ambiguous pieces

bool chess::possibleInferedMove(pieceInstance &piece) {

     switch (piece.Type) {
          case Pawn:
               return inferPawn(piece);
               break;

          default:
               std::cout << std::endl << "Move not implemented yet!" << std::endl << std::endl;
               return false;
               break;
  }
}

bool chess::inferPawn(pieceInstance &piece) {

     int offset = (IsWhiteTurn) ? 1 : -1;
     char ch = (IsWhiteTurn) ? 'p' : 'P';
     int pawnRow = (IsWhiteTurn) ? 6 : 1;
     char chdebug = Board[piece.NewPos.first+offset*2][piece.NewPos.second];

     // handle case where column is known:
     if (piece.FirstPos.second != -1) {
          if (piece.Capturing) {
               if (piece.NewPos.second == piece.FirstPos.second) {
                    return false;
               }
          } else if (!piece.Capturing) {
               if (piece.NewPos.second != piece.FirstPos.second) {
                    return false;
               }
          }

          if (Board[piece.NewPos.first + offset][piece.FirstPos.second] == ch) { // check for 1 square move
               piece.FirstPos.first = piece.NewPos.first + offset;
               return true;
          } else if (Board[piece.NewPos.first + 2 * offset][piece.FirstPos.second] == ch && piece.NewPos.first + 2 * offset ==pawnRow) { // first move double move for white
               piece.FirstPos.first = piece.NewPos.first + 2 * offset;
               return true;
          } else {
               return false;
          }
     } else if (piece.FirstPos.second == -1) {
          if (piece.Capturing) {
               if (piece.NewPos.second == piece.FirstPos.second) {
                    return false;
               }

               if (Board[piece.NewPos.first + offset * 1][piece.NewPos.second + 1] == ch && Board[piece.NewPos.first + offset * 1][piece.NewPos.second - 1] == ch) { // handle ambiguity
                    return false;
               } else if (Board[piece.NewPos.first + offset * 1][piece.NewPos.second + 1] == ch) { // check for pawn on left diagonal
                    piece.FirstPos.second = piece.NewPos.second + 1;
                    piece.FirstPos.first = piece.NewPos.first + 1 * offset;
                    return true;
               } else if (Board[piece.NewPos.first + offset * 1][piece.NewPos.second - 1] == ch) { // check for pawn on right diag
                    piece.FirstPos.second = piece.NewPos.second - 1;
                    piece.FirstPos.first = piece.NewPos.first + 1 * offset;
                    return true;
               } else {
                    return false;
               }
          } else if (!piece.Capturing) {
               if(Board[piece.NewPos.first+offset*2][piece.NewPos.second] == ch && piece.NewPos.first+offset*2==pawnRow) {
                    piece.FirstPos.first = piece.NewPos.first+offset*2;
                    piece.FirstPos.second = piece.NewPos.second;
                    return true;
               } else if(Board[piece.NewPos.first+offset*1][piece.NewPos.second] == ch){
                    piece.FirstPos.first = piece.NewPos.first+offset*1;
                    piece.FirstPos.second = piece.NewPos.second;
                    return true;
               } else {
                    return false;
               }
          }
     }
     return false;
}
