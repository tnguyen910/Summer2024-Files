#include <iostream>

int main() {
    float x, y;
    std::cout << "Side Length 1: ";
    std::cin >> x;

    std::cout << "Side Length 2: ";
    std::cin >> y;

    float output = x*y;
    std::cout << output << std::endl ;
    return 0;
}