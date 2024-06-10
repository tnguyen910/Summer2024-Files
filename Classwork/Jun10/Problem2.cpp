#include <iostream>

int main() {
    float price;

    std::cout << "Input item price: " << std::endl ;
    std::cin >> price;

    float output = price*1.09;
    std::cout << output << std::endl;
    return 0;
}