#include <iostream>
using namespace std;

int main() {
    int numbers[10];
    cout << "Input 10 numbers: ";
    for (int i = 0; i < 10; i++){
        cout << "Input (" << i+1 << "): ";
        cin >> numbers[i];
    }
    
    bool ascending = true;
    bool descending = true;

    for (int i = 1; i < 10; i++) {
        if (numbers[i] < numbers[i-1]) {
            ascending = false;
        }
        if (numbers[i] > numbers[i-1]) {
            descending = false;
        }
        if (!ascending && !descending) {
            cout << "Shuffled!" << endl;
            return 0;
        }
    }

    if (ascending) {
        cout << "Ascending!" << endl;
    }
    if (descending) {
        cout << "Descending!" << endl;
    }
}