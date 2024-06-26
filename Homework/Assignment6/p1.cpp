#include <iostream>
using namespace std;

int main() {
    int maxQtyNum = 20;

    int numbers [maxQtyNum];
    for (int i = 0; i < maxQtyNum; i++) {
        cout << "Enter a number (Index " << (i+1) << "): " ;
        cin >> numbers[i];
    }

    int divByThree = 0;
    int divByFive = 0;

    for (int i = 0; i < maxQtyNum; i++) {
        if (numbers[i]%3 == 0) {
            divByThree ++;
        } 
        if (numbers[i]%5 == 0) {
            divByFive++;
        }
    }

    if (divByThree > divByFive) {
        cout << "More numbers are divisible by three!";
    }
    else if (divByFive > divByThree) {
        cout << "More numbers are divisible by five!";
    }
    else if (divByFive == divByThree) {
        cout << "There are an equal amount of numbers divisible by three and five!";
    }
    else {
        cout << "Something went wrong!";
    }
    cout << endl;
}