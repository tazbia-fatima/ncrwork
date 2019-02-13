#include<stdio.h>

#include<string.h>



void itob(int n, char s[]) {

	int i = 0;

	while (n>0) {

		s[i++] = (n % 2) + '0';

		n = n / 2;

	}

	s[i] = '\0';

	printf("Binary representation : %s\n", _strrev(s));

}



void itoh(int n, char s[]) {

	int i = 0;

	int  r;

	while (n>0) {

		r = n % 16;

		s[i++] = (r < 10) ? (r + '0') : (r - 10 + 'A');

		n = n / 16;

	}

	s[i] = '\0';

	printf("Hexadecimal representation = 0x%s\n", _strrev(s));

}



int main() {

	int n;

	char s[100];

	scanf_s("%d", &n);

	itob(n, s);

	itoh(n, s);

	printf("Enter X to exit");
	scanf_s("%d", &n);
	getchar();
	return 0;

}