#include <iostream>

int main() {
    float base, height;
    std::cout << "What is the length of the base of your triangle: ";
    std::cin >> base;
    std::cout << "\n What is the height of your triangle:";
    std::cin >> height;

    float output = base*height*.5;
    std::cout << output << std::endl;
    return 0;
}