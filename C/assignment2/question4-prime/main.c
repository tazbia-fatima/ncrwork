#include<stdio.h>

void main()
{
	int n, b, i, j, c = 0;
	printf("Enter start point\n");
	scanf("%d", &n);
	printf("Enter end point\n");
	scanf("%d", &b);

	for (i = n; i < b; i++)
	{
		for (j = 2; j < i; j++)
		{
			if ((i%j) == 0)
				c++;
		}
		if (c == 0)
			printf("%d\n", i);
		c = 0;
	}
	getchar();

}