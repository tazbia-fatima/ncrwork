#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
 int count(FILE *);
 void remove_comments(FILE *);
 void match_rotate(FILE *,char *);
 void replace(FILE *);
int main()
{
	char op;
	char *C = NULL;
	int x;
	FILE *fp2=NULL;
	fopen_s(&fp2,"f1.txt","a+");
	//printf("errno%d", x);
	//printf("%s", fp2);
	printf("Menu :");
	printf("\na)Count the number of alphabets,digits,spaces and special characters in the file\nb)Remove all comments from the file contents\nc)Find a matching word in the file and rotate the word and place it in the same file");
	printf("\nd)Replace all tabs present in the file content with \t\nEnter choice\n");
	scanf_s("%c", &op);
	switch(op) {
	case 'a': 
	{	
	x=count(fp2);
		break;
	}
	case 'b':
	{	printf("%c", op);
		remove_comments(fp2);
		printf("%c", op);
	break;
		}
	case 'c':
	{printf("Enter the word to match\n");
	scanf_s("%s", &C);
		match_rotate(fp2,C);
		break;
	}
	case 'd':
	{
		replace(fp2);
		break;
	}
	default:
	{
		printf("Enter valid choice");
		break;
	}
	}

	//printf("%c", op);
	scanf_s("%c", &op);
	getchar();
	return 0;

}
