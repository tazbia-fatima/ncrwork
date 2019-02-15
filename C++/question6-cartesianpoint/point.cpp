#include<iostream>
#include<math.h>
using namespace std;
class Point {
	int x, y;
public:
	void set_pt(int x1, int y1) {
		x = x1;
		y = y1;
	}
	friend void distance_pt(Point p1, Point p2);
};
int main() {
	Point p1, p2;
	int x, y;
	float distance;
	cout << "Enter values of first point\n";
	cin >> x;
	cin >> y;
	p1.set_pt(x, y);
	cout << "Enter values of second point\n";
	cin >> x;
	cin >> y;
	p2.set_pt(x, y);
	//cout << "PT2" << x << y;
	distance_pt(p1, p2);
	cin >> x;
	return 0;

}
void distance_pt(Point p1, Point p2){
	int x1,y1;
	float dis=0;
	x1 = p1.x - p2.y; 
	y1 = p1.y - p2.y;
	dis = sqrt((pow(x1, 2) + pow(y1, 2)));
	cout << "The distance between p1(" << p1.x << "," << p1.y << ") and p2(" << p2.x<<"," << p2.y << ") is = " << dis;
}