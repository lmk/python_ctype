#-*- coding: utf-8 -*-
import time
from ctypes import *

def OnCallback(ret):
    print "    OnCallback: ", ret
    return ret * 10

fp_callback = CFUNCTYPE(c_int, c_int)
c_pyfunc = fp_callback(OnCallback)

hDll = CDLL("D:\\Documents\\Visual Studio 2010\\Projects\\test_dll\\x64\\Debug\\test_dll.dll")

## get / set test
hDll.GET_VALUE.restype = c_int
hDll.SET_VALUE(1)
result = hDll.GET_VALUE()
print "GET/SET result is", result, "\n"

## function pointer test
hDll.RUN_FUNC_PTR.restype = c_int
result = hDll.RUN_FUNC_PTR(fp_callback(OnCallback), 2)
print "FUNC PTR result is", result, "\n"

## callback test
hDll.RUN_CALLBACK.restype = c_int
hDll.SET_CALLBACK(c_pyfunc)
try:
    result = hDll.RUN_CALLBACK(3)
except:
    print "CALLBACK Test Fail!!!\n"
else:
    print "CALLBACK result is", result, "\n"

## class callback test
hDll.RUN_CLASS_CALLBACK.restype = c_int
hDll.SET_CLASS_CALLBACK(c_pyfunc)
try:
    result = hDll.RUN_CLASS_CALLBACK(4)
except:
    print "Class CALLBACK Test Fail!!!\n"
else:
    print "Class CALLBACK result is", result, "\n"


## thread callback test (just die..)
#hDll.SET_THREAD_CALLBACK(fp_callback(OnCallback))



## waiting
for i in range(5):
    print "wait..", i
    time.sleep(1)

