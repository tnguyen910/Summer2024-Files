#include <iostream>
using namespace std;

int main() {
    int maxQtyNum = 6;

    int numbers [maxQtyNum];
    for (int i = 0; i < maxQtyNum; i++) {
        cout << "Enter a number (Index " << (i+1) << "): " ;
        cin >> numbers[i];
    }

    int sum;
    for (int i = 0; i < maxQtyNum; i++) {
        sum += abs(numbers[i]);
    }

    cout << "The absolute sum is: " << sum << endl;  
}