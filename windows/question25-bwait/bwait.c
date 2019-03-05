//Write a program to create two threads and print the reason for WaitForMultipleObjects return.
//Print results with:
//bWaitAll = TRUE and timeout interval INFINITE
//bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(4000) and thread2 Sleep(3000)
//bWaitAll = FALSE and timeout interval INFINITE, thread1 Sleep(2000) and thread2 Sleep(3000)
//bWaitAll = FALSE and timeout interval 2000, thread1 Sleep(4000) and thread2 Sleep(3000)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<string.h>
DWORD WINAPI thread_func(LPVOID lpParam);
DWORD WINAPI thread_func1(LPVOID lpParam);
int _tmain(int argc, TCHAR *argv[]) {
	HANDLE hThread1, hThread2;
	HANDLE arr_handle[2];
	DWORD dwThreadID1, dwThreadID2, wait_return_value;
	hThread1 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadID1);
	if (NULL == hThread1) {
		_tprintf("Error no %d", GetLastError());
	}
	hThread2 = CreateThread(NULL, 0, thread_func1, NULL, 0, &dwThreadID2);
	if (NULL == hThread2) {
		_tprintf("Error no %d", GetLastError());
	}
	arr_handle[0] = hThread1;
	arr_handle[1] = hThread2;
	//wait_return_value = WaitForMultipleObjects(2, arr_handle, TRUE, INFINITE);
	//wait_return_value = WaitForMultipleObjects(2, arr_handle, FALSE, INFINITE); //2nd&3rd
	wait_return_value = WaitForMultipleObjects(2, arr_handle, FALSE, 2000); //4th 
	if (WAIT_OBJECT_0 <= wait_return_value || WAIT_OBJECT_0 + (2 - 1) >= wait_return_value) {
		printf("\nThe reason of waitsingleobject return is Wait_Object_0 : Thread signaled\n");
	}
	else if (WAIT_TIMEOUT == wait_return_value) 
	{
		printf("\nThe reason of waitsingleobject return is Wait_Timeout : Wait time elapsed and Thread unsignaled\n");
	}
	else if (WAIT_ABANDONED_0 <= wait_return_value || WAIT_ABANDONED_0+(2-1) >= wait_return_value)
	{
		printf("\nThe reason of waitsingleobject return is Wait_Abandoned : Thread unsignaled and unreleased\n");
	}
	else if(WAIT_FAILED){
		printf("\nFunction failed\n");
	}
	else {
		printf("ERROR\n");
	}
	printf("\nEnd of waiting for objects and End of Parent process\n");
	getchar();
	return TRUE;
}
DWORD WINAPI thread_func(LPVOID lpParam) {
	for (int i = 0; i < 3; i++) {
		_tprintf("Thread1  executing..\n");
		//Sleep(1000); //to check with respect to wait time
	}
	//Sleep(4000); //to check scheduling of thread during other threads sleep
	//Sleep(2000); //to check scheduling of thread during other threads sleep
	_tprintf("Thread1 executed\n");
	Sleep(4000); //for 2nd&4th condition
	//Sleep(2000); //for 3rd condition
	return 0;
}
DWORD WINAPI thread_func1(LPVOID lpParam) {
	for (int i = 0; i < 3; i++) {
		_tprintf("Thread2 executing..\n");
		//Sleep(3000); //to check with respect to wait time
	}
	//Sleep(3000); //to check scheduling of thread during other threads sleep
	_tprintf("Thread2 executed\n");
	Sleep(3000); //for 2nd,3rd,4th condition
	return 0;
}
