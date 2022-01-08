#include<iostream>
#include<cstring>

using namespace std;

class customer {

public:

	int age;
	string name; // member object
	
	customer() {
		cout << "\nI am inside a default constructor\n" << endl;	
	}

	customer(int age, string name) {
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

};


int main() {

	customer c(21, "Tarun");
	c.printCustomerInfo();

	c.isSameObject(&c) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}