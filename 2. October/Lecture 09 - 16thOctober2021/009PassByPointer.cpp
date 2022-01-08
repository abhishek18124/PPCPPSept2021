#include<iostream>

using namespace std;

void incrementByValue(int a) {
  a++;
}

void incrementByReference(int& a) {
  a++;
}

void incrementByPointer(int* aptr) {
  (*aptr)++;
}

int main() {
  
  int a = 10;
  incrementByValue(a);
  cout << a << endl;
  incrementByReference(a);
  cout << a << endl;
  incrementByPointer(&a);
  cout << a << endl;
  
  return 0;
}