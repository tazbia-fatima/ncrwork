#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void main()
{
	char **arr;
	char* s[50], temp[50];
	int n, i, j, l;
	printf("enter the number of strings\n");
	scanf("%d", &n);
	arr = (char **)malloc(n * sizeof(char *));
	printf("enter %d strings\n", n);
	for (i = 0; i < n; i++)
	{
		scanf("\n%[^\n]s", s);
		l = strlen(s) + 1;
		arr[i] = (char *)malloc((l) * sizeof(char));
		strcpy(arr[i], s);
	}

	for (i = 0; i < n; i++)
	{
		printf("%s\t", arr[i]);

	}
	scanf("%d", &i);
	getchar();
	

}
