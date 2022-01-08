#include<iostream>
#include<cstring>

using namespace std;

class customer {

	int age;
	char gender;
	double credits;
	char name[100];

public:

	customer(int a, char g, double c, char* n) {
		cout << "\nI am inside a parameterised constructor\n" << endl;
		age = a;
		gender = g;
		credits = c;
		strcpy(name, n);
	}	

	void printCustomerInfo() {

		cout << "\nCustomer Info\n";
		cout << "Name : " << name << endl;
		cout << "Age : " << age << endl;
		cout << "Gender : " << gender << endl;
		cout << "Credits : " << credits << endl; 
	}

	void setAge(int a) {
		age = a;
	}

	int getAge() {
		return age;
	}
};


int main() {

	customer c1(21, 'M', 100, "Pratik");

	c1.setAge(19);

	cout << c1.getAge() << endl;

	return 0;
}