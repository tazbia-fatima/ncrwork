#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<string.h>
#define NoOfProc 2
static int count = 0;
void Create_Process(LPSTR file_path);
int _tmain(int argc, TCHAR *argv[], TCHAR *env[]) {
	/*STARTUPINFO strt_info;
	PROCESS_INFORMATION proc_info;
	SECURITY_ATTRIBUTES sec_attr;
	HANDLE hproc;
	ZeroMemory(&strt_info, sizeof(strt_info));
	strt_info.cb = sizeof(strt_info);
	ZeroMemory(&proc_info, sizeof(proc_info));
	sec_attr.bInheritHandle = TRUE;*/
	_tprintf("%d\n", argc);
	int noOfProcesses = atoi(argv[1]); //convertin string to int
	_tprintf("%d\n", noOfProcesses);
	if (argc != (2+noOfProcesses)) { //1st arg - default, 2nd arg-noofprocesses
		_tprintf(_T("USAGE =%s\n Give correct no.of arguments"), argv[0]);
		getchar();
		return FALSE;
	}
	for (int i = 1; i <= argv[1]; i++) {
		LPSTR f_path = argv[i]; //trying to convert tchar to lpstr
		Create_Process(f_path);
	}
	//if (!CreateProcess(NULL, argv[1], NULL, NULL, FALSE, 0, NULL, NULL, &strt_info, &proc_info)) {
	//		_tprintf(_T("create process error. Error no: %d\n"), GetLastError());
	//		getchar();
	//		return FALSE;
	//}
	//_tprintf(_T("The process handle is: %d"), &proc_info.hProcess);//as handle is a pointer.
	//_tprintf(_T("\nThe process ID is: %d"), proc_info.dwProcessId);
	///*int pid = GetProcessId(proc_info.hProcess);
	//_tprintf(_T("\nThe process ID is: %d"), pid);*/
	//_tprintf(_T("\nDONE with 1!"));
	getchar();
	return TRUE;
}
void Create_Process(LPSTR arg){
	count++;
	_tprintf(_T("\n%d"), count);
	STARTUPINFO strt_info;
	PROCESS_INFORMATION proc_info;
	SECURITY_ATTRIBUTES sec_attr;
	HANDLE hproc;
	ZeroMemory(&strt_info, sizeof(strt_info));
	strt_info.cb = sizeof(strt_info);
	ZeroMemory(&proc_info, sizeof(proc_info));
	sec_attr.bInheritHandle = TRUE;
	if (!CreateProcess(NULL, arg, NULL, NULL, FALSE, 0, NULL, NULL, &strt_info, &proc_info)) {
		_tprintf(_T("create process error. Error no: %d\n"), GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("The process handle is: %d"), proc_info.hProcess);//as handle is a pointer.
	_tprintf(_T("\nThe process ID is: %d"), proc_info.dwProcessId);
	/*int pid = GetProcessId(proc_info.hProcess);
	_tprintf(_T("\nThe process ID is: %d"), pid);*/
	_tprintf(_T("\nDONE with!"));
	
}