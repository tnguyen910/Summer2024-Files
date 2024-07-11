#include "functions.h"
#include <iostream>
using namespace std;

int allPalindromes(std::string str) {

    int palindromeIndex = 0;
    int palindromeEnd = 0;
    bool isPalindrome = false;

    //Detect palindrome indices
    for (int i = 0, j = str.size()-1; i < j; i++, j--) {
        if (str[i] == str[j]) {
            if (!isPalindrome) {
                palindromeIndex = i;
                palindromeEnd = j;
            }
            isPalindrome = true;
        }
        else {isPalindrome = false;}
    }

    for (int i = palindromeIndex, k =0; i < palindromeEnd; i++, k++) {
        string printStr = "";
        for (int j = i; j < palindromeEnd-k+1; j++){
            printStr += str[j];
        }
        if (printStr.size()>1) {
            cout << printStr << endl;
        }
       
    }
    return 0;
}

// Returns index found, if no index found, -1.
int findWord(std::string str, std::string target) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == target[0]) {
            for (int j = 0; j < target.length(); j++) {
                if (str[i+j] == target[j]) {
                    continue;
                } 
                else {
                    i = i+j;
                    goto noMatch;
                    }
            }
            // returns <true, index>
            return i;
        }
        noMatch:
        continue;
    }
    return -1;
}