#include<stdio.h>
void main()
{
	int bi[16] = { 0 }, num,i;
	printf("Enter number between 0 and 32:\n");
	scanf_s("%d", &num);
	if (num < 0 | num>36) {
		printf("Invalid number. enter between 0 and 32");
		num = 0;
	}
	bi[0] = 1;
	i = 15;
		while (num > 0)  
		{
			if (num % 2 == 0)
				bi[i] = 0;
			else
				bi[i] = 1;
			i--;
			num = num / 2;
		}
		//bi[i] = 1;
			for (int j = 0; j < 16; j++) {
				printf("%d", bi[j]);
			}
			scanf_s("%d", &num);
			getchar();
}