#include<iostream>
using namespace std;
	void swap_value(int a,int b) {
		a = a + b;
		b = a - b;
		a = a - b;
	}
	void swap_reference(int &a, int &b) {
		a = a + b; b = a - b;
		a = a - b;
	}
int main() {
	int a, b, x;
	cout << "Enter the values of a and b";
	cin >> a >> b;
	cout << "Original values : a : " << a << " and b : " << b;
	do {
		cout << "\nMenu :\n1)Swap by value\n2)Swap by reference\nEnter choice\n";
		cin >> x;
		switch (x)
		{
		case 1: {
			swap_value(a, b);
			cout << "Post swap by value" << endl << "a:" << a << "and b:" << b;
			break;
		}
		case 2: {
			swap_reference(a, b);
			cout << "Post swap by reference" << endl << "a:" << a << "and b:" << b;
			break;
		}
		default: {
			cout << "Invalid choice.Press -1 to exit";
			break; }
		}
		cout << "\nEnter 0 to select again and -1 to exit";
		cin >> x;
	} while (x == 0);
	return 0;
}