#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input number of rows: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 1; j<i; j++) {
            cout << j;
        }
        for (int j = i; j>0; j--) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}
