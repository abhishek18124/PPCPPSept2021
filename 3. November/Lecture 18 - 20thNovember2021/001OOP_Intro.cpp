#include<iostream>
#include<cstring>

using namespace std;

class customer {

public:

	int age;
	char gender;
	double credits;
	char name[100];

	void printCustomerInfo() {

		cout << "\nCustomer Info\n";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl; 

	}
}c3, c4, c5;



void printCustomerInfo(customer c) {

	cout << "\nCustomer Info\n";
	cout << "Name : " << c.name << endl;
	cout << "Age : " << c.age << endl;
	cout << "Gender : " << c.gender << endl;
	cout << "Credits : " << c.credits << endl; 

}

int main() {

	customer c1; // declaration

	// assignment

	c1.age = 10;
	c1.gender = 'M';
	c1.credits = 0;
	strcpy(c1.name, "Teevra");

	c1.printCustomerInfo();

	// printCustomerInfo(c1);

	// cout << "\nCustomer Info\n";
	// cout << "Name : " << c1.name << endl;
	// cout << "Age : " << c1.age << endl;
	// cout << "Gender : " << c1.gender << endl;
	// cout << "Credits : " << c1.credits << endl; 

	customer c2;

	c2.age = 20;
	c2.gender = 'O';
	c2.credits = 100;
	strcpy(c2.name, "Janghu");

	// cout << "\nCustomer Info\n";
	// cout << "Name : " << c2.name << endl;
	// cout << "Age : " << c2.age << endl;
	// cout << "Gender : " << c2.gender << endl;
	// cout << "Credits : " << c2.credits << endl; 

	// printCustomerInfo(c2);

	c2.printCustomerInfo();

	return 0;
}