#include<iostream>

using namespace std;

int main() {

	int no = 11;

	int i;

	for(i=2;i<=no-1; i++) {
		if(no%i == 0) {
			break;		
		}
	}

	// if(i == no) { 
	// 	cout << "Prime !" << endl;
	// }  else {
	// 	cout << "Not a prime!" << endl;
	// }

	i == no ? cout << "Prime !" << endl : cout << "Not a prime !" << endl;


	return 0;
}