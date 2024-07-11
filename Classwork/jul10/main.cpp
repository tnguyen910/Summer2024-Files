#include <iostream>
#include "functions.h"
using namespace std;

int main() {

    vector<int> arr1;
    vector<int> arr2;

    for (int i = 0; i < 5; i++) {
        arr1.insert(arr1.begin()+i, i);
        arr2.push_back(i);
    }

    if (sameElementsNoErase(arr1, arr2)) {
        cout << "Contains Both";
    }
    else {
        cout << "Does not Contain Both";
    }

    cout << endl;

}

//g++ player.cpp main.cpp -o main.out && ./main.out