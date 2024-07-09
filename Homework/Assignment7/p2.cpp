#include <iostream>
using namespace std;

int main() {
    cout << "Input a string: ";
    string str;
    getline(cin, str);

    int uppercase = 0;
    int lowercase = 0;
    int digits = 0;
    int spaces = 0;

    for (int i = 0; i < str.length(); i++) {
        if (str[i]>= 65 && str[i] <= 90 ) {
            uppercase++;
        }
        if (str[i]>=97 && str[i]<=122) {
            lowercase++;
        }
        if (str[i]==' ') {
            spaces++;
        }
        if (str[i] >= 48 && str[i] <= 57) {
            digits++;
        }
    }
    cout << "Uppercase: " << uppercase << ", Lowercase: " << lowercase << ", Digits: " << digits << ", Spaces: " << spaces << endl;
}