#include <iostream>

int main() {
    float x, y, z;
    std::cout << "Enter a number (x): ";
    std::cin >> x;

    std::cout << "Enter a number (y): ";
    std::cin >> y;

    std::cout << "Enter a number (z): ";
    std::cin >> z;

    float output = (x+y+z)/3;
    std::cout << output << std::endl ;
    return 0;
}