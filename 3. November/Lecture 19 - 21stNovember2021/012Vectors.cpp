/*
	
	Vectors Part II
	
	How to create a vector ? 
		> use fill constructor
		> use range constructor
		> use copy constructor
		> use initialiser list (C++11)
	How to add elements to a vector ?
	    > use vector::insert
	      > single element
	      > fill
	      > range
	      > initialiser list
	How to remove elements from a vector ?
	    > use vector::erase
	      > single element
	      > range

	How to sort a vector ?
      > use built-in comparator
      > use user-defined comparator
      > pass in reverse order

*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	vector<int> v1(10, 100);

	for(int i=0; i<v1.size(); i++) {
		cout << v1[i] << " ";
	}

	cout << endl;

	// copy constructor
	vector<int> v2(v1); // vector<int> v2 = v1
	
	// copy assignment operator
	vector<int> v3;
	v3 = v1;

	// range constructor
	vector<int> v4(v1.begin()+1, v1.end());

	return 0;
}






