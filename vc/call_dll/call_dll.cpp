// call_dll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>

typedef int (*callbackFuncPtr)(int);

int callback_function(int n)
{
	printf("callback function arg:%d\n", n);

	return n+10;
}

int _tmain(int argc, _TCHAR* argv[])
{
	HMODULE hModule = LoadLibrary(L"D:\\Documents\\Visual Studio 2010\\Projects\\test_dll\\x64\\Debug\\test_dll.dll");
	if ( hModule == NULL )
	{
		printf("Load Fail\n");
		exit(1);
	}

	PVOID func = NULL;

	// test  get/set 
	func = GetProcAddress(hModule, "SET_VALUE");
	if( func )
	{
		printf("Call SET_VALUE\n");
		int(WINAPI* SET_VALUE)(int) = (int(WINAPI*)(int))func;
		SET_VALUE(1);
	}

	func = GetProcAddress(hModule, "GET_VALUE");
	if( func )
	{
		printf("Call GET_VALUE\n");
		int(WINAPI* GET_VALUE)(void) = (int(WINAPI*)(void))func;
		int n = GET_VALUE();
		printf("   n is %d\n\n", n);
	}


	// test function pointer 
	func = GetProcAddress(hModule, "RUN_FUNC_PTR");
	if( func )
	{
		printf("Call RUN_FUNC_PTR\n");
		int(WINAPI* RUN_FUNC_PTR)(callbackFuncPtr, int) = (int(WINAPI*)(callbackFuncPtr, int))func;
		RUN_FUNC_PTR(callback_function, 2);
		printf("\n");
	}

	// test callback
	func = GetProcAddress(hModule, "SET_CALLBACK");
	if( func )
	{
		printf("Call SET_CALLBACK\n");
		int(WINAPI* SET_CALLBACK)(callbackFuncPtr) = (int(WINAPI*)(callbackFuncPtr))func;
		SET_CALLBACK(callback_function);
	}

	func = GetProcAddress(hModule, "RUN_CALLBACK");
	if( func )
	{
		printf("Call RUN_CALLBACK\n");
		int(WINAPI* RUN_CALLBACK)(int) = (int(WINAPI*)(int))func;
		int n = RUN_CALLBACK(3);
		printf("   n is %d\n\n", n);
	}

	// test class callback
	func = GetProcAddress(hModule, "SET_CLASS_CALLBACK");
	if( func )
	{
		printf("Call SET_CLASS_CALLBACK\n");
		int(WINAPI* SET_CLASS_CALLBACK)(callbackFuncPtr) = (int(WINAPI*)(callbackFuncPtr))func;
		SET_CLASS_CALLBACK(callback_function);
	}

	func = GetProcAddress(hModule, "RUN_CLASS_CALLBACK");
	if( func )
	{
		printf("Call RUN_CLASS_CALLBACK\n");
		int(WINAPI* RUN_CLASS_CALLBACK)(int) = (int(WINAPI*)(int))func;
		int n = RUN_CLASS_CALLBACK(4);
		printf("   n is %d\n\n", n);
	}

	// test dynamic class callback
	func = GetProcAddress(hModule, "INIT_CLASS");
	if( func )
	{
		printf("Call INIT_CLASS\n");
		int(WINAPI* INIT_CLASS)(void) = (int(WINAPI*)(void))func;
		INIT_CLASS();
	}

	func = GetProcAddress(hModule, "SET_D_CLASS_CALLBACK");
	if( func )
	{
		printf("Call SET_D_CLASS_CALLBACK\n");
		int(WINAPI* SET_D_CLASS_CALLBACK)(callbackFuncPtr) = (int(WINAPI*)(callbackFuncPtr))func;
		SET_D_CLASS_CALLBACK(callback_function);
	}

	func = GetProcAddress(hModule, "RUN_D_CLASS_CALLBACK");
	if( func )
	{
		printf("Call RUN_D_CLASS_CALLBACK\n");
		int(WINAPI* RUN_D_CLASS_CALLBACK)(int) = (int(WINAPI*)(int))func;
		int n = RUN_D_CLASS_CALLBACK(5);
		printf("   n is %d\n\n", n);
	}

	// test thread callback
	/* Á×À½ 
	func = GetProcAddress(hModule, "SET_THREAD_CALLBACK");
	if( func )
	{
		printf("Call SET_THREAD_CALLBACK\n");
		int(WINAPI* SET_THREAD_CALLBACK)(int) = (int(WINAPI*)(int))func;
		SET_THREAD_CALLBACK(6);
		Sleep(1000);
		Sleep(1000);
		Sleep(1000);
	}
	*/

	return 0;
}

