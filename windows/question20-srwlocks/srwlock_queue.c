//Write a program where there is a shared queue of fixed size between reader and writer threads.
//Say the queue size is 5, readers are 2 and writers are 4. 
//Synchronize the execution of reader and writer threads via Slim Reader - Writer locks and condition variables.
//Use InitializeSRWLock, AcquireSRWLockExclusive, ReleaseSRWLockExclusive, AcquireSRWLockShared, ReleaseSRWLockShared, SleepConditionVariableSRW, WakeConditionVariable, WakeAllConditionVariable APIs.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<tchar.h>
#include<string.h>