#include<iostream>
#include<cstring>

using namespace std;

bool isPalindrome(char* str) {
	int i = 0;
	int j = strlen(str) - 1;

	while(i < j) {
		if(str[i] != str[j]) {
			return false;
		}

		i++;
		j--;

		// if(A[i] == A[j]) {
		// 	i++;
		// 	j--
		// } else {
		// 	return false;
		// }
	}

	return true;
}

int main() {

	char str[] = "madam";

	isPalindrome(str) ? cout << "\"" << str << "\"" << " is a palindrome" << endl : 
	                    cout << str << " is not a palindrome" << endl;
	                    
	                    
	return 0;
}