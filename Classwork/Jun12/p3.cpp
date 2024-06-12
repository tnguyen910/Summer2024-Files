#include <iostream>

int main() {
    std::cout << "Input 2 numbers: ";
    int x, y;
    std::cin >> x >> y;
    if  (x>y) {
        std::cout << x << std::endl ;
    }
    if  (x<y) {
        std::cout << y << std::endl ;
    }
    else {
        std::cout << "They are equal" << std::endl;
    }
    
    return 0;
}