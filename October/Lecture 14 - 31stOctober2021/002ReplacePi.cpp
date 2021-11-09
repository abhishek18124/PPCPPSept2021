/*

Given string str of size n, design a recursive algorithm to replace all occurrences of pi 
with 3.14 in the given string and print the modified string.

Example : 
	Input : inp[] = "pippppiiiipi"
	Output: out[] = "3.14ppp3.14iii3.14"

	Input : inp[] = "pip"
	Output: out[] = "3.14p"

	Input : inp[] = "xpix"
	Output: out[] = "x3.14x"

*/

#include<iostream>

using namespace std;

void f(char* inp, int i) {
	// base case
	if(inp[i] == '\0') {
		return;
	}

	// recursive case

	// you're standing at the ith character and you've check first if (i, i+1)th match with "pi"
	if(inp[i] == 'p' && inp[i+1] == 'i') {
		// replace (i, i+1)th with "3.14", to do this, first shift all the characters
		// starting from the (i+2)th 2 steps to the right

		int j = i+2;
		while(inp[j] != '\0') {
			j++;
		}

		while(j >= i+2) {
			inp[j+2] = inp[j];
			j--;
		}

		inp[i] = '3';
		inp[i+1] = '.';
		inp[i+2] = '1';
		inp[i+3] = '4';

		f(inp, i+4);
	} else {
		f(inp, i+1);
	}
}

int main() {

	char inp[100] = "xpix";

	f(inp, 0);

	cout << inp << endl;

	return 0;
}
