/*

Given a phone keypad as shown below, and an n digit number, print all words which are possible by 
pressing the n digits on the keypad.

 1()     2(abc) 3(def) 
 4(ghi)  5(jkl) 6(mno)
 7(pqrs) 8(tuv) 9(wxyz)

*/

#include<iostream>

using namespace std;

string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void pressKeypad(char* inp, int i, char* out, int j) {
    // base case
    if(inp[i] == '\0') {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // recursive case

    // you're at the ith digit of inp, and you need to decide the character with which 
    // you want to map the ith digit

    int digit = inp[i] - '0';
    // string options = keypad[digit];
    // for(int k=0; k<options.length(); k++) {
    //     char c_k = options[k];
    //     out[j] = c_k;
    //     pressKeypad(inp, i+1, out, j+1);
    // }

    if(digit == 0 || digit == 1) {
        // you can skip this digit and directly move to the next digit in the input sequence
        pressKeypad(inp, i+1, out, j);
        return;
    }

    for(char c_k : keypad[digit]) {
        out[j] = c_k;
        pressKeypad(inp, i+1, out, j+1);
    }
}

int main() {
	
    char inp[] = "12";
    char out[10];

    pressKeypad(inp, 0, out, 0);

	return 0;
}
