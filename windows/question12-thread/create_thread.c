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
	}
	
	CloseHandle(hThread1);
	
	getchar();
	return TRUE;
}
DWORD WINAPI thread_func(LPVOID lpParam){
	for (int i = 0; i < 10; i++) {
		_tprintf("Thread executing..\n");
	}
	Sleep(1000);
	_tprintf("Thread executed");
	return 0;
}