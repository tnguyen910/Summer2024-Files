#include <iostream>

int main() {
    std::cout << "Input a character: ";
    char x;
    std::cin >> x;
    if  (x=='a' or x=='A') { // ASCII codes for A and a respectively
        std::cout << "The character is a" << std::endl;
        return 0;
    }
    std::cout << "This character is not a" << std::endl ;
    
    return 0;
}