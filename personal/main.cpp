#include <utility>
#include <string>
#include <unordered_map>
#include <set>
#include <iostream>
using namespace std;



    string countOfAtoms(string formula) {

    set<string> elementsPresent;
    unordered_map<string, int> atoms;
    unordered_map<int, unordered_map<string, int>> levels;

    pair<bool, int> debug;
    int currentLevel = 0;
    int elementsCount = 0;
    int lastNum;
    bool inElement = false; // this keeps track of singular elements
    for (int i = 0; i <= formula.length(); i++ ){
        //keep track if we are "in" an element or not and handle singular elements
        if (formula[i] >= 'A' && formula[i] <= 'Z' || formula[i] == '(' || formula[i] == ')'|| formula[i] == 0){ // check if there is an uppercase
            if (!inElement) {
                lastNum = i-1;
            } else{ // if singular element (as checked by inElement & uppercase)
                string element = formula.substr(lastNum+1, i-lastNum-1);
                if (atoms[element] == 0) {
                    elementsPresent.insert(element);
                    elementsCount++; //indicate addition of new element
                }
                if (currentLevel == 0){
                    atoms[element]++;
                }
                else {
                    levels[currentLevel][element] ++;
                }
                lastNum = i-1;
            }
            inElement = (formula[i] == '(' || formula[i] == ')') ? false : true;

            if (formula[i] == '(' || formula[i] == ')' ) { // handle Parentheses
                if (formula[i] == '(') {
                    currentLevel++;
                    lastNum = i;
                }
                if (formula[i] == ')') {
                    string multiplierStr = "";
                    bool hasNumber = (formula[i+1] >= '0' && formula[i+1] <= '9') ? true : false;
                    multiplierStr = (hasNumber) ? multiplierStr + formula[i+1] : "1";
                    int j = 1;
                    while(formula[i+1+j] >= '0' && formula[i+1+j] <= '9' && hasNumber){
                        multiplierStr+= formula[i+1+j];
                        j++;
                    }
                    i+=j; // this doesn't have the +1 because it gets added at the top of the beginning for loop
                    lastNum = i-1;
                    int multiplier = stoi(multiplierStr);
                    for (pair<string, int> x : levels[currentLevel]){
                        string element = x.first;
                        int qty = x.second;
                        if (currentLevel > 1) {
                            levels[currentLevel-1][element] += multiplier*qty;
                        } else{
                            atoms[element] += multiplier*qty;
                        }
                        levels[currentLevel][x.first] = 0;
                    }
                    currentLevel = (currentLevel == 0 ) ? 0 : currentLevel - 1;
                    if (!hasNumber) {
                        inElement = true;
                        if(formula[i] == '(') {
                            inElement = false;
                        }
                    }
                    // i++;
                }
                continue;

            }

        }
        // THIS HANDLES Non-Parentheses with numbers
        if (formula[i] >= '0' && formula[i] <= '9'){ // search for numbers
            //find the name of the element
            string element = formula.substr(lastNum+1, i-lastNum-1);
            //keep track of how many numbers
            string qtyStr = "";
            qtyStr += formula[i];
            int j = 1;
            while(formula[i+j] >= '0' && formula[i+j] <= '9'){
                qtyStr+= formula[i+j];
                j++;
            }
            i+=j-1;
            //increase already searched, keeps index on number. ex: N4H: index is currently 1 -> stays on 1 which gets increased at top of loop)

            int count = stoi(qtyStr);
            if (atoms[element] == 0) {
                elementsPresent.insert(element);
                elementsCount++; //indicate addition of new element
            }
            if (currentLevel == 0){
                    atoms[element]+= count;
            } else {
                levels[currentLevel][element] += count;
            } // add count of elements set to  respective hashmap
            inElement = false;
        }


    }
    //BUILD OUTPUT strin
    string out = "";
    // Handle carbon and hydrogen since order

    // if (elementsPresent.find("C") != elementsPresent.end()) { // carbon
    //     int currentElementQty = atoms["C"];
    //     string toAppend = (currentElementQty != 1) ? "C"+to_string(currentElementQty) : "C";
    //     out += toAppend;
    // }
    // if (elementsPresent.find("H") != elementsPresent.end()) { //hydrogen
    //     int currentElementQty = atoms["H"];
    //     string toAppend = (currentElementQty != 1) ? "H"+to_string(currentElementQty) : "H";
    //     out += toAppend;
    // }
    // Nvm its not needed lol, its just alphabetical **

    for (string x : elementsPresent){
        // if (x == "H" || x == "C") {
        //     continue;
        // }
        string currentElement = x;
        int currentElementQty = atoms[currentElement];

        string toAppend = (currentElementQty != 1) ? currentElement+to_string(currentElementQty) : currentElement;
        out += toAppend;
    }

    return out;
}

int main() {

    cout << countOfAtoms("Mg(OH)2");
    return 0;
}
