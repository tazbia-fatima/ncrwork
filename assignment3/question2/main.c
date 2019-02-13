#include<stdio.h>
void main()
{
	int n, i, j, swap;
	int *p = NULL;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	p = (int*)malloc(n * sizeof(int));

	if (p == NULL)
	{
		printf("Error! memory not allocated\n");

	}
	else
	{
		printf("Enter %d values\n", n);
		for (i = 0; i < n; i++)
		{
			scanf("%d", p + i);

		}

		i = 0;
		j = n - 1;
		while (i < j)
		{
			if (p[i] < 0)
			{
				i++;

			}


			else if (p[j] > 0)
			{
				j--;
			}
			else
			{
				swap = p[i];
				p[i] = p[j];
				p[j] = swap;
			}

		}
		for (i = 0; i < n; i++)
		{
			printf("%d\n", p[i]);

		}


	}
	free(p);
	getchar();

}