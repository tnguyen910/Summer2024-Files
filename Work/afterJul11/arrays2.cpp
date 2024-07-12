#include "interface.h"
#include "problems.h"
#include <iostream>


void arrays2::problem1(std::vector<int> nums1) {
    std::cout << "Sum: " << calculateSum(nums1) << std::endl;
    std::cout << "Mean: " << calculateAverage(nums1) << std::endl;
}

void arrays2::problem2(std::vector< std::vector<int> > mat) {
    if (!verifySquareMat(mat)){
        std::cout << "Not a square matrix!" << std::endl;
        return;
    }
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[i].size(); j++){
            if (j == i) {
                std::cout << " " << mat[i][j] << " ";
            } else {
                std::cout << " 0 ";
            }
        }
        std::cout << std::endl;
    }
}
