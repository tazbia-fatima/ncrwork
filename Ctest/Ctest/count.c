#include<stdio.h>
int count(FILE *p) {
	int a, d, s, sp;
	char c;
	a = d = s =sp= 0;
	//fopen_s(&p, f1, "r");
	do{
		c = fgetc(p);
		if (((c >= 'A')&&(c <= 'Z'))||((c>= 'a')&&((c)<= 'z'))) //if((p+i)>= 'A') && (p+i) <= 'Z'))?
		{
			++a;

		}
		else if ((c >= 0) && (c <= 9)) {
			++d;
		}
		else if (c == ' ') {
			++s;
		}
		else if (c == '\n') {
			continue;
		}
		else {
			++sp;
		}
	} while (c != EOF);
	printf("\nCount of :\nAlphabets:%d\nDigits:%d\nSpaces:%d\nSpecial characters:%d\n", a, d, s, sp);
	return 0;
}