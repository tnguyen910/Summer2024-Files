#include <iostream>
using namespace std;

int main() {
    int random = rand()%100 + 1;
    int guess;
    do {
        guess;
        cout << "What is your guess? ";
        cin >> guess;

        if (guess == random){
            cout << "You got it!";
        }
        if (guess > random) {
            cout << "Too high!";
        }
        if (guess < random) {
            cout << "Too low!";
        }
    } while (guess != random); 
}