#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

int invertponwards(int n, int p, int b);

int main() {

	int result, n, p, b;
	printf("enter the values of n, p, b\n");
	scanf("%d", &n);
	scanf("%d", &p);
	scanf("%d", &b);
	result = invertponwards(n, p, b); 
	printf("The integer after inverting is %d", result);
	scanf("%d", &n);
	return 0;
}

int invertponwards(int n, int p, int b)
{
	int binaryNum[10] = {0}, t = 0, c, max, x=0;

	int i = 0;
	while (n > 0) {

		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	for (c = i; c >=0; c--) {
		printf("%d", binaryNum[c]);
	}
	printf("\n");

	max = p + b;
	//c = p + 1;
	c = p;
	if (max < i) { //i is the length
		while (t < b)
		{

			if (binaryNum[c] == 1)
				binaryNum[c] = 0;
			else
				binaryNum[c] = 1;
			c++;
			t++;

		}
	}
	else
		printf("enter other values for p and b");

	for (c = i; c >=0; c--) {
		printf("%d", binaryNum[c]);
	}

	x = 0;
	for (c = 0,t=0; c <i,t<i; c++,t++)
	{
		x = x + binaryNum[c]*pow(2,t);
		printf("\n%d and %d--%d",binaryNum[c],t, x);
	}
	printf("\nXX - %d", x);
	return x;

}