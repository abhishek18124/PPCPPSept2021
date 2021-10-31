/*

Given a string (sequence of characters) of length n, generate all of its permutations. 

Example
	
	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<cstring>

using namespace std;

void generatePermutations(char* inp, int i) {
	// base case
	if(inp[i] == '\0') {
		cout << inp << endl;
		return;
	}

	// recursive case

	for(int j=i; j<strlen(inp); j++) {
		swap(inp[i], inp[j]);
		generatePermutations(inp, i+1);
		swap(inp[i], inp[j]); // backtracking step : to restore the original 
							  // state of my string before the next swap
	} 

}

int main() {

	char inp[] = "abc";

	generatePermutations(inp, 0);

	return 0;
}
