#include <iostream>


int problem6() {
    std::cout << "Input a character: ";
    char x;
    std::cin >> x;
    if  (x<65 or x>122) { // Alphabet ASCII codes
        std::cout << "The character is not a letter!" << std::endl;
        return 0;
    }

    char vowels[10] = {'a','e','i','o','u','A','E','I','O','U'} ;
    // int vowels[10] = {65, 69, 73, 79, 85, 97, 101, 105, 111, 117} ;

    for (int i = 0; i < 10; i++) {
        if (x==vowels[i]) {
            std::cout << "Your character is a vowel" << std::endl;
            return 0;
        }
    }
    std::cout << "Your character is a consonant." << std::endl; 
    return 0;
}

int problem7() {
    std::cout << "Input 3 numbers: ";
    int x, y, z;
    std::cin >> x >> y >> z;
    int numbers[3] = {x,y,z};
    int max = x;
    for (int i = 0; i<3; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }

    }
    std::cout << "The maximum of the nubmers is " << max << std::endl;
    return 0;

}

int problem8() {
    std::cout << "Input a number: ";
    int x;
    std::cin >> x;
    if (x<0) {
        std::cout << "Your number is negative" << std::endl;
        return 0;
    }
    if (x>0) {
        std::cout << "Your number is positive" << std::endl;
        return 0;
    }
    std::cout << "Your number is neither negative or positive. " << std::endl;
    return 0;
}

int problem9() {
    int x;
    std::cout << "Input a number of your day of the week: ";
    std::cin >> x;
    if (x<0) {
        return 0;
    }
    switch(x%7){
        case(1):
        std::cout << "Sunday" << std::endl;
        break;
        case(2):
        std::cout << "Monday" << std::endl;
        break;
        case(3):
        std::cout << "Tuesday" << std::endl;
        break;
        case(4):
        std::cout << "Wednesday" << std::endl;
        break;
        case(5):
        std::cout << "Thursday" << std::endl;
        break;
        case(6):
        std::cout << "Friday" << std::endl;
        break;
        case(0):
        std::cout << "Saturday" << std::endl;
        break;
    }
    return 0;
}
int problem10() {
    int x;
    std::cout << "Input a number: ";
    std::cin >> x;

    if (x%2 == 0){
        std::cout << "Your number is even" << std::endl;
        return 0;
    }
    std::cout << "Your number is odd" << std::endl;
    return 0;
}

int problem11() {
    int x;
    std::cout << "Input a number of sides: ";
    std::cin >> x;

    switch (x){
        case 1:
        std::cout << "Line";
        break;
        case 2:
        std::cout << "Angle";
        break;
        case 3:
        std::cout << "Triangle";
        break;
        case 4:
        std::cout << "Quadrilateral";
        break;
        case 5:
        std::cout << "Pentagon";
        break;
        case 6:
        std::cout << "Hexagon";
        break;
    }
    if (x>6) { std::cout << "I'm too lazy to code more shapes"; }
    if (x<0) { std::cout << "Less than 0 sides!";}
    std::cout << std::endl;
    return 0; 
}

int problem12() {
    int x;
    std::cout << "Input your menu item number: ";
    std::cin >> x;

    switch (x){
        case 1:
        std::cout << "10";
        break;
        case 2:
        std::cout << "20";
        break;
        case 3:
        std::cout << "30";
        break;
        case 4:
        std::cout << "25";
        break;
        case 5:
        std::cout << "39";
        break;
    }
    if (x>5 or x<0) { std::cout << "Not a menu item"; }
    std::cout << std::endl;
    return 0; 
}

int problem13() {
    int x;
    std::cout << "Input your month number: ";
    std::cin >> x;

    switch (x){
        case 1:
        std::cout << "31";
        break;
        case 2:
        std::cout << "28";
        break;
        case 3:
        std::cout << "31";
        break;
        case 4:
        std::cout << "30";
        break;
        case 5:
        std::cout << "31";
        break;
        case 6:
        std::cout << "30";
        break;
        case 7:
        std::cout << "31";
        break;
        case 8:
        std::cout << "31";
        break;
        case 9:
        std::cout << "30";
        break;
        case 10:
        std::cout << "31";
        break;
        case 11:
        std::cout << "30";
        break;
        case 12:
        std::cout << "31";
        break;

    }
    if (x>12 or x<0) { std::cout << "Not a month"; }
    std::cout << std::endl;
    return 0; 
}

int problem14() {
    int x;
    std::cout << "Input your year: ";
    std::cin >> x;

    if (x%4 != 0) {
        std::cout << "Not a leap year!" << std::endl;
        return 0;
    }
    if (x%400 != 0 && x%100==0) {
        std::cout << "Not a leap year!" << std::endl;
        return 0;
    }
    std::cout << x << " is a leap year." << std::endl;
    return 0;
}

int main() {
    while (true) {
        int x;
        std::cout << "Which problem do you want to run (6-14) choose 0 to end: ";
        std::cin >> x;
        switch(x) {
            case 0:
            return 0;
            case 6:
            problem6();
            continue;
            case 7:
            problem7();
            continue;
            case 8:
            problem8();
            break;
            case 9:
            problem9();
            break;
            case 10:
            problem10();
            break;
            case 11:
            problem11();
            break;
            case 12:
            problem12();
            break;
            case 13:
            problem13();
            break;
            case 14:
            problem14();
            break;

        }

    }
}
