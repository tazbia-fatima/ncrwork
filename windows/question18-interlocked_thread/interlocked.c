#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<string.h>
int count = 0;
DWORD WINAPI thread_func(LPVOID lpParam);
int _tmain(int argc, TCHAR *argv[]) {
	HANDLE hThread1, hThread2;
	DWORD dwThreadID1, dwThreadID2;
	int x = count;
	count = 0;
	printf("\nCount INITIAL VALUE is: %d", count);
	hThread1 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadID1);
	if (NULL == hThread1) {
		_tprintf("Error no %d", GetLastError());
	}
	//_tprintf(_T("\nParent waiting for thread to execute normally"));
	//WaitForSingleObject(hThread1 //handle of thread
	//	, INFINITE//dwMilliseconds
	//);
	hThread2 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadID2); //thread2ofsameprocess
	if (NULL == hThread2) {
		_tprintf("Error no %d", GetLastError());
	}
	/*_tprintf(_T("\nParent waiting for thread to execute normally"));*/
	WaitForSingleObject(hThread1 //handle of thread
		, INFINITE//dwMilliseconds
	);
	/*_tprintf(_T("\nParent waiting for thread to execute normally"));*/
	WaitForSingleObject(hThread2 //handle of thread
		, INFINITE//dwMilliseconds
	);
	if (count != (x + 2)) {
		printf("Inconsistent sharing. Count is %d", count);
	}
	else {
		printf("\nCount FINAL VALUE is: %d", count);
	}
	getchar();
	return TRUE;
}
DWORD WINAPI thread_func(LPVOID lpParam) {
	InterlockedIncrement(&count); //using interlocked function for atomic access
	return 0;
}