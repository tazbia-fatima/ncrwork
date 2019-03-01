#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h>
int any(char *, char *);
int main() {
	char s1[50], s2[50];
	int pos;
	/*s1 = (char *)malloc(50 * sizeof(char));*/
	printf("Enter the string\n");
	scanf("%[^\n]s", s1);
	/*s2 = (char *)malloc(50 * sizeof(char));*/
	printf("Enter the string\n");
	scanf("%[^\n]s", s2);
	pos=any(s1, s2);
	printf("Index of first match is %d", pos);
	scanf("%[^\n]s", s1);
	return 0;
}
int any(char *s1, char *s2) {
	for (int i = 0; i < strlen(s1); i++) {
		for (int j = 0; j < strlen(s2); j++) {
			if (s1[i] == s2[j]) {
				return i;
			}
		}
	}

}