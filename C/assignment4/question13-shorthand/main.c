//to expand shorthand
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZEE 10000
char* expand(char *, char *);
int main() {
	char *arr_str,*s1,*s2;
	int length=0,flag=0,i=0;
	arr_str = (char *)malloc(sizeof(char) * SIZEE);
	printf("Enter your string s1\n");
	scanf("%s", arr_str);
	do{
		/*scanf("%c", &arr_str[i]);*/
		if (!((arr_str[i] >= 'a'&&arr_str[i] <= 'z') || (arr_str[i] >= 'A' &&arr_str[i] <= 'ZZ') || (arr_str[i] >= '0'&&arr_str[i] <= '9') || (arr_str[i] == '-') || (arr_str[i]=='\t') || (arr_str[i]=='\n'))) {
			printf("Error. Enter only characters or digits");
			flag = 1;
			getchar();
			break;
		}
		length++;
		i++;
	}while (arr_str[i] != '\0');
	length = strlen(arr_str);
	//printf("%d", length);
	if (0 == flag) {
		s2 = (char*)malloc(sizeof(char)*length);
		s2=expand(arr_str, s2);
		printf("\nThe expanded string is %s", s2);
		getchar();
		return 0;
	}
	getchar();
	return -1;
}
char* expand(char *s1, char *s2) {
	//printf("\nIn expand");
	char low_lim, up_lim;
	int j=0;
	for (int i = 0, j=0; s1[i]!='\0'; j++,i++) {
		//printf("\nin for");
		if ((s1[i] == '-')&&(s1[i+1]!='-')) {
			//printf("\nin if");
			low_lim = s1[i - 1];
			up_lim = s1[i + 1];
			//printf("\n%c and %c", low_lim, up_lim);
			if (up_lim < low_lim) {
				printf("Invalid shorthand"); //example h-a
				getchar();
				free(s2);
			}
			int diff = (int)up_lim - (int)low_lim -1;
			//printf("%d", diff);
			s2 = (char*)realloc(s2, sizeof(char)*(diff));
			char c = low_lim;
			for ( int k=0; k<diff; k++) {		
				c = c + 1;
				s2[j] = c;
				j++;
				//ll++;
			}
			
			//printf("\n j value is %d", j);
			i++; //toskipthehyphen
			//continue;
		}
		//printf("\n j value is %d", j);
		s2[j] = s1[i];
	}
	getchar();
	return s2;
}