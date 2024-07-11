#include <iostream>
using namespace std;
//Floyd's Triangle
int main() {
    int n = 0;
    cout << "Input Number of Rows: ";
    cin >> n;
    int j = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < i+1; k++){
            cout << j+1 << " ";
            j++;
        }
        cout << endl;
    }
    return 0;
}
