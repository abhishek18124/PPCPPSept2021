#include<iostream>

using namespace std;

int main() {

	int no = 8;

	int i;

	for(i=2;i<no; i++) {
		if(no%i == 0) {
			cout << "Not a prime !" << endl;
			break;		
		}
	}

	if(i == no) { 
		cout << "Prime !" << endl;
	}


	return 0;
}