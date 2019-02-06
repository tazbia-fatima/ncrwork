#include<stdio.h>
void main() {
	char text[80] = { 0 };
	int i, l_count, d_count, space_count, tab_count;
	l_count = d_count = space_count = tab_count = 0;
	printf("Enter the characters");
	for (i = 0; i < 80; i++) {
		scanf_s("%c", &text[i]);
		if (text[i] == '\n') {
			break;
		}
	}
	for (i = 0; text[i] != '\0'; i++) {
		if (((text[i] >= 'A') && (text[i] <= 'Z')) | ((text[i] >= 'a') && (text[i] <= 'z')))
		{
			l_count++;
		} 
		else if((text[i] >= '0') && (text[i] <= '9'))
		{
			d_count++;
		}
		else if(32 == text[i])
		{
			space_count++;
		}
		else if (9 == text[i])
		{
			tab_count++;
		}
		else
		{
			printf("Enter valid character");
		}
	}
	printf("\nThe number of : \nLetters are: %d\nDigits are: %d\nSpaces are: %d\nTabs are:%d\n", l_count, d_count, space_count, tab_count);
	scanf_s("%d", &i);
	getchar();
}
