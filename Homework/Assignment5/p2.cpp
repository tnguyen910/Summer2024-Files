#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Input a number";
    cin >> number;

    bool positive = false;
    bool even = false;

    if (number%2 == 0) {
        even = true;
    }

    if (number > 0) {
        positive = true;
    }

    if (number == 0) {
        cout << "Neither Positive Nor Negative";
    }

    if (even) {
        cout << "Even";
        return 0;
    }

    cout << "Odd";
    return 0;

}