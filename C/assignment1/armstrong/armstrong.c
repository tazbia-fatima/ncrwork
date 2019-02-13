#include<stdio.h>
#include<math.h>
void main() {
	int num, orig, sum=0, length, i;
	printf("Enter the number to check\n");
	scanf_s("%d", &num);
	orig = num;
	length = log10(num) + 1;
	printf("length is %d\n",length);
	while (num != 0) {
		i = num % 10;
		num = num / 10;
		sum += pow(i, length);
	}
	if(sum == orig) {
		printf("The num %d is an armstrong number", sum);
	}
	else
	{
		printf("The number isnt an armstrong number");
	}
	scanf_s("%d", &num);
	getchar();
}