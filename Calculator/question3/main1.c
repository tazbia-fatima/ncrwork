#include<stdio.h>
void main()
{
	long int num = 0, num2=0, last_four;
	printf("Enter the number");
	scanf_s("%x", &num);
	printf("Num is %d", num);
	/*num2 = ((1 << 4) - 1) << 0;
	printf("\n the mask is %d", num2);
	last_four = num & num2;*/
	//for (int i = 1; i <= 28; i++) {
		//last_four = num << i;
	//}
	//last_four = last_four >> 1;
	last_four = 51966 << 12;
	//last_four = num >> 27;

	printf("\nlast four digits is %ld", last_four);
	//last_four = last_four >> 12;
	//printf("\nlast four digits is %d", last_four);
	scanf_s("%d", &num);
	getchar();
}