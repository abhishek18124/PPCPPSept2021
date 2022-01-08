#include<iostream>
#include<cstring>

using namespace std;

int main() {

	char str[] = "ab$c.def.gh/i//j#k";
	char dl[] = ".$#/";

	char* token = strtok(str, dl);
	cout << token << endl;

	while(token != NULL) {
		token = strtok(NULL, dl);
		cout << token << endl;
	}
 
	return 0;
}