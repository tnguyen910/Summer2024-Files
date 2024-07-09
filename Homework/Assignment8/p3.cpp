#include <iostream>
using namespace std;

int main() {
    string str = "";
    char ch; 
    cout << "Input a string: ";
    getline(cin, str);
    cout << "Input a character you want to find in the string: ";
    cin >> ch;

    string returnStr = "";

    for (int i = 0, j = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            j++;
            continue;
        }
        if (str[i] == ch) {
            cout << "Your character appears in word " << (j+1) << " of the sentence" << endl;
            return 0;
        }
    }

    


}