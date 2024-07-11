#include <iostream>
#include <string>

int main() {
    std::cout << "Input a character: ";
    char s;
    std::cin >> s;

    /* while (s.size() != 1) {
        std::cout << "String size is not 1! Input a character: ";
        std::cin >> s;
    }*/
    
    int output = int(s);

    std::cout << "This is the Ascii Code for the character: " << output << std::endl;
    return 0;
}