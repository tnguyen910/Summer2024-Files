#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Input a string: ";
    getline(cin, s);
    s = s + " ";
    int maxLength = 0;
    string longestWord = "";

    maxLength = s.find(' ');
    longestWord = s.substr(0, s.length()-s.find(' '));
    s = s.substr(s.find(' ')+1, s.length()-s.find(' '));


    while (s.length() > 0) {
        string currentWord = s.substr(0, s.find(' ')); 
        if (currentWord.length() > maxLength) {
            maxLength = currentWord.length();
            longestWord = currentWord;
        }
        if (s.find(' ') != string::npos && s.length() > s.find(' ')){
                s = s.substr(s.find(' ')+1, s.length()-s.find(' '));
            } else {
                s = "";
            }
    }
    cout << "Max Length: " << maxLength << endl; 
    cout << "Longest word: " << longestWord << endl;
}