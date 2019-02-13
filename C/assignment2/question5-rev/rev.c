#include<stdio.h>
#include<math.h>

int main()
{
	int n, temp = 0, r, len;
	printf("enter the number to reverse\n");
	scanf("%d", &n);
	len = log10(n) + 1;
	while (n != 0)
	{
		r = n % 10;
		n = n / 10;
		temp = temp + (r*pow(10, len));
		len--;

	}
	temp = temp / 10;
	printf("Reverse is %d", temp);

	getchar();
	return 0;
}