#include<stdio.h>

void main()

{

	int n, sum = 0;

	printf("Enter the number\n");
	scanf_s("%d", &n);

	while (n>0) {

		sum += n % 10;

		n = n / 10;

	}

	printf("The sum of digits is %d", sum);

	scanf_s("%d", &sum);
	getchar();

}