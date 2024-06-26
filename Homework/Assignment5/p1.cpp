#include <iostream>
using namespace std;

int main() {

    bool validShape = false;
    bool validCalc = false;
    string shape;
    string calc;

    while (!validShape) {
        cout << "What shape do you want to calculate (lowercase): ";
        cin >> shape;
        if (shape != "triangle" || shape!= "square" || shape!="circle") {
                cout << "Invalid shape name!";
                continue;
            }
            validShape = true;
        }

    while (!validCalc) {
        cout << "Do you want to calculate area or perimeter? (lowercase): ";
        cin >> calc;
        if (calc != "area" || calc != "perimeter") {
                cout << "Invalid calculation type!";
                continue;
            }
            validCalc = true;
        }

    if (shape == "triangle") {
        if (calc == "perimeter"){
            cout << "Enter your 3 side lengths: ";
            int a, b, c;
            cin >> a >> b >> c;
            cout << a+b+c << endl;
            return 0;
        }
        if (calc=="area") {
            cout << "What are your base and height?";
            int b, h;
            cin >> b >> h;
            cout << 0.5*b*h << endl;
            return 0;
        }
    }

    if (shape == "square") {
        cout << "Enter your side length: ";
        int a;
        cin >> a;

        if (calc == "perimeter"){
            cout << 4*a << endl;
            return 0;
        }
        if (calc=="area") {
            cout << a*a << endl;
            return 0;
        }
    }
    if (shape == "circle") {
        cout << "Enter radius: ";
        int a;
        cin >> a;

        if (calc == "perimeter"){
            cout << 3.14*2*a << endl;
            return 0;
        }
        if (calc=="area") {
            cout << 3.14*a*a << endl;
            return 0;
        }
    }
} 
   
    