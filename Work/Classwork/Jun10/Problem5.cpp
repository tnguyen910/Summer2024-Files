#include <iostream>

int main() {
    float degreesFahrenheit;
    std::cout << "What is the temperature in Fahrenheit: ";
    std::cin >> degreesFahrenheit;

    float degreesCelcius = (degreesFahrenheit-32) * (5.0/9);
    std::cout << degreesCelcius << std::endl;
    return 0;
}