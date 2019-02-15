#include<iostream>
#include<math.h>
using namespace std;
class Matrix {
	int rows, cols, **p;
public:
	Matrix() {
		rows = cols = 0;
		p = NULL;
	}
	Matrix(int r,int c) {
		rows = r;
		cols = c;
		p = (int **)malloc(sizeof(int*)*r);
		for (int i = 0; i < r; i++) {
			p[i] = (int *)malloc(sizeof(int)*c);
		}
	}
	void set_matrix() {
		cout << "Enter the no of rows of matrix:\n";
		cin >> rows;
		cout << "Enter the no of columns of matrix:\n";
		cin >> cols;
		p = (int **)malloc(sizeof(int*)*rows);
		for (int i = 0; i < rows; i++) {
			p[i] = (int *)malloc(sizeof(int)*cols);
		}
		cout << "Enter the matrix:\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cin >> *(*(p + i) + j);
			}
		}
	}
	void display() {
		cout << "The matrix is :\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				cout << *(*(p+i)+j);
				cout << "\t";
			}
			cout << "\n";
		}
	}
	friend Matrix matrix_multipli(Matrix, Matrix);
};
Matrix matrix_multipli(Matrix m1, Matrix m2) {
	Matrix res(m1.cols,m2.rows);
	int sum=0;
	//cout << "XX";
	if (m1.cols != m2.rows) {
		//cout << "YYY";
		cout << "Multiplication not valid";
		res.rows = 0;
		res.cols = 0;
		return (res);
	}
	else {
		//cout << "XXX";
		for (int i = 0; i < res.rows; i++) {
			//cout << "1st for";
			for (int j = 0; j < res.cols; j++) {
				//cout << "2nd for";
				for (int k = 0; k < m2.rows; k++) {
					sum += (*(*(m1.p + i) + k))*(*(*(m2.p + k) + j));
				}
				*(*(res.p + i) + j) = sum;
				sum = 0;
			}

		}
		return (res);
	}
}

int main() {
	Matrix m1, m2, res;
	int x;
	m1.set_matrix();
	m1.display();
	m2.set_matrix();
	m2.display();
	res = matrix_multipli(m1,m2);
	res.display();
	cin >> x;
	return 0;
}


