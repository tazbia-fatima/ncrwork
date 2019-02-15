#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
using namespace std;
class Student {
	char *studentName, *grade;
	int marks[3];
public:
	void set_Data(const char *sname, char *grade1, int marks1[3]) {
		int l;
		l = strlen(sname);
		studentName = (char *)malloc(sizeof(char)*l);
		strcpy(studentName, sname);
		l = strlen(grade1);
		grade = (char *)malloc(sizeof(char)*l);
		strcpy(grade, grade1);
		for (int i = 0; i < 3; i++) {
			marks[i] = marks1[i];
		}
	}
	float calculateAverage() {
		float avg;
		avg = (marks[0] + marks[1] + marks[2]) / 3;
		//cout << "Average is:" << avg << endl;
		cout << "Avg is :" << avg;
		return avg;
	}
	void ComputeGrade(float avg) {
		if (avg > 60) {
			grade = "First Class";
		}
		else if (50 < avg < 60) {
			grade = "Second Class";
		}
		else if (40 < avg < 50) {
			grade = "Third Class";
		}
		else
			grade = "Fail";
		cout << "Grade is:" << grade;
	}
	void display() {
		cout << "Student Details :" << endl;
		cout << "Name :" << studentName << endl << "Grade :" << grade << endl << "Marks :";
		cout << "\tMarks 1:" << marks[0] << "\tMarks 2:" << marks[1] << "\tMarks 3:" << marks[2];
	}
};

int main() {
	Student s1;
	float avg;
	int marks[3];
	char grade1[100];
	/*cout << "With hard coded values";
	marks[0]=50;
	marks[1] = 33;
	marks[2] = 99;
	s1.set_Data("Tazbia Fatima", "Uncomputed", marks);
	avg=s1.calculateAverage();
	s1.ComputeGrade(avg);
	s1.display();*/
	//TO take values from user
	char sname[100];
	int x,y;
	cout << "Menu:" << endl << "1)Set Data\n2)Calculate Average\n3)ComputeGrade\n4)Display";
	do {
		cout << "\nEnter option";
		cin >> x;
		switch (x)
		{
		case 1: {
			cout << "Enter details-name,grade,marks[3]\n";
			cin >> sname;
			cin >> grade1;
			cin >> marks[0];
			cin >> marks[1];
			cin >> marks[2]; //sname and grade are char *
			s1.set_Data(sname, grade1, marks);
			s1.display();
			break;
		}
		case 2: {
			avg = s1.calculateAverage();
			break; }
		case 3: {
			avg = s1.calculateAverage();
			s1.ComputeGrade(avg);
			break; }
		case 4: {
			s1.display();
			break; }
		default: {cout << "Enter valid choice";
			break; }
		}
		cout<<"\nEnter 0 to select another option";
		cin >> y;
	} while (y == 0);
			cin >> avg;
			return 0;
}