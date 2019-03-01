#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#define BUFFSIZE 100
int _tmain(int argc, TCHAR *argv[]) {
	_tprintf(_T("XYXZ"));
	HANDLE hfile;
	TCHAR buffer1[BUFFSIZE];
	STARTUPINFO strt_info;
	PROCESS_INFORMATION proc_info;
	SECURITY_ATTRIBUTES sec_attr_h;
	//HANDLE hproc;
	ZeroMemory(&strt_info, sizeof(strt_info));
	strt_info.cb = sizeof(strt_info);
	ZeroMemory(&proc_info, sizeof(proc_info));
	sec_attr_h.bInheritHandle = TRUE;
	//sec_attr_p.bInheritHandle = TRUE;
	//DWORD dwNoOfBytesRead;
	if (argc != 2) { //for no of command lines args i.e only 1 file name as argument
		_tprintf(_T("Wrong no. of arguments i.e %d. Must enter only 1 file name as argument"), argc);
		getchar();
		return FALSE;
	}
	hfile = CreateFile(argv[1], GENERIC_READ, FILE_SHARE_READ,&sec_attr_h, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL); //opening file and assigning handler
	if (INVALID_HANDLE_VALUE == hfile) { //if file isnt found
		_tprintf(_T("File doesn't exist. Error no : %d"), GetLastError());
		getchar();
		return FALSE;
	}
	
	_tprintf(_T("File named %s is open"), argv[1]);
	printf("BEFORE CREATE");
	LPSTR handle1 = (LPSTR)hfile;
	if (!CreateProcess("C:\\Users\\cdac\\Documents\\ncrwork\\windows\\Debug\\question8-readfile.exe",
		handle1, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &strt_info, &proc_info)) {
		_tprintf(_T("create process error. Error no: %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	printf("AFTER CREATE");
	getchar();
	return TRUE;
}