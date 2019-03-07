#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZEE 10000
void string_rev(char *);
void string_cpy(char *);
void string_cmp();
void string_concat();
char* ip_str();
char *str1, str2;
void string_concat() {
	int n, n1;
	char *str1, *str2;
	printf("Enter string1");
	str1 = (char*)malloc(sizeof(char)*SIZEE);
	scanf("%s", str1);
	printf("\nEnter string2");
	str2 = (char*)malloc(sizeof(char)*SIZEE);
	scanf("%s", str2);
	printf("%s", str1);
	n = strlen(str1) ;
	n1 = strlen(str2);
	while (*str1)// goes till the end of the first string
		str1++;

	while (*str2)
	{
		*str1 = *str2;
		str2++;
		str1++;
	}
	*str1 = '\0';// puts null at  the end of concatenated string.
	str1 = str1 - (n + n1); 
	printf("string after concat operation:%s\n", str1);
}
void string_cmp() {
	int i = 0;
	char *str1, *str2;
	printf("Enter string1");
	str1 = (char*)malloc(sizeof(char)*SIZEE);
	scanf("%s", str1);
	printf("\nEnter string2");
	str2 = (char*)malloc(sizeof(char)*SIZEE);
	scanf("%s", str2);
	printf("XXXX");
	while(str1[i] == str2[i])
	{
		if (str1[i] == '\0' || str2[i] == '\0')
			break;
		i++;
	}
	printf("After string comparision\n");
	if (str1[i] == '\0' && str2[i] == '\0') //when null is encountered in both the strings
		printf("%s and %s  strings are same:0", str1, str2);
	else if (*str1 > *str2)
		printf("%s is bigger than %s:1", str1, str2);// when ascii of first string greater than second
	else
		printf("%s is smaller than %s:-1", str1, str2);
}
void string_rev(char *orig_str) {
	char *reverse_string;
	int last, len=strlen(orig_str), iterator;
	reverse_string = (char*)malloc(sizeof(char) * len);
	last = len; //tostartfromlast
	len = 0;
	for (iterator = last - 1; iterator >= 0; iterator--)
		reverse_string[len++] = orig_str[iterator];
	reverse_string[len] = '\0';
	printf(" string after reverse operation:%s\n", reverse_string);
}
void string_cpy(char *orig_str) {
	char *cpy_str;
	int j = strlen(orig_str);
	cpy_str = (char*)malloc(sizeof(char) * j);
	while (*orig_str)
	{
		*cpy_str = *orig_str;
		orig_str++;
		cpy_str++;
	}
	*cpy_str = '\0';
	cpy_str = cpy_str - (j);
	printf("string copied to destination is:");
	printf("%s\n", cpy_str);
}
char* ip_str() {
	char *str;
	//int i=2, j=0;
	printf("Enter string1");
	str = (char*)malloc(sizeof(char)*SIZEE);
	scanf("%s", str); //[^\n]%*c
	if (NULL == str) {
		printf("No choice made");
		return;
	}
	//while ((str[j]) != '\n')
	//{
	//	/*if (isdigit(str[j]))
	//	{
	//		printf("Invalid input");
	//		free(str);
	//		return;
	//	}*/
	//	j++;
	//}
	return str;
}
int main() {
	int choice, iterator1;
	do {
		printf("\nMenu:\n1)Reverse\n2)Copy\n3)Compare\n4)Concat\n5)Exit\nEnter choice.");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: {
			str1 = ip_str();
			//printf("XYZ %s", str1);
			string_rev(str1);
			printf("Enter 0 to perform another operation or 5 to exit");
			scanf("%d", &iterator1);
			break;
		}
		case 2: {
			str1 = ip_str();
			string_cpy(str1);
			printf("Enter 0 to perform another operation or 5 to exit");
			scanf("%d", &iterator1);
			break;
		}
		case 3: {
			string_cmp();
			printf("Enter 0 to perform another operation or 5 to exit");
			scanf("%d", &iterator1);
			break;
		}
		case 4: {
			string_concat();
			printf("Enter 0 to perform another operation or 5 to exit");
			scanf("%d", &iterator1);
			break;
		}
		case 5: {
			break; }
		default: {
			printf("Invalid choice. Enter 0 to make again");
			break;
		}
		}
	} while (iterator1 == 0);
	getchar();
	return 0;
}
