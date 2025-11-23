#include "01_inline.h"

// 일반 함수
int Add(int a, int b)
{
    return a + b;
}

// inline 함수
inline int Add_Inline2(int a, int b)
{
	return a + b;
}

// 클래스 멤버 함수 inline
inline int Inline::Add_Inline2(int a, int b)
{
	return a + b;
}