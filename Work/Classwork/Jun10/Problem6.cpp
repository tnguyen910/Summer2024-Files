#include <iostream>





int swapVariables(int x, int y) {
    std::cout << "Original x: " << x << std::endl;
    std::cout << "Original y:" << y << std::endl;

    x = x + y; /* => x = 3 */
    y = -(y-x); /* => y = 1*/
    x = x-y; /* => x = 2*/

    std::cout << "new x value: " << x << std::endl;
    std::cout << "new y value: " << y << std::endl;
    return 0;
}
int inputSwapVariables() {
    int x, y;
    std::cout << "Input a number x:";
    std::cin >> x;
    std::cout << "Input a number y:";
    std::cin >> y; 

    swapVariables(x, y);

    return 0;
}

int main() {
    inputSwapVariables();

    std::cout << "Test cases" << std::endl; 
    swapVariables(43, 54);
    swapVariables(57, 23);
    swapVariables(102356, 30);
    return 0;

}