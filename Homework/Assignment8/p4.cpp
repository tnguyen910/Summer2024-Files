#include <iostream>
using namespace std;

int main() {
    cout << "Input as string: ";
    string str;
    getline(cin, str);

    for (int i = str.length()-1; i > 1; i-- ){
        if (str[i]==' '){
            cout << str.substr(i+1, str.length()-(i+1)) << endl;
            return 0;
        }
    }
}