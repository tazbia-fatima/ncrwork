#include<stdio.h>

int main()

{

	int temp, num = -1, rev = 0, rem;

	printf("Enter any number:\n");

	scanf_s("%d", &num);

	temp = num;

	while (temp>0)

	{

		rem = temp % 10;

		rev = rev * 10 + rem;

		temp = temp / 10;

	}

	if (rev == num)

	{

		printf("%d is a palindrome\n", num);

	}

	else

	{
		printf("%d is not a palindrome\n", num);
	}

	scanf_s("%d", &num);
	getchar();
	return 0;

}