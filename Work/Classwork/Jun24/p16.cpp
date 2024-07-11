#include <iostream>
using namespace std;

int main() {
    int qtyPositive = 0;
    bool positive = false;
    while (!positive) {
        int x;
        cout << "Give me a negative number;";
        cin >> x;
        if (x >= 0) {
            cout << "Not negative!, Try Again";
            qtyPositive++;
            continue;
        }
        cout << "You chose " << qtyPositive << " positive numbers before choosing an negative one!";
        positive = true;
    }
}