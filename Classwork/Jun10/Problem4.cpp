#include <iostream>

int main() {

    float r;
    std::cout << "What is the radius of your sphere: ";
    float volume = (4/3)*3.14*r*r*r;
    std::cout << volume << std::endl;
    return 0;
}