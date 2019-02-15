#include<iostream>
using namespace std;
inline float addi(int a, int b) {
	return a + b;
  }
inline float subb(int a, int b) {
	return a - b;
}
inline float multi(int a, int b) {
	return a * b;
}
inline float divi(int a, int b) {
	return a / b;
}
int main() {
	int a, b,op,x;
	float res;
	cout << "Enter a and b\n";
	cin >> a;
	cin >> b;
	do{
	cout << "\nMenu:\n1)Add\n2)Subtract\n3)multiply\n4)Divide\nEnter choice";
	cin >> op;
		switch (op) {
		case 1: {res = addi(a, b);
			cout << "Result is :" << res;
			break; }
		case 2: {res = subb(a, b);
			cout << "Result is :" << res;
			break; }
		case 3: {res = multi(a, b);
			cout << "Result is :" << res;
			break; }
		case 4: {res = divi(a, b);
			cout << "Result is :" << res;
			break; }
		default: {cout << "Invalid choice";
			break; }
		}
		cout << "\nEnter 0 to operate again";
		cin >> x;
	} while (x == 0);
			 cin >> op;
			 return 0;
}