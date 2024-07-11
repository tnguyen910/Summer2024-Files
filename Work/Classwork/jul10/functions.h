#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <vector>
#include <string>

std::vector<int> buildNumsVec(int n, std::string prompt);

void fillNumsArray10(int n, std::string prompt = "");

void problem3(int arr[10]);

int secondLargest(int arr[10]);

bool sameElementsNoErase(std::vector<int> arr1, std::vector<int> arr2, std::string prompt = "");

bool sameElements(std::vector<int> arr1, std::vector<int> arr2, std::string prompt = "");

#endif
