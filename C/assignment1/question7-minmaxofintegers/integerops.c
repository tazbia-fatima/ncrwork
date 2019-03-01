#include<stdio.h>
#include<limits.h>

void main() {

	int c = 0, sum = 0, avg = 0, n,max=0,min=INT_MAX;
	printf("Enter the integers");
	for (int i = 0;; i++)
	{
		scanf_s("%d", &n);

		if (n <= 0)

			break;

		else {
			sum += n;
			c++;

			if (n <= min)

				min = n;

			if (n >= max)

				max = n;

		}

	}
	avg = sum / c;

	printf("Count of positive integers = %d\n", c);
	printf("Maximum = %d\n", max);
	printf("Minimum = %d\n", min);
	printf("Average = %d\n", avg);

	scanf_s("%d", &c);
	getchar();
}