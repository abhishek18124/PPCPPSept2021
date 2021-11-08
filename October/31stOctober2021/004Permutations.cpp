/*

Given a string (sequence of characters) of length n, generate all of its permutations. 

Example
	
	Input : inp[] = "abc"
	Output: ["abc", "acb", "bac", "bca", "cba", "cab"]

*/

#include<iostream>
#include<set>
#include<cstring>

using namespace std;

void generatePermutations(char* inp, int i, set<string>& s) {
	// base case
	if(inp[i] == '\0') {
		string str = string(inp);
		s.insert(str);
		// cout << inp << endl;
		return;
	}

	// recursive case

	for(int j=i; j<strlen(inp); j++) {
		swap(inp[i], inp[j]);
		generatePermutations(inp, i+1, s);
		swap(inp[i], inp[j]); // backtracking step : to restore the original 
							  // state of my string before the next swap
	} 

}

int main() {

	char inp[] = "cba";
	set<string> s;

	generatePermutations(inp, 0, s);

	for(auto str : s) {
		cout << str << endl;
	}

	return 0;
}
