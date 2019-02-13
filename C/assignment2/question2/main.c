#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

void btoh(int n);
void htob(char* n);

void main()
{
	int num, op;
	char hex[10];
	printf("Menu\n1.Binary to Hexa\n");
	printf("2.Hexa to Binary\n");
	scanf("%d", &op);
	switch (op)
	{
	case 1: printf("Enter your binary value\n");
		scanf("%d", &num);
		btoh(num);
		break;

	case 2: printf("Enter your Hexa value\n");
		scanf("%s", hex);
		htob(hex);
		break;
	default: printf("Enter valid choice");
		break;
	}
	getchar();
}

void btoh(int num)
{
	int n, i = 0, j = 0, remainder, decimalNumber = 0;
	char hex[100];


	while (num != 0)
	{
		n = num % 10000;
		//printf("%d\n", n);
		while (n != 0)
		{
			remainder = n % 10;

			n /= 10;
			decimalNumber += remainder * pow(2, i);
			++i;
			//printf("%d", decimalNumber);
		}
		if (decimalNumber > 9)
			decimalNumber = decimalNumber + 55;
		else
			decimalNumber = decimalNumber + 48;

		//printf("\n%c", decimalNumber);
		num = num / 10000;
		hex[j++] = decimalNumber;
		decimalNumber = 0; i = 0;
	}
	for (i = j - 1; i >= 0; i--)
	{
		printf("%c", hex[i]);
	}


}

void htob(char* hex)
{
	int l, i, d, j = 0, x;
	char c;
	int* b;

	l = strlen(hex);
	i = 0;
	b = (int*)malloc(l * 4 * sizeof(int));
	//int b[l][4];
	for (j = 0; j < (l * 4); j++)
	{
		b[j] = 0;
	}
	printf("Length is %d\n", b[(l * 4) - 1]);
	j = 0;
	while (i < l)
	{
		x = i + 1;
		j = (4 * x) - 1;
		c = hex[i];
		d = (int)c;

		if (d >= 48 && d < 58)
			d = d - 48;

		else
			d = d - 87;
		printf("Equivalent value of %c is %d\n", c, d);


		while (d > 0) {

			b[j] = d % 2;
			printf("%d", b[j]);
			d = d / 2;
			j--;
		}


		i++;
		//j = (4 * i) ;
		printf("\nNow\n");

	}
	//printf("%d\n", b[1]);
	for (j = 0; j < (4 * l); j++)
	{
		printf("%d", b[j]);
	}

}