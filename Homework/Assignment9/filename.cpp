#include <iostream>
using namespace std;


//Floyd's Triangle
int main() {
    int n = 4;

    for (int i = 0; i < n; i++) {
        int j;
        for (int k = 0; k < i; k++){
            cout << j << " ";
            j++;
        }
        cout << endl;
    }
}
