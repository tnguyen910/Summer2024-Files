#include <iostream>
using namespace std;

int main() {
    cout << "How many terms of the fibonacci sequence do you want?  Input: ";
    int terms;
    cin >> terms;

    int previous = 0;
    int current = 1;

    for ( int i = 0; i < terms; i++) {
        if ( i == 0 ){
            cout << 0 << " ";
            continue;
        }
        current = current + previous; 
        previous = current - previous;
        cout << current << " ";
    }
}