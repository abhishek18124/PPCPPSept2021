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
		cout << "\nI am inside a parameterised constructor 1\n" << endl;
		age = a;
		gender = g;
		credits = c;
		strcpy(name, n);
	}	

	customer(int a, char g, double c) {
		cout << "\nI am inside a parameterised constructor 2\n" << endl;
		age = a;
		gender = g;
		credits = c;
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

	customer c1; // it will invoke the default constructor

	customer c2(20, 'F', 100, "Riya");

	c2.printCustomerInfo(); // it will invoke the 1st parameterised constructor

	customer c3(30, 'M', 500);

	c3.printCustomerInfo(); // it will invoke the 2nd parameterised constructor

	return 0;
}