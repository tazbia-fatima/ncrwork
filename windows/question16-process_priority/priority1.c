#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<string.h>
int _tmain(int argc, TCHAR *argv[], TCHAR *env[]) {
	STARTUPINFO strt_info;
	PROCESS_INFORMATION proc_info;
	SECURITY_ATTRIBUTES sec_attr;
	HANDLE hproc;
	ZeroMemory(&strt_info, sizeof(strt_info));
	strt_info.cb = sizeof(strt_info);
	ZeroMemory(&proc_info, sizeof(proc_info));
	sec_attr.bInheritHandle = TRUE;
	if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, HIGH_PRIORITY_CLASS, NULL, NULL, &strt_info, &proc_info)) {
		_tprintf(_T("create process error. Error no: %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	printf("Process created");
	getchar();
	return TRUE;
}