#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<stdlib.h>
int main() {
	int arr_l, arr1_len;
	char char1 = 'A';
	wchar_t char_local = L'A';
	printf("Enter length of char array");
	scanf("%d", &arr_l);
	PSTR arr_p = (PSTR)malloc(sizeof(CHAR)*arr_l);
	printf("Enter the character array");
	scanf("%s", arr_p);
	printf("Enter length of widechar array");
	scanf("%d", &arr1_len);
	PWSTR arr_w_p = (PWSTR)malloc(sizeof(WCHAR)*arr1_len);
	printf("Enter the widecharacter array");
	scanf("%S", arr_w_p); //Capital S is format specifier for wide char
	printf("is arr_p unicode :%d\n", IsTextUnicode(arr_p, strlen(arr_p)+1, NULL));
	printf("is arr_w_p unicode :%d\n", IsTextUnicode(arr_w_p, wcslen(arr_w_p)+1, NULL));
	int res = MultiByteToWideChar(CP_UTF8, 0, arr_p, strlen(arr_p), NULL, 0);//returns size of result array
	if (0 == res) {
		printf("Error!", GetLastError());
		return -1;
	}
	PWSTR res_arr_p = (PWSTR)malloc(sizeof(WCHAR)*res);
	MultiByteToWideChar(CP_UTF8, 0, arr_p, strlen(arr_p), res_arr_p, res+1); //conversion
	printf("%S", res_arr_p);
	printf("\n");
	//printf("YY");
	int res_w = WideCharToMultiByte(CP_UTF8, 0, arr_w_p, wcslen(arr_w_p), NULL, 0,NULL,NULL); //returns size of resultant array
	if (0 == res_w) {
		printf("Error!", GetLastError());
		return -1;
	}
	PSTR res_arr_w_p = (PSTR)malloc(sizeof(CHAR)*res_w);
	WideCharToMultiByte(CP_UTF8, 0, arr_w_p, wcslen(arr_w_p)+1, res_arr_w_p, res_w+1,NULL,NULL); //conversion
	//printf("\nXYZ");
	printf("%s\n", res_arr_w_p);
	//printf("YY");
	scanf("%d", &res);
	getchar();
	return 0;
}