#include<stdio.h>
void replace(FILE *p) {
	char c;
	//fopen_s(&p, "f1.txt", "r+");
	while (!feof(p)) {
		c=fgetc(p);
		if ( c == '\t') {
			fputc('\\', p);
			fputc('t', p);
		}
	}
}