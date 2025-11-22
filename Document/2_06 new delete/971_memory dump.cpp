
//메모리 누수 결과를 디버그 결과 창에 표시하기  //F5 디버그모드로 실행하세요.

// for c	memalloc(): 파일(라인)이 추가됩니다.
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

// for c++	new: 파일(라인)이 추가됩니다. 
#ifdef _DEBUG 
#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 
#endif 
#endif

#include <memory>

int main(int argc, char* argv[])
{
	_CrtSetDbgFlag(0x21);

	int* c = (int*)malloc(10 * sizeof(int));

	int* cpp = new int[10];

	return 0;
}


/*
//메모리 누수 출력하기 -----------------------------------------

	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
	#include <iostream>
	using namespace std;

	void main()
	{
		int *p = new int();
		_CrtDumpMemoryLeaks();  //출력창에 메모리 누수 출력
		//system("pause");
	}
*/

/*
//F5 디버그모드로 실행하세요.

	#include <iostream>
	#include <Windows.h>

	#define _CRTDBG_MAP_ALLOC
	#include <cstdlib>
	#include <crtdbg.h>

	#ifdef _DEBUG
	#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	#endif

	int main()
	{
		_CrtSetBreakAlloc(86);

		byte* buff = new byte[100];

		_CrtDumpMemoryLeaks();

		return 0;
	}

*/