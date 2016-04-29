#include "StdAfx.h"
#include "CallFunc.h"

CCallFunc::CCallFunc(void)
{
	_pCallbackFunc = NULL;
}


CCallFunc::~CCallFunc(void)
{
}

void CCallFunc::SetCallbackFunc(callbackFuncPtr pFn)
{
	_pCallbackFunc = pFn;
}

int CCallFunc::Run(int n)
{
	return _pCallbackFunc(n);
}