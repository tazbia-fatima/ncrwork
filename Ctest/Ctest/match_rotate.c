#include<stdio.h>
#include<string.h>
void match_rotate(FILE *p,char *c) {
	char *str=NULL;
	int flag = 0,l,x,j;
	l = strlen(c);
	//fopen_s(&p, "f1.txt", "r+");
	for (int i = 0; !feof(p);i++) {
		if (fgetc(p+i) == *(c+i)) 
		{
			for (int j = i; j<l; j++) {
				if (fgetc((p + i) + j) == *((c + i) + j)) {
					flag = 1;
					
				}
			}
			if (flag == 1) {
				printf("Matched");
				
				for (x = 0, j = l - 1; j >= 0; j--, x++) {
					str[x] = c[j];
				}
			}
			fputs(str, p+i);
		}
		else {
			flag = 0;
		}
	}
}