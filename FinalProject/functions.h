#ifndef INTERFACE_H
#define INTERFACE_H
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

//Add Functions

enum pieceType {
    Pawn, Knight, Bishop, Rook, King, Queen, Error
};
class pieceInstance{
    public:
        std::pair<int, int> FirstPos;
        std::pair<int, int> NewPos;
        bool Capturing;
        bool IsWhite;
        pieceType Type;
        pieceInstance(std::pair<int,int> firstPos = {-1,-1}, std::pair<int,int> newPos = {-1,-1}, bool isWhite = true, pieceType type = Error) {
                    FirstPos = firstPos;
                    NewPos = newPos;
                    IsWhite = isWhite;
                    Capturing = false;
                    Type = type;
                }
};

class chess{

    private:
        bool UseSymbols;
        char Board[8][8];
        bool VerifyValidity;
        bool IsWhiteTurn;

    public:
        chess (bool useSymbols = true, bool verify = true) {
            VerifyValidity = verify;
            UseSymbols = useSymbols;
            IsWhiteTurn = false;
        }

        void initializeBoard();

        bool settings();
        bool executeTurn();
        void movePieces(std::string str);
        bool setPiece(pieceInstance &piece);
        bool validSlot(pieceInstance &piece);

        // parses string to convert to a pieceInstance for move.
        pieceInstance parsePieceString(std::string str);
        char getCharFromPiece(pieceInstance piece);

        //check to see if a peice that can potentially capture exists, and set it. return false if not
        bool possibleInferedMove(pieceInstance &piece);
        bool inferPawn(pieceInstance &piece);

        //composite function to validate moves
        bool validateMove(pieceInstance &piece);
        bool validatePawnMove(pieceInstance &piece);



        pieceType getPieceFromChar(char ch);

        void printBoard();
        void printBoard(bool useSymbol);

        std::string getSymbolStr(char ch);
        std::string getSymbolStr(char ch, bool useSymbol);

        bool setUseSymbols(bool b);

        bool getUseSymbols() const {return UseSymbols;}
};

inline std::string chess::getSymbolStr(char ch) {
    return getSymbolStr(ch, UseSymbols);
}

inline void chess::printBoard() {
    chess::printBoard(UseSymbols);
}


#endif
