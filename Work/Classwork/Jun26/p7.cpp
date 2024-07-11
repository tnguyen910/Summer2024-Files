#include <iostream>
using namespace std;

int main() {
        string s;
        cout << "Enter a string: ";
        getline(cin, s);
        s = s + " ";
        string returnString;
        bool beginningOfString = true;
        bool activeSubString = false;
        int subStrStart; //x is "beginning" of the working string, y is the "end"
        for (int i = 0; i <= s.size(); i++) {
            if (isspace(s[i])) {
                if (beginningOfString || !activeSubString) {
                    continue;
                }
                if (returnString != ""){
                    returnString = " " + returnString;
                }
                returnString = s.substr(subStrStart, i-subStrStart) + returnString;
                activeSubString = false;
                continue;
            }
            else if (!activeSubString) {
                beginningOfString = false;
                subStrStart = i;
                activeSubString = true; 
            }
            else { continue; }
        }
        cout << returnString;
    }