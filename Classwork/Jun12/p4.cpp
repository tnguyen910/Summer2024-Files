#include <iostream>

int main() {
    std::cout << "Input a number: ";
    int x;
    std::cin >> x;
    if  (x>10) {
        std::cout << "The number is greater than 10" << std::endl ;
    }
    if  (x<10) {
        std::cout << "The number is less than 10" << std::endl ;
    }
    else {
        std::cout << "They are equal" << std::endl;
    }
    
    return 0;
}