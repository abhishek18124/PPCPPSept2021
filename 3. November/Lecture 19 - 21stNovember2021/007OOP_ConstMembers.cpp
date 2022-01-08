#include<iostream>
#include<cstring>

using namespace std;

class customer {

public:

	int age;
	string name; // member object
	const int userId;
	static int count;


	customer(int age, string name, int userId) : userId(userId){
		count++;
		cout << "\nI am inside a parameterised constructor\n" << endl;
		this->age = age;
		this->name = name;
		// this->userId = userId; // error, const members must be initialised
	}	

	void printCustomerInfo() const {
		cout << "\nCustomer Info\n";
		cout << "Name : " << this->name << endl; 
		cout << "Age : " << this->age << endl;
		cout << "ID : " << this->userId << endl; 
	}

	// bool operator==(customer c) {
	// 	return this->age == c.age;
	// }
};

bool operator==(customer c1, customer c2) {
	return c1.age == c2.age;
}

int customer::count = 0;

int main() {

	customer c1(21, "Tarun", 123);
	c1.printCustomerInfo();

	const customer c2(24, "Rohit", 345);

	if(c1 == c2) { // c1.operator==(c2)
		cout << "same age" << endl;
	} else {
		cout << "different age" << endl;
	}

	return 0;
}