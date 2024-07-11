#include <iostream>
using namespace std;


string p10() {
    string str;
    string returnString;
    cout << "Input a string: ";
    getline(cin, str);

    for (int i = 0; i < str.length(); i++) {
        if (i != str.find(str[i])) {
            continue;
        }
        returnString += str[i];

    }

    return returnString;
}

string p11(string str) {
    string out = "";

    for (int i = 0; i < str.length(); i++) {
        bool toAppend = true;
        for (int j = i+1; j < str.length(); j++) {
            if (str[i] > str[j]) {
                toAppend = false;
                break;
            }
        }
        if (toAppend) {
            out += str[i];
        }
    }
    return out;

}

bool p12(string word1, string word2) {

    bool isAnagram = true;
    if (word1.length() != word2.length()){
        return false;
    }
    for (int i = 0; i < word1.size(); i++) {

        bool letterPresent = false;
        for (int j = 0; j < word2.size(); j++ ) {
            if (word1[i] == word2[j]) {
                string placeholder = "";
                for(int k = 0; k < word2.size(); k++) {
                    if (k != j) {
                        placeholder += word2[k];
                    }
                }
                word2 = placeholder;
                letterPresent = true;
                break;
            }
        }
        if (!letterPresent) {
            return false;
        }
    }
    return true;

}

string getString() {
    cout << "Input a String: ";
    string out;
    getline(cin, out);
    return out;
}

int getInt() {
    cout << "Input an integer: ";
    int out;
    cin >> out;
    return out;
}

int main() {
    cout << "Case 1" << endl << "Word1: knee, Word2: keen";
    if(p12("race", "care")==true){
        cout <<  "Success" << endl;
    } else {cout << "Failed" << endl;}

    cout << "Case 2" << endl << "Word1: knee, Word2: keen";
    if(p12("knee", "keen")==true){
        cout <<  "Success" << endl;
    } else {cout << "Failed" << endl;}

    return 0;
}

