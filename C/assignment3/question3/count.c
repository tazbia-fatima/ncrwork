#include<stdio.h>

void main()
{
	int n, bin[8] = { 0 }, n2, i = 7, c = 0;
	printf("Enter a number between 1 and 255\n");
	scanf("%d", &n);
	if (n > 0 && n < 256)
	{
		while (n > 0)
		{
			n2 = n % 2;
			bin[i--] = n2;
			n = n / 2;
			if (n2)
				c++;
		}
		printf("binary equivalent is\n");
		for (i = 0; i < 8; i++)
		{
			printf("%d", bin[i]);
		}
		printf("\n Number of 1's are %d", c);
	}
	else
	{
		printf("Entered number not in range");
	}
	scanf("%d", &i);
	getchar();
}