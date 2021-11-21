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

	customer(int a, string n) : age(a), name(n) {
		cout << "\nI am inside a parameterised constructor\n" << endl;
	}	

	void printCustomerInfo(c) {
		cout << "\nCustomer Info\n";
		cout << "Name : " << name << endl; 
		cout << "Age : " << age << endl; 
	}

};


int main() {

	customer* cptr1 = new customer;	
	customer* cptr2 = new customer(20, "Tushar");

	cout << "cptr2->age = " << cptr2->age << endl;
	cout << "cptr2->name = " << cptr2->name << endl;

	delete cptr1;
	delete cptr2;

	return 0;
}