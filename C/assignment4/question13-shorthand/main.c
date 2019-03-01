#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
char* expand(char *, char *);
int main() {
	char x[10000], *s1,*s2;
	int l,flag=0,i=0;
	printf("Enter your string s1");
	while(x){
		scanf("%c", &x[i]);
		if (!((x >= 'a'&&x <= 'z') || (x >= 'A' &&x <= 'ZZ') || (x >= '0'&&x <= '9'))) {
			printf("Error. Enter only characters or digits");
			flag = 1;
			//x = {};
			break;
		}
	}
	if (0 == flag) {
		l = strlen(x);
		s1 = (char *)malloc(l * sizeof(char));
		strcpy(x, s1);
		s2 = (char *)malloc(l * sizeof(char));
		s2=expand(s1, s2);
		printf("The expanded string is %s", s2);
		getchar();
		return 0;
	}
	return -1;
}
char* expand(char *s1, char *s2) {
	char ll, ul;
	int y;
	for (int i = 0; s1[i] != '\0'; i++) {
		if ((s1[i] == '-')&&(s1[i+1]!='-')) {
			ll = s1[i - 1];
			ul = s1[i + 1];
			/*for ( y = i; y <= ll; y++) {
				strcpy(s2[y], s1[y]);
			}*/
			for (int j = i; j < ul; j++) {
				strcpy(s2[j], ll++);
				//ll++;
			}
			/*for (int z = ul; s1[z]!='\0'; z++) {
				strcpy(s2[y], s1[z]);
			}*/
		}
		strcpy(s2[i], s1[i]);
	}
	return s2;
}