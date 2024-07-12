#include <iostream>
#include <vector>
#include "interface.h"

int utilityFunctions::impl(std::string test){

    return 0;

}
std::vector<int> utilityFunctions::getNumsVec(int n) {
    std::vector<int> nums;
    for (int i = 0; i<n; i++) {
        std::cout << "Input a Number (" << i+1 << "/" << n << "): ";
        int x = 0;
        std::cin >> x;
        nums.push_back(x);
    }
    return nums;
}
