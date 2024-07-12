#include "interface.h"
#include "problems.h"
#include <iostream>


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

void arrays2::problem1(std::vector<int> nums1) {
    std::cout << "Sum: " << calculateSum(nums1) << std::endl;
    std::cout << "Mean: " << calculateAverage(nums1) << std::endl;
}
