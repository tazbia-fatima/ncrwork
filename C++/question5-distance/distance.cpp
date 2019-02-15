#include<iostream>
using namespace std;
class Distance2;
class Distance1 {
	int meter;
	int centimeter;
public:
	void set_d1(int m, int cm) {
		meter = m;
		centimeter = cm;
	}
	friend void add_distance(Distance1 d1, Distance2 d2);
};
class Distance2 {
	int feet;
	int inches;
public:
	void set_d2(int f, int in) {
		feet = f;
		inches = in;
	}
	friend void add_distance(Distance1 d1, Distance2 d2);
};
int main() {
	Distance1 d1;
	Distance2 d2;
	int x, y;
	cout << "Enter values of first distance in meters and centimeters\n";
	cin >> x;
	cin >> y;
	d1.set_d1(x, y);
	cout << "Enter values of second distance in feet and inches\n";
	cin >> x;
	cin >> y;
	d2.set_d2(x, y);
	add_distance(d1, d2);
	cin >> x;
	return 0;
	
}
void add_distance(Distance1 d1, Distance2 d2) {
	int op;
	cout << "\nMenu :\n1)Result of addition in meters and centimeters\n2)Result of addition in Feet and Inches\nEnter Choice:";
	cin >> op;
	switch (op)
	{
	case 1: 
	{
		d2.feet = d2.feet*0.3048; //convert ft to m
		d2.inches = d2.inches*2.45; //convert inches to cm
		if (d2.inches > 100) { //to check if cms are more than 1m
			d2.feet = d2.feet + (d2.inches / 100);
			d2.inches = (d2.inches % 100); //use modf for floating values
		}
		//d1 is used to store result. it is local
		d1.meter = d1.meter + d2.feet; //addition of meters
		d1.centimeter = d1.centimeter + d2.inches; //addition of cm
		if (d1.centimeter > 100) {  //to check if cms are more than 1m
			d1.meter = d1.meter + (d1.centimeter / 100);
			d1.centimeter = (d1.centimeter % 100);
		}
		//gives integer rounded off output
		cout << "\nThe result is: " << d1.meter << "m and " << d1.centimeter << "cm\n";
		break;
	}
	case 2: {
		d1.meter = d1.meter*3.2808; //convert m to ft
		d1.centimeter = d1.centimeter*0.39; //convert cm to in
		if (d1.centimeter > 12) { //to check if inches more than 2 feet
			d1.meter = d1.meter + d1.centimeter / 12;
			d1.centimeter = d1.centimeter % 12;
		}
		//d2 is used to store result. it is local 
		d2.feet = d2.feet + d1.meter; //addition of feet
		d2.inches = d2.inches + d1.centimeter; //addition of inches of distance
		if (d2.inches > 12) { //to check if inches more than 2 feet
			d2.feet = d2.feet + d2.inches / 12;
			d2.inches = d2.inches % 12;
		}
		//gives integer result
		cout << "\nThe result is: " << d2.feet << "ft and " << d2.inches << "in\n";
		break;
	}
	default: {cout << "invalid choice";
		break; }
	}
}