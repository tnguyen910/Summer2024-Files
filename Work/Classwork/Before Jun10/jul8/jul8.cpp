#include <iostream>
#include "functions.h"
using namespace std;

int main() {
    int f = findWord("racecar", "ace");

    if (f != -1) {
        cout << "true, index (start from 0): " << f;
    }
    else {
        cout << "false";
    }
    cout << endl;
}