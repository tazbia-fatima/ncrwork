#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#define BUFFSIZE 100
int _tmain(int  argc,LPTSTR argv[]){
	HANDLE hfile;
	TCHAR buffer1[BUFFSIZE];
	DWORD dwNoOfBytesRead;
	if (argc > 2 || argc < 2) { //for no of command lines args i.e only 1 file name as argument
		_tprintf(_T("Wrong no. of arguments i.e %d. Must enter only 1 file name as argument"),argc);
		getchar();
		return FALSE;
	}
	hfile = CreateFile(argv[1],GENERIC_READ,0,NULL,OPEN_EXISTING,FILE_ATTRIBUTE_NORMAL,NULL); //opening file and assigning handler
	if (INVALID_HANDLE_VALUE == hfile){ //if file isnt found
		_tprintf(_T("File doesn't exist. Error no : %d"),GetLastError());
		getchar();
		return FALSE;
	}
	_tprintf(_T("File named %s is open"),argv[1]);
	while (1) { //to print every line in the file and not just single one
		ZeroMemory(buffer1, BUFFSIZE);//refreshing buffer after everyline
		BOOL return_val = ReadFile(hfile, buffer1, BUFFSIZE, &dwNoOfBytesRead, NULL);
		if (0 == return_val) { //to check if readfile failed
			_tprintf(_T("Reading of file - %s failed."), argv[1]);
			getchar();
			return FALSE;
		}
		if ( return_val && 0 == dwNoOfBytesRead) {
			_tprintf(_T("Reached EndOfFile"));
			break;
		}
		_tprintf(_T("\n%s"), buffer1); // as project is ANSI coded
		//_tprintf(_T("Contents from File - %s successful read as : %S"),argv[1],buffer1);
	}
	CloseHandle(hfile);
	getchar();
	return TRUE;
}