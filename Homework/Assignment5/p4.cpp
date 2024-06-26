#include <iostream>
using namespace std;

int main() {
    cout << "Pick an operation: " << endl;
    cout << "1: Addition" << endl;
    cout << "2: Subtraction" << endl;
    cout << "3: Multiplication" << endl;
    cout << "4: Division" << endl;
    cout << "Pick an operation by inputting a number: ";

    bool valid = false;

    int operation;

    while (!valid) {
        cin >> operation;

        if (operation > 0 && operation < 5){
            valid = true;
            break;
        }
        cout << "Invalid selector, try again: ";
    }

    int x, y;

    cout << "Enter 2 numbers in the order of operation (ex: 1, 2 for 1 + 2 for addition): ";
    cin >> x >> y;
    bool divideByZero;

    if (y==0 && operation ==4) {
           divideByZero = true;
    }

    while (divideByZero) {
        if (y == 0) {
            cout << "Invalid second number! Try again: ";
            cin >> y;
        }
    }

    switch (operation){
        case 1:
        cout << x + y;
        break;
        case 2:
        cout << x - y;
        break;
        case 3:
        cout << x*y;
        break;
        case 4:
        cout << x/y;
        break;
    }

}