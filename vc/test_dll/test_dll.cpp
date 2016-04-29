// test_dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "stdio.h"
#include "CallFunc.h"

#define CTYPE extern "C"
#define DLL_API __declspec( dllexport )

//#define API_TYPE __stdcall
#define API_TYPE __cdecl


// set / get test
int g_n = 0;

CTYPE DLL_API int API_TYPE SET_VALUE(int n)
{
	g_n = n;

	return n;
}

CTYPE DLL_API int API_TYPE GET_VALUE()
{
	return g_n;
}


// function pointer test
CTYPE DLL_API int API_TYPE RUN_FUNC_PTR(callbackFuncPtr pFn, int n)
{
	if ( pFn )
		return pFn(n);

	return -1;
}

// callback test
callbackFuncPtr  g_pFn = NULL;

CTYPE DLL_API int API_TYPE SET_CALLBACK(callbackFuncPtr pFn)
{
	g_pFn = pFn;

	return 0;
}

CTYPE DLL_API int API_TYPE RUN_CALLBACK(int n)
{
	if ( g_pFn )
		return g_pFn(n);

	return -1;
}

// class callback test
CCallFunc		g_callFunc;

CTYPE DLL_API void API_TYPE SET_CLASS_CALLBACK(callbackFuncPtr pFn)
{
	g_callFunc.SetCallbackFunc(pFn);
}

CTYPE DLL_API int API_TYPE RUN_CLASS_CALLBACK(int n)
{
	return g_callFunc.Run(n);
}

// thread callback test
callbackFuncPtr  g_pThreadFn = NULL;

DWORD API_TYPE ThreadFunc (PVOID pvParam)
{
	printf("running thread\n");
	Sleep(1000);

	if ( g_pThreadFn )
		g_pThreadFn(5);

	printf("exit thread\n");
	return 0;
}

CTYPE DLL_API void API_TYPE SET_THREAD_CALLBACK(callbackFuncPtr pFn)
{
	g_pThreadFn = pFn;

	DWORD dwThreadID;
	HANDLE hThread = CreateThread( NULL, 0, ThreadFunc, NULL, 0, &dwThreadID);
}

// test dynamic class callback

CCallFunc* g_pCallFunc =NULL;

CTYPE DLL_API void API_TYPE INIT_CLASS()
{
	g_pCallFunc = new CCallFunc();
}


CTYPE DLL_API void API_TYPE SET_D_CLASS_CALLBACK(callbackFuncPtr pFn)
{
	if ( g_pCallFunc )
		g_pCallFunc->SetCallbackFunc(pFn);
}

CTYPE DLL_API int API_TYPE RUN_D_CLASS_CALLBACK(int n)
{
	if ( g_pCallFunc )
		return g_pCallFunc->Run(n);

	return -1;
}
