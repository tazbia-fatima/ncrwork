#include<iostream>
using namespace std;
class Time1{
	int hours, mins, secs;
public:
	Time1() {
		hours = mins = secs = 0;
	}
	Time1(int h, int m, int s) {
		hours = h;
		mins = m;
		secs = s;
	}
	void display_time() {
		cout<< "Time is - " << hours << ":" << mins << ":" << secs<<endl;
	}
	void add_time(Time1 t1, Time1 t2) {
		int x;
		x = t1.secs + t2.secs;
		if (x >= 60) {
			mins = t1.mins+t2.mins + (x / 60);
			secs = x % 60;

		}
		else
			secs = x; 
		if (mins >= 60) {
			hours = t1.hours + t2.hours + (mins / 60);
			mins = mins % 60;
		}
		else {
			hours = t1.hours + t2.hours;
			mins = t1.mins + t2.mins;
		}
	}
};

int main() {
	int x, y, z;
	cout<<"Enter the values of hrs, mins and seconds"<<endl;
	cin >> x >> y >> z;
	Time1 t1(12,35,12), t2(x,y,z),t3;
	t1.display_time();
	t2.display_time();
	t3.add_time(t1, t2);
	t3.display_time();
	cin >> x;
	return 0;
}