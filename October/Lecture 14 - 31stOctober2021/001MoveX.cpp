/*

Given a string str, design a recursive algorithm to move all the occurrence of letter x 
to the end of the string str.

Example 
	Input : str = "axbcxdxfx"
	Output: str = "abcdfxxxx"

	Input : str = "xabcxdxfx"
	Output: str = "abcdfxxxx"

*/

#include<iostream>

using namespace std;

string f(string str) {

	if(str.empty()) {
		return str;
	}

	// extract the character at the 0th idx
	string firstChar = str.substr(0, 1); // firstChar = str[0]

	string subString = str.substr(1);
	string subStringFromMyFriend = f(subString);

	if(firstChar == "x") {
		// append firstChar to the end of subStringFromMyFriend
		return subStringFromMyFriend + firstChar;
	} else {
		// preprend firstChar to the beginning of subStringFromMyFriend
		return firstChar + subStringFromMyFriend;
	}
}

int main() {

	string str = "axbx";

	cout << f(str) << endl;
  	
	return 0;
}
