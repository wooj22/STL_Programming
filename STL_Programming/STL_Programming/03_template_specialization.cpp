/*
	[ 템플릿 특수화 (template <>)]

	특정 T 타입에 대해서 함수를 다르게 처리하고 싶을때 템플릿 특수화를 정의할 수 있다.
	template <> 선언 후 특정 타입의 개별 함수를 작성할 수 있고, 이 경우에는 T 타입을 사용하지 못한다.
*/

#include <iostream>
using namespace std;

template <class T>
T Max(T a, T b)
{
	return a > b ? a : b;
}

// char* 템플릿 특수화 
template <>
char* Max(char* a, char* b)
{
	cout << "char* Max<char*>(char* a, char* b)" << endl;
	return strlen(a) > strlen(b) ? a : b;
}

// const char* 템플릿 특수화
template <>
const char* Max(const char* a, const char* b)
{
	cout << "const char* Max<const char*>(const char* a, const char* b)" << endl;
	return strcmp(a, b) > 0 ? a : b;
}

int main(void)
{
	cout << Max(11, 15) << endl;
	cout << Max('T', 'Q') << endl;
	cout << Max(3.5, 7.5) << endl;

	cout << Max("Simple", "Best") << endl;	// const char* 특수화 템플릿 함수 호출

	char str1[] = "Simple";
	char str2[] = "Best";
	cout << Max(str1, str2) << endl;	// char* 특수화 템플릿 함수 호출

	return 0;
}
