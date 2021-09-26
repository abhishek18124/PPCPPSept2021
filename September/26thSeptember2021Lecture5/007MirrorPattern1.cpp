/*

Write a program to print the following pattern

   *
  ***
 *****
*******
 *****
  ***
   *

here, n i.e. number of rows with increasing pattern is equal to four.

*/

#include<iostream>

using namespace std;

int main() {

   int n = 4;

   // to print upper part of diamond (i.e stars in inc. order)
   for(int i=1; i<=n; i++) {
      // in the ith row, print (n-i) spaces 
      for(int j=1; j<=n-i; j++) {
         cout << " ";
      }

      // followed by (2i-1) *
      for(int j=1; j<=2*i-1; j++) {
         cout << "*";
      }

      cout << endl;
   }

   // to print lower part of diamond (i.e. stars in dec. order)
   for(int i=1; i<n; i++) {
      // in the ith row, print i " " followed by
      for(int j=1; j<=i; j++) {
         cout << " ";
      }

      // 2(n-i)-1 *
      for(int j=1; j<=2*(n-i)-1; j++) {
         cout << "*";
      }

      cout << endl;
   }

	return 0;
}