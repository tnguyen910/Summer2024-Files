#include <iostream>

int main() {
    std::cout << "How old are you? ";
    int age;
    std::cin >> age;

    if (age > 64) {
        std::cout << "Senior" <<std::endl;
        return 0;
    }
    if (age > 19) {
        std::cout << "Adult" << std::endl;
        return 0;
    }
     if (age > 12) {
        std::cout << "Teenager" << std::endl;
        return 0;
    }
    if (age > 0) {
        std::cout << "Child";
        return 0;
    }
    std::cout << "Not a valid age!" << std::endl;
    return 0;
}