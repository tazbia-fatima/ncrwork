#include<stdio.h>
#include<math.h>

void itob(int n);
void btoi(long n);

void main()
{
	int i, op;
	long b;
	printf("MENU\n1.Enter Decimal to convert to binary\n");
	printf("2.Enter Binary to convert to decimal\n");
	scanf("%d", &op);
	printf("Enter your number\n");
	switch (op) {
	case 1: {scanf("%d", &i);
		itob(i);
		break; }

	case 2: {scanf("%ld", &b);
		btoi(b);
		break; }
	}
	getchar();
}

void itob(int n)
{

	int binaryNum[25];
	int i = 0;
	while (n > 0) {

		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	for (int j = i - 1; j >= 0; j--)
		printf("%d", binaryNum[j]);

}

void btoi(long n)
{

	int decimalNumber = 0, i = 0, remainder;
	while (n != 0)
	{
		remainder = n % 10;
		n /= 10;
		decimalNumber += remainder * pow(2, i);
		++i;
	}
	printf("Decimal number is: %d\n", decimalNumber);
}