#include <iostream>
#include <string>
using namespace std;

char toUpper(char ch) {
    if (ch >= 97 && ch <= 122 ){
        return ch-32;
    }
    return ch;
}

int main(){
    string input;

    cout << "Input your names: ";
    getline(cin, input);

    int priorityIndex; //Store index of first character in the name

    for (int i = 0; i < input.size(); i++){ //logic to handle alphabetical order
        cout << "Iteration: "<< i << ", PriorityIndex: " << priorityIndex << ", Current Letter:  " << input[i] << endl; //DEBUG STATEMENT: Check prio index
        if (i == 0){ // Handle first iteration
            priorityIndex = i;
            continue;
        }
        if (input[i-1] == ' ') {  // Check if previous char was a space, indicating beginning of new name
            char current = toUpper(input[i]);
            if (toUpper(input[priorityIndex]) >= current){ //If character is same or earlier in alphabet, execute comparison
                int j = 0;
                while (true) { // loop through each of the words until hitting a space ( handled later) -> note, if the characters are the same, nothing happens counter is just increased
                    cout << "Iteration (In nested loop): "<< i+j << ", PriorityIndex: " << priorityIndex << ", Current Letter:  " << input[i+j] << endl;
                    if (toUpper(input[i+j]) < toUpper(input[priorityIndex+j])) { // if the new word's current character is earlier in alphabet, break the loop, set priorityIndex, increase i & break
                        priorityIndex = i;
                        break;
                    }
                    else if (toUpper(input[i+j]) > toUpper(input[priorityIndex+j])) { // if current is not prioritized, break with no change
                        break;
                    }

                    bool wordEnd = false;
                    if (toUpper(input[i+j+1]) == ' ' && i+j+1 <= input.size()){ //handle word end, if characters are the same, shorter word is prioritized
                        priorityIndex = i;
                        j++; //remedial counter increase because checking j+1
                        wordEnd = true;
                    } else if (toUpper(input[priorityIndex+j+1]) == ' ') {
                        j++;
                        wordEnd = true;
                    }

                    j++; //increase counter

                    if (wordEnd) {
                        break;
                    }
                }
                i+=j; //skip already checked characters
            }
        }
    }

    int i = priorityIndex;
    string out = "";
    while(input[i] != ' ' && i <= input.size()){ // build the output string
        out+=input[i];
        i++;
    }

    cout << out << endl;

    return 0;

}
