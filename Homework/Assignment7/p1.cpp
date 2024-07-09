#include <iostream>
using namespace std;

int main() {
    cout << "Input an integer: ";
    int x;
    cin >> x;
    bool prime = true;
    for (int i = 2; i < x; i++){
        if (x%i == 0) {
            prime = false;
            cout << "Your integer is not a prime" << endl;
            break;
        }
    }
    cout << "Your integer is a prime" << endl;

}