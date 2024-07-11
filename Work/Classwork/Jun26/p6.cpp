#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    string largestName = "";
    bool beginningOfName = true;
    bool wordsLeft = true;
    while(wordsLeft) {
        if (beginningOfName) {
            int pos = s.find(' ');
            largestName = s.substr(0, pos);
            beginningOfName = false;
            s = s.substr(s.find(' ')+1, s.length()-largestName.length()+1); 
            continue;
        }
        if (toupper(s[0]) <= largestName[0]){
            if (s.find(' ') == std::string::npos) {
                // finish code for the last word
                largestName = s;
                wordsLeft = false;
                break;
            }
            else {
                largestName = s.substr(0, s.find(' '));
            }
            
        }
        s = s.substr(s.find(' ')+1, s.length()-largestName.length()+1);        
    }
    cout << "The name earliest in alphabetical order is: " << largestName << endl;
}