#include <iostream>

int main() {
    std::cout << "What day number is it (Monday is day 1): ";
    int day;
    std::cin >> day;
    if (day<=0) {
        std::cout <<"not a valid day" << std::endl;
        return 0;
    }
    if (day%7 == 0 or day%7 == 6) {
        std::cout << "It is a weekend" << std::endl;
        return 0;
    }

    std::cout << "It is a weekday!" << std::endl;
    return 0;
}