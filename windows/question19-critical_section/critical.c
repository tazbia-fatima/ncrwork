//Write a program to modify shared variable between two threads guarded by critical section.
//Use InitializeCriticalSection or InitializeCriticalSectionAndSpinCount, DeleteCriticalSection, EnterCriticalSection, LeaveCriticalSection.
//Wait for both the threads to exit before exiting process primary thread.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<string.h>
DWORD WINAPI thread_func(LPVOID lpParam);
DWORD WINAPI thread_func1(LPVOID lpParam);
CRITICAL_SECTION lpCritSection;
int sum = 0;
DWORD WINAPI thread_func(LPVOID lpParam) {
	EnterCriticalSection(&lpCritSection);
	for (int i = 0; i < 10; i++) {
		sum++;
	}
	_tprintf("Thread1 executed\n");
	_tprintf(_T("Sum is  : %d\n"),sum);
	LeaveCriticalSection(&lpCritSection);
	return 0;
}
DWORD WINAPI thread_func1(LPVOID lpParam) {
	EnterCriticalSection(&lpCritSection);
	for (int i = 0; i < 10; i++) {
		sum++;
	}
	_tprintf("Thread2 executed\n");
	_tprintf(_T("Sum is : %d\n"), sum);
	LeaveCriticalSection(&lpCritSection);
	return 0;
}
int _tmain(int argc, TCHAR *argv[]) {
	HANDLE hThread1, hThread2;
	HANDLE arr_handle[2];
	DWORD dwThreadID1, dwThreadID2, wait_return_value;
	InitializeCriticalSection(&lpCritSection);
	hThread1 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadID1);
	if (NULL == hThread1) {
		_tprintf("Error no %d", GetLastError());
	}
	hThread2 = CreateThread(NULL, 0, thread_func1, NULL, 0, &dwThreadID2);
	if (NULL == hThread2) {
		_tprintf("Error no %d", GetLastError());
	}
	wait_return_value = WaitForSingleObject(hThread1 //handle of thread
		, INFINITE//dwMilliseconds
	);
	wait_return_value = WaitForSingleObject(hThread2 //handle of thread
		, INFINITE//dwMilliseconds
	);
	printf("Threads executed.");
	DeleteCriticalSection(&lpCritSection);
	getchar();
	return TRUE;
}