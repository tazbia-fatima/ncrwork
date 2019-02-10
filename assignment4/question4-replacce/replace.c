#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void replace(char *);
int main() {
	char *cat = NULL;
	cat = (char *)malloc(50 * sizeof(char));
	printf("Enter the string\n");
	scanf("%[^\n]s", cat);
	replace(cat);
	getchar();
	return 0;
}
void replace(char *str) {
	int l,c=0;
	l = strlen(str);
	for (int i = 0; i < l; i++) {
		if (' ' == str[i]) {
			str[i] = '-';
			c++;
		}
	}
	printf("\nThe replaced string is: %s\n", str);
	printf("The number of spaces replaced are : %d ", c);
}