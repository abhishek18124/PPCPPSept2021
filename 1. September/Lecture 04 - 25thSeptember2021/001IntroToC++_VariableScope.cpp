#include<iostream>

using namespace std;

int x = 10;

int main() {

	cout << x << endl;

	int x = 20;

	cout << x << endl;

	int y = 30;

	{
		
		cout << x << endl;

		int x = 30;

		{
			int x = 40;

			cout << y << endl;
		}

		cout << ::x << endl;

	}

	return 0;
}