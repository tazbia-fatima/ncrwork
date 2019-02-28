//Program to write data to file.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<string.h>
int main(int argc, LPTSTR argv[]) {
	HANDLE hfile;
	//TCHAR buffer[] = TEXT("HI WRITING SUCCESSFULLY DONE\n");
	//_tprintf("Enter the string you want to write to file");
	int Buffsize = strlen(argv[2]);
	TCHAR* buffer;
	buffer = (TCHAR*)malloc(sizeof(TCHAR)*Buffsize);
	strcpy(buffer, argv[2]);
	if (argc > 3 || argc < 3) { //for no of command lines args i.e only 1 file name as argument
		_tprintf(_T("Wrong no. of arguments i.e %d. Must enter only 1 file name as argument"), argc);
		getchar();
		return FALSE;
	}
	hfile = CreateFile(argv[1], GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (INVALID_HANDLE_VALUE == hfile) {
		_tprintf(_T("File couldn't be opened/created. Error no : %d"), GetLastError());
		getchar();
		return FALSE;
	}
	DWORD dwNoOfBytesWritten, dwNoOfBytesToWrite;
	dwNoOfBytesToWrite = strlen(buffer) + 1;
	BOOL return_val = WriteFile(hfile,buffer,dwNoOfBytesToWrite,&dwNoOfBytesWritten,NULL);//overwrites existing content
	if (0 == return_val) { //to check if writefile failed
		_tprintf(_T("Writing of file - %s failed."), argv[1]);
		getchar();
		return FALSE;
	}
	if (dwNoOfBytesWritten != dwNoOfBytesToWrite) {
		_tprintf(_T("Writing not performed perfectly"));
		return FALSE;
	}
	_tprintf("Writing successful. Check file");
	CloseHandle(hfile);
	getchar();
	return TRUE;
}