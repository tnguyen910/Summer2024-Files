#include <iostream>
using namespace std;

int main() {
    int n;

    while(true) {
        cout << "Input number of rows: ";
        cin >> n;
        if (n < 27 && n > 0) {
            break;
        }
        cout << "Invalid! (0 < n < 27) " << endl;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j<i; j++) {
            char out = 'A' + i-1;
            cout << out;
        }
        cout << endl;
    }



}
