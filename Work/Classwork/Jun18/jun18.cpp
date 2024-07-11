#include <iostream>

//loops

void problem1() {
    for(int i = 0; i < 10; i++) {
        std::cout << i+1 << std::endl;
    }
    return;
}

void problem2() {
    for(int i = 0; i < 10; i++) {
        std::cout << 10-i << std::endl;
    }
    return;
    }

void problem3() {
    for(int i = 2; i < 20; i+=2) {
        std::cout << (i) << std::endl;
    }
    return;
}

void problem4() {
    for(int i = 0; i < 10; i++) {
        std::cout << (i+1)*(i+1) << std::endl;
    }
    return;
}

void problem5() {
    for(int i = 8; i*7 < 200; i++) {
        std::cout << (i*7) << std::endl;
    }
    return;
}

void problem6() {
    int sum = 0;
    for(int i = 0; i < 51; i++) {
        if ((i)%2==0) {
            sum += i;
        }
    }
    std::cout << sum << std::endl;
    return;
}

void problem7() {
    int sum = 0;
    for(int i = 0; i < 100; i++) {
        if (i%3==0 && i%5==0) {
            // debug std::cout << i << std::endl;
            sum += i;
        }
    }
    std::cout << sum << std::endl;
    return;
}

void problem8() {
    int max;
    std::cout << "Input a number: ";
    std::cin >> max; 
    for(int i = 0; i < max; i++) {
        std::cout << i+1 << std::endl;
    }
    return;
}

void problem9() {
    int num;
    std::cout << "Input a number: ";
    std::cin >> num; 
    for(int i = 0; i < 10; i++) {
        std::cout << num*(i+1) << std::endl;
    }
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
            case 7: problem7(); break;
            case 8: problem8(); break;
            case 9: problem9(); break;
        }
        i++;
    }
}