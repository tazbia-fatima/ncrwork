#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int s, h, n, r, b[10], i = 0, x = 1, j, a[10], op;
	printf("Enter a hexadecimal number");
	scanf("%x", &h);
	n = h;
	int k = n;
	//printf("\n %d", n);
	//printf("\n");
	do {
		printf("\nMenu:\n1.Hex value of Ones Compliment\n2.Perform Masking\n3.Shifting of bits\n4.Exit\nEnter choice");
		scanf("%d", &op);
		switch (op)
		{
		case 1: {
			while (n != 0)
			{
				r = n % 2;
				a[i] = r;
				r = !r;
				b[i] = r; //one's compliment
				i++;
				n = n / 2;
			}
			n = 0;
			for (j = i - 1; j >= 0; j--)
			{
				printf("%d", b[j]);
				//printing one's compliment
			}
			for (j = 0; j < i; j++)
			{
				n = n + b[j] * x;
				x = x * 2;
			}
			printf("\n hex value is %x", n);
			printf("\nEnter 2 to make choice again");
			scanf("%d", &a[1]);
			break; }
		case 2: {
			int h1 = (h & 0xff); //masking
			printf("\nvalue after masking with offf is %x", h1);
			printf("\nEnter 2 to make choice again");
			scanf("%d", &a[1]);
			break; }
		case 3: {
			printf("\n Enter number of bits to be shifted");
			scanf("%d", &s);
			int g = k << s;
			printf("\n the hex value after shifting is %x", g);
			printf("\nEnter 2 to make choice again");
			scanf("%d", &a[1]);
			break; }
		case 4: { a[1] == 5;
			break; }
		default: { printf("invalid choice");
			break; }
		}
		
	} while (a[1] ==2);
	scanf("%d", &s);
	return 0;
}