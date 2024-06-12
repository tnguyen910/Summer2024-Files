#include <iostream>

int main() {
    std::cout << "How many units of electricity did you use: ";
    float units, cost;
    std::cin >> units;

    if (units >= 100) {
        cost = 0.12*100;
        cost += (units-100)*0.15;
        std::cout << "Cost: " << cost << std::endl;
        return 0;
    }
    cost = 0.12*units;
    std::cout << "Cost: " << cost << std::endl;
    return 0;
}