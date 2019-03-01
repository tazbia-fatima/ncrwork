#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<string.h>
int _tmain() {
	HANDLE g_hEvent = CreateEvent(NULL, FALSE, FALSE, TEXT("Tazbia_Event"));
	if (INVALID_HANDLE_VALUE == g_hEvent) {
		_tprintf(_T("Error in creating handle. Error no :%d"), GetLastError());
		getchar();
		return FALSE;
	}
	//_tprintf(_T("%d\n"), g_hEvent);
		getchar();
	return TRUE;

}