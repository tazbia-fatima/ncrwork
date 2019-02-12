#include<stdio.h>
void remove_comments(FILE *p) {
	FILE *p1;
	int x=0;
	char c, c1,c2;
	printf("REMOVE\n");
	fopen_s(&p1,"f3.txt", "w");
	while(!feof(p)){
		c = fgetc(p);
		if (c == 47) {
			c = fgetc(p);
			if(c == 47){}
		}
		if ( (c != 47 )&& (c1 != 47))
		{
			fputc(c, p1);
			fputc(c1, p1);
		}
		else if (c==47&&c1=='*')
		{
			printf("XXX");
			do 
			{
				fseek(p, 1, SEEK_CUR);
				printf("XX");
				//fputc(32, p);
				c = fgetc(p);
				c1 = fgetc(p);
			} while (c!=47&&c1 != '*');
		}
		else if ((c == 47) && (c1 == 47)) 
		{
			 
			do{
				fseek(p, 1, SEEK_CUR);
				printf("YY");
				//fputc(32, p);
				c = fgetc(p);
			} while (c != '\n');
		}
		else 
		{
			continue;
		}
		fseek(p, -1, SEEK_CUR);
	} while (c1 != EOF);
	printf("Ready to print file");
	fseek(p1, 0, SEEK_SET);
	c2 = fgetc(p1);
	printf("%c", c2);
	while (c2 != EOF) 
	{
		printf("%c", c2);
		c2 = fgetc(p1);
	}
}