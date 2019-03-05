//Write a program to create a thread and print the reason for WaitForSingleObject return.Print results with.
//1.timeout interval INFINITE
//2.timeout interval 1000
//3.timeout interval 1000 with Sleep(2000) inside thread
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<string.h>
DWORD WINAPI thread_func(LPVOID lpParam);
int _tmain(int argc, TCHAR *argv[]) {
	HANDLE hThread1;
	DWORD dwThreadID1, wait_return_value;
	hThread1 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadID1);
	if (NULL == hThread1) {
		_tprintf("Error no %d", GetLastError());
	}
	wait_return_value = WaitForSingleObject(hThread1 //handle of thread
		, INFINITE//dwMilliseconds
	);
	//wait_return_value = WaitForSingleObject(hThread1 //handle of thread
	//	, 1000//dwMilliseconds
	//); //for 2nd and 3rd condition
	if (WAIT_OBJECT_0 == wait_return_value) {
		printf("\nThe reason of waitsingleobject return is Wait_Object_0 : Thread signaled");
	}
	else if (WAIT_TIMEOUT == wait_return_value) //102 in hexa is 258 in deci and dword is deci
	{
		printf("\nThe reason of waitsingleobject return is Wait_Timeout : Wait time elapsed and Thread unsignaled");
	}
	else if (WAIT_ABANDONED == wait_return_value) //80 in hexa is 128 in deci and dword is deci
	{
		printf("\nThe reason of waitsingleobject return is Wait_Abandoned : Thread unsignaled and unreleased");
	}
	else if(WAIT_FAILED){
		printf("\nFunction failed");
	}
	else {
		TRUE;
	}
	getchar();
	return TRUE;
}
DWORD WINAPI thread_func(LPVOID lpParam) {
	for (int i = 0; i < 10; i++) {
		_tprintf("Thread executing..\n");
	}
	_tprintf("Thread executed");
	//Sleep(2000); //for third condition
	return 0;
}
