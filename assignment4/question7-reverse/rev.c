#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *rev(char *);
int main() {
	char *str = NULL;
	str = (char *)malloc(50 * sizeof(char));
	printf("Enter the string\n");
	scanf("%[^\n]s", str);
	printf("%s", str); 
	str=rev(str);
	printf("The reversed string is %s", str);
	getchar();
	return 0;
}
char *rev(char *str) {
	char *rev1 = NULL;
	rev1 = (char *)malloc(50 * sizeof(char));
	return(rev1  rev(str + 1));
}