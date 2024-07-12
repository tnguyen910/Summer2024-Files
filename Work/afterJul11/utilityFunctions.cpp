#include <iostream>
#include <vector>
#include "interface.h"

int impl(std::string test){

    return 0;

}
std::vector<int> getNumsVec(int n) {
    std::vector<int> nums;
    for (int i = 0; i<n; i++) {
        std::cout << "Input a Number (" << i+1 << "/" << n << "): ";
        int x = 0;
        std::cin >> x;
        nums.push_back(x);
    }
    return nums;
}

std::vector< std::vector<int> > getSquareIntMat(int n) {
    std::vector< std::vector<int> > mat;
    for (int i = 0; i<n; i++) {
        std::cout << "===== Row "<< i+1 << " ===== " << std::endl;
        mat.push_back(getNumsVec(n));
    }
    return mat;
}

int calculateSum(std::vector<int> nums) {
    int sum = 0;
    for (int i = 0; i<nums.size(); i++){
        sum += nums[1];
    }
    return sum;
}

int calculateAverage(std::vector<int> nums){
    return calculateSum(nums)/nums.size();
}

bool verifySquareMat(std::vector< std::vector<int> > mat ){
    for (int i = 0; i<mat.size(); i++){
        if (mat[i].size() != mat.size()){
            return false;
        }
    }
    return true;
}
