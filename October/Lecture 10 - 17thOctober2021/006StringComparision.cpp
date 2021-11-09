#include<iostream>
#include<cstring>

using namespace std;

int stringCompare(char* str1, char* str2) {
	int i = 0;
	int j = 0;

	int m = strlen(str1);
	int n = strlen(str2);

	while(i < m && j < n) {
		if(str1[i] == str2[j]) {
			i++;
			j++;
		} else  {
			if(str1[i] > str2[j]) {
				return 1;
			} else {
				return -1;
			}
		}
	}

	if(i == m && j == n) {
		// both the string have the same length
		return 0;
	} else if(i < m) {
		// str2 is completely exhaused, and str1 still has some characters therefore str1 > str2
		return 1;
	} else {
		// str1 is completely exhaused, and str2 still has some characters therefore str1 < str2
		return -1;
	}

}

int main() {

	char str1[] = "abc";
	char str2[] = "abc";

	// here, pointers to the first characters are compared and not the content
	// of the array that is why we are getting output as "No they are not equal"

	// if(str1 == str2) {
	// 	cout << "Yes they are equal!" << endl;
	// } else {
	// 	cout << "No they are not equal" << endl;
	// }

	cout << strcmp(str1, str2) << endl; // output is 0 when equal, 1 when str1 > str2, -1 when str1 < str2
										   // comparision is done lexicographically

	cout << stringCompare(str1, str2) << endl;

	return 0;
}