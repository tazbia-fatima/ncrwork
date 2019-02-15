#include<iostream>
using namespace std;
class Complex {
	float real;
	float img;
public:
	Complex() {
		real = img = 0;
	}
	Complex(float r) {
		real = img = r;
	}
	Complex(float r, float i) {
		real = r;
		img = i;
	}
	void display() {
		cout << real << "+" << img << "i";
	}
	friend Complex add_refe(Complex &c1, Complex &c2);
	friend Complex multi_refe(Complex &c1, Complex &c2);
};
int main() {
	Complex c1(2.1), c2(5.0,2), c3, c4;
	char a;
	c3 = add_refe(c1, c2);
	c4 = multi_refe(c1, c2);
	cout << "c1 is :";
	c1.display();
	cout << "\nc2 is :";
	c2.display();
	cout << "\nThe addition res is : ";
	c3.display();
	cout << "\nThe multiplication res is : ";
	c4.display();
	cin >> a;
	return 0;
}
Complex add_refe(Complex &c1, Complex &c2) {
	Complex res;
	res.real = c1.real + c2.real;
	res.img = c1.img + c2.img;
	return res;
}
Complex multi_refe(Complex &c1, Complex &c2) {
	Complex res;
	res.real = c1.real * c2.real;
	res.img = c1.img * c2.img;
	return res;
}