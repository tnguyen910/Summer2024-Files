#include <iostream>
#include "interface.h"
#include "problems.h"
using namespace std;

int main() {
    utilityFunctions u;
    arrays2 a;
    std::vector<int> nums = u.getNumsVec(5);
    a.problem1(nums);

    return 0;
}
