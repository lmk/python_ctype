#pragma once
#include "StdAfx.h"

typedef int (*callbackFuncPtr)(int);

class CCallFunc
{
public:
	CCallFunc(void);
	~CCallFunc(void);

	void SetCallbackFunc(callbackFuncPtr pFn);
	int Run(int n);

private:
	callbackFuncPtr _pCallbackFunc;
};

