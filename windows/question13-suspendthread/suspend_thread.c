#include<stdio.h>
#include<dos.h>
#include<Windows.h>
#include<tchar.h>
DWORD WINAPI thread_func(LPVOID lpParam);
int _tmain() {
	DWORD dwThreadID;
	HANDLE hThread1;

	hThread1 = CreateThread(NULL, 0, thread_func, NULL, 0, &dwThreadID);
	if (NULL == hThread1) {
		_tprintf("Error");
		return FALSE;
	}
	_tprintf(_T("Resuming thread after 5 secs.\n"));
	Sleep(5000);
	ResumeThread(hThread1);
	CloseHandle(hThread1);
	getchar();
	return TRUE;
}
DWORD WINAPI thread_func(LPVOID lpParam) {
	for (int i = 1; i <= 1000; i++) {
		_tprintf(_T("%d\n"),i);
	}
	Sleep(1000);
	_tprintf("Thread executed");
	return TRUE;
}