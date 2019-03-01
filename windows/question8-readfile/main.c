#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#define BUFFSIZE 100
int _tmain(int  argc, LPTSTR argv[]) {
	_tprintf(_T("HERE : %s\n"), argv[0]);
	HANDLE h1 = (HANDLE)argv[0];
	TCHAR buffer1[BUFFSIZE];
	DWORD dwNoOfBytesRead;
	//if (argc != 2) { //for no of command lines args i.e only 1 file name as argument
	//	_tprintf(_T("Wrong no. of arguments i.e %d. Must enter only 1 file name as argument"), argc);
	//	getchar();
	//	return FALSE;
	//}
	_tprintf(_T("In process"));
	while (1) { //to print every line in the file and not just single one
		ZeroMemory(buffer1, BUFFSIZE);//refreshing buffer after everyline
		BOOL return_val = ReadFile(h1, buffer1, BUFFSIZE, &dwNoOfBytesRead, NULL);
		if (0 == return_val) { //to check if readfile failed
			_tprintf(_T("Reading of file - %s failed."), argv[0]);
			getchar();
			return FALSE;
		}
		if (return_val && 0 == dwNoOfBytesRead) {
			_tprintf(_T("Reached End_Of_File"));
			break;
		}
		_tprintf(_T("\n%s"), buffer1); // as project is ANSI coded
									   //_tprintf(_T("Contents from File - %s successful read as : %S"),argv[1],buffer1);
	}

	//CloseHandle(argv[1]);
	getchar();
	return TRUE;
}