#include<stdio.h>

#include<ctype.h>

int main() {

	int l = 0, digits = 0, tab = 0, space = 0, i;

	char text[80], c;

	scanf_s("%[^\n]s", text);

	for (i = 0; i < 80; i++) {

		c = text[i];

		if (isalpha(c))

			l++;

		else if (isdigit(c))

			digits++;

		else if (c == '\t')

			tab++;

		else if (c == ' ')

			space++;

		else if (c == '\n' || c == '\0')

			break;

	}

	printf("Letters = %d \n", l);

	printf("digits = %d \n", digits);

	printf("tabs = %d \n", tab);

	printf("space = %d \n", space);

	return 0;
}