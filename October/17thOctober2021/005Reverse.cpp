#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

void reverse(char* str) {
	int i = 0;
	int j = strlen(str)-1;

	while(i < j) {
		swap(str[i], str[j]);
		i++;
		j--;
	}
}

int main() {

	char str[] = "hello world";

	cout << "Before reverse  = " << str << endl;

	reverse(str);

	cout << "After 1st reverse = " << str << endl;

	strrev(str);

	cout << "After 2nd reverse = " << str << endl;

	reverse(str, str+strlen(str)); // function overloading

	cout << "After 3rd reverse = " << str << endl;

	int A[] = {1, 2, 3};
	int n = sizeof(A) / sizeof(int);

	reverse(A, A+n);

	for(int i=0; i<n; i++) {
		cout << A[i] << " ";
	}

	cout << endl;

	return 0;
}