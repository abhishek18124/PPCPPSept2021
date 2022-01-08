#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	int age;
	string name; // member object
	
	customer(int age, string name) {
		this->age = age;
		this->name = name;
	}	
};

bool myComparator(customer c1, customer c2) {
	return c1.name < c2.name;
}

int main() {

	vector<customer> v;
	
	customer c1(21, "Tarun");
	customer c2(18, "Teevra");
	customer c3(19, "Rohan");
	customer c4(20, "Aryan");

	v.push_back(c1);
	v.push_back(c4);
	v.push_back(c2);
	v.push_back(c3);
	
	sort(v.begin(), v.end(), myComparator);

	for(auto c : v) {
		cout << c.age << " " << c.name << endl;
	}

	return 0;
}