#include<stdio.h>
#include<stdlib.h>

extern int add(int a, int b);
extern int sub(int a, int b);
extern int mul(int a, int b);
extern int divi(int x, int y);
void main()
{
	int a = 0, b = 0,x=0, res=0; 
	printf("Enter 2 nos ");
	scanf_s("%d%d", &a, &b);
	printf("The value of a is %d The value of b is %d ",a,b);
	printf("Menu:\n1. Add\n2. Sub\n3. Mul\n4. Div\n");
	printf("Enter the Function you'd like to perform :");
	scanf_s("%d", &x);
	switch (x) {
	case 1: { res=add(a, b);
		printf("\nres is %d",res);
		break;
	}
	case 2: {printf("\n res is %d", sub(a, b));
		break; }
	case 3: {printf("\n res is %d", mul(a, b));
		break; }
	case 4: {printf("\n res is %d", divi(a, b));
		break; }
	default: {
		printf("Unvalid");
		break;
	}
	}
	scanf_s("%d", &x);
	getchar();
}