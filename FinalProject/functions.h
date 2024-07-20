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
    void initializeBoard(char (&board)[8][8]);
    void printBoard(char (&board)[8][8]);


    bool setUseSymbols(bool b);

    bool getUseSymbols() const {return UseSymbols;}
};


#endif
