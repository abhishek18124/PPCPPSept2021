#include<iostream>
#include<cstring>
#include<climits>

using namespace std;

int main() {

	int maxLength = INT_MIN; // or 0 since length of the str is non-negative
	char maxString[100];
	char temp[100];

	int n;
	cin >> n;

	cin.ignore(); // to ignore the \n after n

	int i = 0;

	while(i < n) {
		cin.getline(temp, 100);
		if(int(strlen(temp)) > maxLength) {
			maxLength = strlen(temp);
			strcpy(maxString, temp);
		}
		i++;
	}

	cout << maxString << " " << maxLength << endl;



	return 0;
}