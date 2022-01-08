#include<iostream>
#include<cstring>

using namespace std;

class customer {

public:

	int age;
	char gender;
	double credits;
	char name[100];

	customer() {
		cout << "\nI am inside the default constructor\n" << endl;
	}

	customer(int a, char g, double c, char* n) {
		cout << "\nI am inside a parameterised constructor\n" << endl;
		age = a;
		gender = g;
		credits = c;
		strcpy(name, n);
	}

	customer(customer& c) {
		cout << "\nI am inside a copy constructor\n" << endl;
		strcpy(name, c.name);
		age = c.age;
		gender = c.gender;
		credits = c.credits;
	}

	void operator=(customer c) {
		cout << "\nI am inside a copy assignment operator function\n" << endl;
		strcpy(name, c.name);
		age = c.age;
		gender = c.gender;
		credits = c.credits;
	}

	void printCustomerInfo() {

		cout << "\nCustomer Info\n";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl; 
	}
};


int main() {

	customer c1(20, 'F', 100, "Riya");

	c1.printCustomerInfo(); // it will invoke the parameterised constructor

	customer c2;

	// c2 = c1;

	c2.operator=(c1);

	c2.printCustomerInfo();

	return 0;
}