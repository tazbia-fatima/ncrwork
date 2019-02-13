#include<stdio.h>

int fact(int n);
int main()
{
	int n, r;
	printf("Enter number\n");
	scanf("%d", &n);
	r = fact(n);
	printf("factorial is %d", r);
	getchar();
	return 0;
}

int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return (n*fact(n - 1));

}