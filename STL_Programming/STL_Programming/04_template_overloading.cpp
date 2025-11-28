/*
	일반 함수와 템플릿 함수가 모두 있는 경우
	일반 함수가 우선 호출된다.

	>> 우선 호출 순서
		1. 일반함수
		2. 특수화 템플릿 함수
		3. 템플릿 함수
*/

#include <iostream>
using namespace std;

// 일반 함수
int Add(int a, int b)
{
	cout << "일반 함수 int Add(int, int) 호출" << endl;
	return a + b;
}

// 템플릿 함수
template <class T>
T Add(T a, T b)
{
	cout << "템플릿 함수 T Add<T>(T, T) 호출" << endl;
	return a + b;
}

// 템플릿 특수화
template <>
double Add(double a, double b)
{
	cout << "템플릿 특수화 double Add<double>(double, double) 호출" << endl;
	return a + b;
}

int main()
{
	Add(1, 2);			// 일반 함수
	Add(1.0, 2.0);		// 템플릿 특수화
	Add('A', 'B');		// 템플릿 함수
}