#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main()
{

	char **p;
	char *temp;
	char s[50];
	int n, i, j, len;
	printf("Enter the no. of  strings\n");
	scanf("%d", &n);
	p = (char**)malloc(n * sizeof(char*));
	printf("Enter the strings\n");
	for (i = 0; i < n; i++)
	{
		scanf("%s", s);
		len = strlen(s);
		p[i] = (char*)malloc((len+1) * sizeof(char));
		strcpy(p[i], s);
	}
	printf("BEFORE\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\n", p[i]);
	}
	temp= (char*)malloc((len + 1) * sizeof(char));
	temp = p[0][0];
	//printf("First char is %c", temp);
	for (i = 0; i < n; i++)
	{
		//printf("1st for");
		for (j = 0; j < n - i; j++)
		{
			//printf("\n2st for");

			if ((*(*(p+j)+0)) > (*(*(p+j+1)+0)))
			{
				temp = *(p+i);
				*(p+i)= *(p+j);
				*(p + j) = temp;

			}
			//printf("End of 2nd for");
		}
		//printf("end of 1st for");
	}

	printf("After sorting\n");

	for (i = 0; i < n; i++)
	{
		printf("%s\n", p[i]);
	}
	scanf("%d", n);
	getchar();
}