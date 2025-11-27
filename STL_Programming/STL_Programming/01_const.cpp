/*
	[ const ]

	const 키워드는 읽기 전용 객체로 사용하겠다는 키워드로,
	const로 선언한 객체들은 읽기 전용 상수로 사용된다. (수정 불가)

	- 일반 변수
		const int data = 10;		-> 값 변경 불가

	- 포인터 변수
		const int* ptr1 = &a;		-> 역참조 값 변경 불가
		int* const ptr2 = &a;		-> 포인터 주소 변경 불가
		const int* const ptr3 = &a; -> 역참조 값, 포인터 주소 모두 변경 불가

	- 참조 변수
		const int& ref = a;			 -> 값 변경 불가
*/

#include <iostream>
using namespace std;

int main()
{
	// 일반 변수 const
	{
		// 일반 변수 -> 수정 가능
		int a = 10;
		a = 20;

		// const 변수  ->  수정 불가능
		const int ca = 10;
		ca = 20;
	}
	

	// 포인터 변수 const
	// 포인터 변수의 경우 두 부분에 const를 붙일 수 있다.
	// 1. T* const ___ : 포인터 주소 const
	// 2. const T* ___ : 역참조 값 cosnt
	// 3. const T* const ___ : 포인터 주소도 변경 불가, 포인터가 가리키는 값도 변경 불가
	{
		int a = 10;
		int b = 10;

		// 일반 포인터
		int* ptr1 = &a;
		*ptr1 = 20;				// 역참조 값 변경 o
		ptr1  = &b;				// 포인터 주소 변경 o

		// 포인터 주소 const
		int* const ptr2 = &a;
		*ptr2 = 10;			    // 역참조 값 변경 o
		ptr2  = &b;			    // 포인터 주소 변경 x

		// 역참조 값 const
		const int* ptr3 = &a;
		*ptr3 = 20;				// 역참조 값 변경 x
		ptr3  = &b;				// 포인터 주소 변경 o

		// 전부 cosnt
		const int* const ptr4 = &a;
		*ptr4 = 20;				// 역참조 값 변경 x
		ptr4  = &b;				// 포인터 주소 변경 x
	}


	// 참조 변수 const
	{
		int a = 10;
		int b = 10;

		const int& c_cref = a;				// 값 변경 x
	}
}