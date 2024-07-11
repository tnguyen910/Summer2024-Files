#include <iostream>


void problem1() {
    std::string name;
    std::cout << "Enter name";
    std::cin >> name;
    std::cout << "Hello " << name << std::endl;
    return;
    }

void problem2() {
    std::string x, y;
    std::cout << "Enter your 2 strings: ";
    std::cin >> x >> y;
    std::string concat = x + y;
    std::cout << concat << std::endl;
    return;
}

void problem3() {
    // std::string x = "x";
    // int y = 1;
    // std::cout << x + y;

    std::string a = "a";
    std::string b = "b";
    std::cout << a+b;

    int u = 1;
    int v = 2;
    std::cout << u + v;
}

void problem4() {

    std::string input;
    std::cout << "Enter string";
    std::cin >> input;
    std::cout << "String length: " << input.length() << std::endl;
    return;
}

void problem5() {
    std::string input;
    std::cout << "Enter string";
    std::cin >> input;
    std::cout << "String chars 1, 2, and last: " << input[1] << input[2] << input[input.length()-1] << std::endl;
    return;
}

void problem6() {
    std::string str;
    char ch;
    int index;
    std::cout << "Enter string: ";
    std::cin >> str;
    std::cout << "Enter index you'd like to replace (0-indexed): ";
    std::cin >> index;
    std::cout << "Enter replacement character: ";
    std::cin >> ch;

    std::string output = str.substr(0,index) + ch + str.substr(index + 1);

    std::cout << "New string: " << output << std::endl;
    return;
}

int main() {
    int i = 0;
    while (i < 100) {
        int x;
        std::cout << "Which problem do you want to run (0 to exit): ";
        std::cin >> x;
        switch(x) {
            default: std::cout << "Not a function" << std::endl; break;
            case 0: return 0;
            case 1: problem1(); break;
            case 2: problem2(); break;
            case 3: problem3(); break;
            case 4: problem4(); break;
            case 5: problem5(); break;
            case 6: problem6(); break;
        }
        i++;
    }
}