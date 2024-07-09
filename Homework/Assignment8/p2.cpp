#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Input a string: ";
    getline(cin, str);
    string returnStr = "";
    while (true) {
        if (str[0] != ' ') { 
            returnStr += str[0]; //Build returnStr
        } else { // Handle Extra Spaces
            str = str.substr(1, str.length()-1);
            continue;
        }

        if (str.find(' ') != std::string::npos){ 
            str = str.substr(str.find(' ')+1, str.length()-str.find(' ')); //Cleave off the first word
        } else { 
            break; //Break loop once there is no more string
        }
    
    }

    cout << returnStr << endl;
}