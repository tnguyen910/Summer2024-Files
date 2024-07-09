#include <iostream>
using namespace std;

int main() {

    string str;
    while (true) {
        cout << "Input a string with 2 words: ";
        getline(cin,str); 
        int spaces = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ') {
                spaces++;
            }
        }
        if (spaces > 1) {
            cout << "Invalid String!" << endl;
        } else {
            break;
        }
    }

    int spaceIndex = str.find(' ');
    int starSubstrLength = str.length()-spaceIndex-1;
    string returnStr = str.substr(0, spaceIndex) + " ";

    for (int i = 0; i < starSubstrLength; i++) {
        returnStr += "*";
    }
    cout << returnStr << endl;

    
}