#include <iostream>


/*5. Write a C++ program that receives a number from the user and prints out its remainder to 2 on the screen. You can use % operator to calculate the remainder to a number. For example 109 % 2 will give us the remainder of 109 to 2 which is equal to 1. */
int main() {
    int x; 
    std::cout << "Give me a number:";
    std::cin >> x;
    int output = x%2;
    std::cout << output << std::endl;
    return 0;
}