#include<iostream>
// #define PI 3.14
// #define PRINT cout<<
// #define NEWLINE endl
// #define SEMICOLON ;
// #define F(n) for(int i=0; i<n; i++) {PRINT i << NEWLINE SEMICOLON}
#define F(n, m) for(int i=0; i<n; i++) {for(int j=0; j<m; j++) {cout << i << j << " ";} cout << endl;}


using namespace std;

int main() {

	// int r = 10;

	// cout << 2 * PI * r << endl;
	// PRINT 2 * PI * r << NEWLINE;
	// F(10)

	// for(int i=0; i<5; i++) {for(int j=0; j<5; j++) {cout << i << j << " ";}cout << endl;}

	F(5, 5);

	return 0;
}