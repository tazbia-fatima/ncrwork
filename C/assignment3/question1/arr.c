#include<stdio.h>
int main()
{
	int  arr[50],N, req = 0, t, flag = 0;
	int i = 0, j = 0, sum = 0;
	printf("Enter array size\n");
	scanf("%d", &N);
	printf("Enter array \n");
	for (i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	printf("Enter required number\n");
	scanf("%d", &req);
	sum = arr[0];
	//printf("%d", len);
	if (req == 0)
	{
		for (i = 0; i < N; i++)
		{
			if (arr[0] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			printf("found");
		else
			printf("not found");
	}
	else
	{
		while (i < (N + 1) && j < (N + 1))
		{
			if ((i >= j) && (j != 0))
			{
				t = i;
				i = j;
				j = t;
			}
			if (arr[0] == req)
			{
				break;
			}
			else if (sum < req)
			{
				if (j == N)
					break;
				else
				{
					j++;
					sum = sum + arr[j];
					//printf("%d\n", sum);
				}
			}
			else if (sum > req)
			{
				if (i == N)
					break;
				else
				{
					sum = sum - arr[i];
					i++;
					//printf("%d\n", sum);

				}
			}
			else if (sum == req)
			{
				break;
			}
		}
		if (sum == req)
			printf("found between indices %d and %d", i, j);
		else
			printf("not found");
	}

	scanf("%d", &i);
	getchar();
	return 0;
}