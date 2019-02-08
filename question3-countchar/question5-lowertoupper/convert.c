#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {
	char *str = NULL;
	int l = 0;
	str = (char *)malloc(50 * sizeof(char));
	printf("Enter the string\n");
	scanf("%[^\n]s", str);
	//printf("%s", str); - teststatement
	l = strlen(str);
	for (int i = 0; i < l; i++) {
		if (*(str+i) >= 65 && *(str+i) <= 90) {
			*(str+i) = *(str+i) + 32;
		}
		else if (str[i] >= 97 && str[i] <= 122) {
			str[i] = str[i] - 32;
		}
		else
		{
			str[i] = str[i];
		}
	}
	printf("The converted string is %s\n", str);
	getchar();
	return 0;
}