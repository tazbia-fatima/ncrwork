//to expand shorthand
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define SIZEE 10000
char* expand(char *, char *);
int main() {
	char *arr_str,*resultant_arr;
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
	printf("\nThe  string is %s", arr_str);
	length = strlen(arr_str);
	printf("\nThe  string is %s", arr_str);
	printf("%d", length);
	if (0 == flag) {
		resultant_arr = (char*)malloc(sizeof(char)*length);
		resultant_arr=expand(arr_str, resultant_arr);
		printf("\nThe expanded string is %s", resultant_arr);
		free(arr_str);
		free(resultant_arr);
		getchar();
		return 0;
	}
	free(arr_str);
	free(resultant_arr);
	getchar();
	return -1;
}
char* expand(char *orig_arr, char *resultant) {
	//printf("\nIn expand");
	char low_lim, up_lim;
	int j=0;
	for (int i = 0, j=0; orig_arr[i]!='\0'; j++,i++) {
		printf("\nin for");
		if ((orig_arr[i] == '-')&&(orig_arr[i+1]!='-')) {
			printf("\nin if");
			low_lim = orig_arr[i - 1];
			up_lim = orig_arr[i + 1];
			printf("\n%c and %c", low_lim, up_lim);
			if (up_lim < low_lim) {
				printf("Invalid shorthand"); //example h-a
				getchar();
				free(resultant);
			}
			int diff = (int)up_lim - (int)low_lim -1;
			printf("%d", diff);
			resultant = (char*)realloc(resultant, sizeof(char)*(diff));
			char c = low_lim;
			for ( int k=0; k<diff; k++) {		
				c = c + 1;
				printf("\nvalue of c %c", c);
				resultant[j] = c;
				printf("\nvalue of s2 %c", resultant[j]);
				j++;
				//ll++;
			}
			
			printf("\n j value is %d", j);
			i++; //toskipthehyphen
			//continue;
		}
		printf("\n j value is %d", j);
		printf("\nvalue of s1 %c", orig_arr[i]);
		
		resultant[j] = orig_arr[i];
		printf("\nvalue of s2 %c", resultant[j]);
	}
	printf("\nThe expanded string is %s", resultant);
	getchar();
	return resultant;
}