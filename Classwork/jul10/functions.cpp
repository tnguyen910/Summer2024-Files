#include "functions.h"
#include <iostream>


std::vector<int> buildNumsVec(int n, std::string prompt = ""){
    std::cout << prompt << std::endl;
    std::vector<int> out;
    for (int i = 0; i<n; i++) {
        std::cout << "Input number (" << n << "): ";
        int in;
        std::cin >> in;
        out.push_back(in);
    }
    return out;

}
void fillNumsArray10(int arr[10], std::string prompt){
    std::cout << prompt << std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout << "Input number (" << i << "): ";
        int in;
        std::cin >> in;
        arr[i] = in;
    }
}

int problem5(int arr[10]) {
    
    int max = arr[0];
    int sum = arr[0];
    for (int i = 1; i < 10; i++) {
        if (arr[i] > max ) {
            max = arr[i];
        }
        sum+=arr[i];
    }
    return sum = max;
}

void problem3(int arr[10]) {

    int out[10];

    for (int i = 0; i < 10; i+=2 ) {
        if (arr[i] >= arr[i+1]) {
            out[i] = arr[i+1];
            out[i+1] == arr[i];
        }
        else {
            out[i] = arr[i];
            out[i+1] == arr[i+1];
        }
    }

    std::cout << out[1];
    
}

int secondLargest(int arr[10]) {
    int largest;
    int secondLargest;

    largest = (arr[0]>arr[1]) ? arr[0] : arr[1];
    secondLargest = (arr[0]>arr[1]) ? arr[1] : arr[0];

    for (int i = 2; i < 10; i++) {

        if (arr[i] < largest && arr[i] > secondLargest) {
            secondLargest = arr[i];
        }
        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        }

    }
    return secondLargest;
}


bool sameElements(std::vector<int> arr1, std::vector<int> arr2, std::string prompt) {
    std::cout << prompt;
    for (int i = 0; i<arr1.size(); i++) {
        for (int j = 0; j<arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                arr2.erase(arr2.begin()+j); // if this is an array and not a vector, 
                break; 
            }
        }
    }
    return (arr2.size() == 0) ? true : false;
}

bool sameElementsNoErase(std::vector<int> arr1, std::vector<int> arr2, std::string prompt) {
    bool hasElement = true;
    std::cout << prompt;
    for (int i = 0; i<arr1.size(); i++) {
        bool hasElement = false;
        for (int j = 0; j<arr2.size(); j++) {
            if (arr1[i] == arr2[j]) {
                hasElement = true;
                break; 
            }
        }
        if (!hasElement) {
            return false;
        }

    }
    return true;
}