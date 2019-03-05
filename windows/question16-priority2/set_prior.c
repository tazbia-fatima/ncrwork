#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<string.h>
DWORD WINAPI thread_func(LPVOID lpParam);
int _tmain(int argc, TCHAR *argv[], TCHAR *env[]) {
	printf("in child process");
	HANDLE h1 = GetCurrentProcess();
	HANDLE hThread1;
	DWORD dwThreadID;
	getchar();
	printf("\n Handle is %d", h1);
	if (!SetPriorityClass(h1, BELOW_NORMAL_PRIORITY_CLASS)) {
		printf("Couldn't Set priority. Error no : %d", GetLastError());
		getchar();
		return FALSE;
	}
	hThread1 = CreateThread(NULL, 0, thread_func, NULL, THREAD_PRIORITY_LOWEST, &dwThreadID);
	if (NULL == hThread1) {
		_tprintf("Error no %d",GetLastError());
	}
	_tprintf(_T("\nParent waiting for thread to execute normally"));
	WaitForSingleObject(hThread1 //handle of thread
		, INFINITE//dwMilliseconds
	);
	CloseHandle(hThread1);
	printf("XXX");
	getchar();
	return TRUE;
}
DWORD WINAPI thread_func(LPVOID lpParam) {
		for (int i = 0; i < 10; i++) {
			_tprintf("Thread executing..\n");
		}
		Sleep(1000);
		_tprintf("Thread executed");
		return 0;
}