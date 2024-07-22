#ifndef INTERFACE_H
#define INTERFACE_H
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

//Add Functions
int impl(std::string test);
int calculateSum(std::vector<int>);
int calculateAverage(std::vector<int>);
std::vector<int> getNumsVec(int n);
bool verifySquareMat(std::vector< std::vector<int> > mat );
std::vector< std::vector<int> > getSquareIntMat(int n);


#endif
