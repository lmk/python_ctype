# python에서 ctype을 이용한 c library 연동 예제

**python의 ctype 모듈을 이용해서 visual c++로 작성한 동적 dll을 읽는 sample 코드 입니다.**


## 소스 코드 설명

* [/vc/test_dll](https://github.com/lmk/python_ctype/tree/master/vc/test_dll): 동적 dll 코드 입니다. 

  * [SET_VALUE](https://github.com/lmk/python_ctype/blob/master/vc/test_dll/test_dll.cpp#L18): int 형 값을 저장합니다.
  * [GET_VALUE](https://github.com/lmk/python_ctype/blob/master/vc/test_dll/test_dll.cpp#L25): 저장한 int형 값을 읽어 옵니다.
  * [SET_CALLBACK](https://github.com/lmk/python_ctype/blob/master/vc/test_dll/test_dll.cpp#L32): 함수 포인터를 저장합니다. python으로 코딩한 함수를 넘길 것 입니다.
  * [RUN_CALLBACK](https://github.com/lmk/python_ctype/blob/master/vc/test_dll/test_dll.cpp#L50): 저장한 함수 포인터에 정수형 값을 넘겨 실행 합니다. 실행하면 python함수가 실행될 것 입니다.
  * [SET_CLASS_CALLBACK](https://github.com/lmk/python_ctype/blob/master/vc/test_dll/test_dll.cpp#L61): c++ class를 사용해서 함수 포인터를 저정합니다.
  * [RUN_CLASS_CALLBACK](https://github.com/lmk/python_ctype/blob/master/vc/test_dll/test_dll.cpp#L66): c++ class를 사용해서 저장한 함수 포인터를 실행합니다.
  * [SET_THREAD_CALLBACK](https://github.com/lmk/python_ctype/blob/master/vc/test_dll/test_dll.cpp#L86): 함수 포인터를 저장하고, thread 에서 1초 후 함수를 실행합니다.
  * [INIT_CLASS](https://github.com/lmk/python_ctype/blob/master/vc/test_dll/test_dll.cpp#L98): c++ class를 동적으로 생성합니다.
  * [SET_D_CLASS_CALLBACK](https://github.com/lmk/python_ctype/blob/master/vc/test_dll/test_dll.cpp#L104): 동적으로 생성한 class를 사용해서 함수 포인터를 저장합니다.
  * [RUN_D_CLASS_CALLBACK](https://github.com/lmk/python_ctype/blob/master/vc/test_dll/test_dll.cpp#L110): 동적으로 생성한 class를 사용해서 함수 포인터를 실행합니다.

* [/vc/call_dll](https://github.com/lmk/python_ctype/tree/master/vc/call_dll): test_dll을 LoadLibrary() 해서 순서대로 테스트 하는 c++ 코드 입니다.(test_dll.dll 파일의 경로는 맞게 수정해야 동작합니다)
* [/python](https://github.com/lmk/python_ctype/tree/master/python): 동적 dll 읽어 순서대로 테스트 하는 python 코드 입니다.(test_dll.dll 파일의 경로는 맞게 수정해야 동작합니다)
