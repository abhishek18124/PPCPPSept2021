#include<iostream>
#include<cstring>

using namespace std;

class customer {

public:

	int age;
	char gender;
	double credits;
	char* name;

	customer() {
		cout << "\nI am inside the default constructor\n" << endl;
	}

	customer(int a, char g, double c, char* n) {
		cout << "\nI am inside a parameterised constructor\n" << endl;
		age = a;
		gender = g;
		credits = c;
		name = new char[strlen(n)+1];
		strcpy(name, n);
	}

	customer(customer& c) {
		cout << "\nI am inside a copy constructor\n" << endl;
		name = new char[strlen(c.name)+1];
		strcpy(name, c.name);
		age = c.age;
		gender = c.gender;
		credits = c.credits;
	}

	void operator=(customer c) {
		cout << "\nI am inside a copy assignment operator function\n" << endl;
		name = new char[strlen(c.name)+1];
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

	~customer() {
		cout << "I am inside the " << name << "'s destructor" << endl;
		delete name;
	}
};


int main() {

	customer c1(20, 'F', 100, "Riya");

	c1.printCustomerInfo(); // it will invoke the parameterised constructor

	customer c2(c1); // it will invoke the default copy constructor

	c2.printCustomerInfo();

	strcpy(c2.name, "abc");

	cout << "c2.name = " << c2.name << endl;
	cout << "c1.name = " << c1.name << endl;

	return 0;
}