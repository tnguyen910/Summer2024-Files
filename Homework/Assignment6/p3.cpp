#include <iostream>
using namespace std;

int main() {
    int maxQtyNum = 5;

    int numbers [maxQtyNum];
    for (int i = 0; i < maxQtyNum; i++) {
        cout << "Enter a number (Index " << (i+1) << "): " ;
        cin >> numbers[i];
    }

    int sum;
    for (int i = 0; i < maxQtyNum; i++) {
        if (numbers[i] > 0) {
            sum += numbers[i];
        }
    }

    cout << "The sum of positive numbers is: " << sum << endl;  
}