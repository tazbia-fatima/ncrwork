#include <stdio.h>
#include <string.h>

int main() {
	int c = 0, l = 0, l1;;
	char * s[] = { "we will teach you how to", "Move a mountain ", "Level a building " , "Erase the past ","Make a million"};
	l1 = sizeof(s) / sizeof(char *);
	for (int j = 0; j <l1 ; j++) 
	{
		printf("Outerloop: %s", *(s + j));
		l = strlen(*(s + j));
		//printf("XX %d",l); - test statement
		for (int i = 0; i < l; i++)
		{
			if (*(*(s+j)+i) == 'e')
			{
				c++;
				//printf("Innerloop  %c", *(*(s + j)+i)); - test statement
			}
		}
		printf("\n");
	}
	printf("The total number of 'e's are: %d", c);
	getchar();
	return 0;
}
