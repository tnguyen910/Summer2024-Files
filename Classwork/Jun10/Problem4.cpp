#include <iostream>
#include <cmath>

int main() {
    double r;
    std::cout << "What is the radius of your sphere: ";
    std::cin >> r;
    double volume = 4.0/3.0 * M_PI * (r*r*r);
    std::cout << volume << std::endl;
    return 0;
}