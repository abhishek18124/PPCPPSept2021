/*

	Implement a phonebook storing mapping between person's name and their phone numbers 
	using an unordered_map.

*/

#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phonebook;

	phonebook["Abhishek"].push_back("999366996");
	phonebook["Abhishek"].push_back("123456788");

	phonebook["Bhavya"].push_back("12344556677");
	phonebook["Pratik"].push_back("12329482494");

	for(auto p : phonebook) {
		cout << p.first << " : ";
		for(auto x : p.second) {
			cout << x << " ";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}