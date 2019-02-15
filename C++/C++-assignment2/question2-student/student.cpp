#include<iostream>
using namespace std;
class STUDENT {
	int rollno, marks[10], tot_m;
	char name[100], grade;
public:
	istream& operator >> (STUDENT &s) 
	{
		cout << "Enter student roll no";
		cin >> s.rollno;
		cout << "Enter student name";
		cin >> s.name;
		cout << "Enter student grade";
		cin >> s.grade;

	}
};
int main() {
	STUDENT s1;
	cin >> s1;
	return 0;
}