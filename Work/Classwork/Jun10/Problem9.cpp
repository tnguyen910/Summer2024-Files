#include <iostream>

int main() {
    int x;

    std::cout << "Input an integer: ";
    std::cin >> x;

    int output = x%10;
    std::cout << "The last digit is: " << output << std::endl;
    return 0;

} 