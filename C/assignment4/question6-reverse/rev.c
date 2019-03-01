#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void rev(char *);
int main() {
	char *str = NULL;
	int l;
	str = (char *)malloc(5 * sizeof(char));
	printf("Enter the string\n");
	scanf("%[^\n]s", str);
	//l = strlen(str);
	printf("%s", str); 
	rev(str);
	//printf("\nThe reversed string is %s", str);
	scanf("%[^\n]s", str);
	getchar();
	return 0;
}
void rev(char *str) {
	//char a[50];
	//int i = 0;
	if (*str) {
		rev(str + 1);
		printf("%c", *str);
	}
	//return a;
}