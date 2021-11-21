#include<iostream>
#include<cstring>

using namespace std;

class customer {

public:

	int age;
	string name; // member object
	static int count;
	
	customer() {
		count++;
		cout << "\nI am inside a default constructor\n" << endl;	
	}

	customer(int age, string name) {
		count++;
		cout << "\nI am inside a parameterised constructor\n" << endl;
		this->age = age;
		this->name = name;
	}	

	void printCustomerInfo() {
		cout << "\nCustomer Info\n";
		cout << "Name : " << this->name << endl; 
		cout << "Age : " << this->age << endl; 
	}

	bool isSameObject(customer* cptr) {
		return this == cptr;
	}

	static void f() {
		cout << count << endl;
	}

};

int customer::count = 0;

int main() {

	customer c1;
	customer c2;
	customer c3;

	// cout << c1.count << endl << c2.count << endl << c3.count << endl;

	cout << customer::count << endl;

	customer::f();

	return 0;
}