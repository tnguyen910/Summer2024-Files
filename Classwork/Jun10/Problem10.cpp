#include <iostream>

int main() {
    int x;

    std::cout << "Input an integer: ";
    std::cin >> x;

    int output = int((x%1000)/100);
    std::cout << "The 3rd to last digit is: " << output << std::endl;
    return 0;

} 