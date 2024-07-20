#ifndef INTERFACE_H
#define INTERFACE_H
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

//Add Functions

class chess{

    private:
    bool UseSymbols;

    public:
    chess (bool useSymbols = true) : UseSymbols(useSymbols){}
    void initializeBoard(char (&board)[8][8]);

    void printBoard(char (&board)[8][8]);
    void printBoard(char (&board)[8][8], bool useSymbol);

    std::string getSymbolStr(char ch);
    std::string getSymbolStr(char ch, bool useSymbol);

    bool setUseSymbols(bool b);

    bool getUseSymbols() const {return UseSymbols;}
};

inline std::string chess::getSymbolStr(char ch) {
    return getSymbolStr(ch, UseSymbols);
}

inline void chess::printBoard(char (&board)[8][8]) {
    chess::printBoard(board, UseSymbols);
}


#endif
