#include<iostream>
using namespace std;

class polar {
	float angle, radi;
public:
	static int count;
	polar() {
		angle = radi = 0;
		count++;
	}
	polar(float a,float r) {
		angle = a;
		radi = r;	
		count++;
	}
	~polar() {
		count--;
	}
};
int polar::count;
int main() {
	float a, r;
	cout << "Enter angle and radius";
	cin >> a;
	cin >> r;
	polar p1(a,r), p2;
	cout << "\nthe no.of active objects are :" << polar::count;
	{
		polar p3;
		cout << "\nthe no.of active objects are :" << polar::count;

	}
	cout << "\nthe no.of active objects are :" << polar::count;

	cin >> a;

	return 0;
}