#include "interface.h"
#include "problems.h"
using namespace std;



void executeProblem1(){
    arrays2 a;
    std::vector<int> nums = getNumsVec(5);
    a.problem1(nums);
}

void executeProblem2(){
    arrays2 a;
    a.problem2(getSquareIntMat(5));

}
int main() {
    executeProblem2();
    return 0;
}
