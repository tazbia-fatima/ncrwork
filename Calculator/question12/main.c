#include<stdio.h>
#include<math.h>
void rotate_right(int, int);
void main() {
	int n = 0, b = 0;
	printf("Enter the number and the value of the position b");
	scanf_s("%d\n%d", &n, &b);
	rotate_right(n, b);
	scanf_s("%d", &n);
	getchar();
}
void rotate_right(int n, int b) {
	long int mul, num, num2, res, count;
	mul = pow(10, b);
	num = n % mul;
	num2 = n / mul;
	count = log10(num2)+1;
	/*while (n != 0) {
		n = n / 10;
		count+=1;
	}*/
	res = num *pow(10, count) + num2;
	printf("The rotated result is %ld", res);
}