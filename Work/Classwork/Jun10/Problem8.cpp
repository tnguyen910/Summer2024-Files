#include <iostream>

int main() {

    std::cout << "Input a double: ";

    double input;
    std::cin >> input;

    double output = input - int(input);
    std::cout << "Just the decimal on the input is: " << output << std::endl;
    return 0;
}