#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	string str;

	str = "Hello World";

	cout << str.length() << endl;
	cout << str.size() << endl;

	string str1("Hello");
	string str2("World");

	str1 += str2; // str1 = str1 + str2
	// str1.append(str2);

	cout << str1 << endl;

	str1 = "a";
	str2 = "z";
	cout << str1.compare(str2) << endl;

	cout << (str1 > str2) << endl;

	str1 = "hello llo world";
	cout << str1.find("llo") << endl;
	cout << str1.rfind("llo") << endl;
	cout << str1.find("abc") << endl;
	cout << string::npos << endl;

	if(str1.find("llo") != string::npos) {
		cout << "Present";
	} else {
		cout << "Not Present";
	}
 
	cout << str1.substr(10) << endl;
	cout << str1.substr(10, 2) << endl;

	string s("helloWorld");

	reverse(s.begin(), s.end());

	cout << s << endl;

	char* ch_s = (char *)s.c_str();
	cout << ch_s << endl;

	
}