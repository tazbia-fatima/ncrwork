#include<stdio.h>
void testlsb(int);
int rever_byte(int, int, int, int);
void rotate_bit(int);
void main()
{
	int num = 0, mask, mask1, C, A, F, E, num2, result_of_bit_b;
	printf("Enter the number");
	scanf_s("%x", &num);
	printf("Num is %d", num);
	num2 = num >> 4;
	num2 = num2 << 4;
	E = num ^ num2;
	printf("\nE %d", E);
	num2 = num >> 8;
	num2 = num2 << 8;
	mask = num ^ num2;
	mask1 = mask ^ E;
	F = mask1 >> 4;
	printf("\nF %d", F);
	num2 = num >> 12;
	num2 = num2 << 12;
	mask = num ^ num2;
	mask1 = mask ^ mask1;
	A = mask1 >> 8;
	printf("\nA %d", A);
	C = num >> 12;
	printf("\nC %d", C);
	printf("\nAnswer of bit a :");
	testlsb(num);
	printf("\nAnswer of bit b :");
	result_of_bit_b=rever_byte(C, A, F, E);
	printf("\nAnswer of bit c :");
	rotate_bit(result_of_bit_b);
	scanf_s("%d", &num);
	getchar();
}
void testlsb(int num)
{
	int res = 0, num2;
	num2 = num >> 4;
	res = num2 << 4;
	res = res ^ num;
	if (res >= 7) {
		printf("\nYes atleast 3 of the last 4 bits are set");
	}
	else
		printf("\nTest failed. Not even 3 of last 4 bits are set");
}
int rever_byte(int C, int A, int F, int E) {
	int resultant;
	F = F << 12;
	E = E << 8;
	C = C << 4;
	resultant = F | E;
	resultant = resultant | C;
	resultant = resultant | A;
	printf("\nResulting order = FECA. That is %d", resultant);
	return resultant;
}
void rotate_bit(int num) {
	unsigned int x, y, num1, num2;
	num1 = num >> 12;
	x = num1 << 12;
	num2 = num ^ x;
	num2 = num2 << 4;
	y = num2 | num1; 
	printf("rotate 4 bits ECAF: %d", y);

}