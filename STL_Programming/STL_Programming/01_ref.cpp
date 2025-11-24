/*
	[ reference (&) ]

	참조 변수는 기존 변수를 참조하여 메모리를 공유한다.
	참조 변수는 선언과 동시에 참조해야하며, 참조 대상을 변경할 수 없다.
	기본적으로 lvalue 참조만 가능하며, rvalue는 cosnt&로만 참조할 수 있다.
	(모던에서는 rvalue참조 (&&) 문법이 등장한다)
*/

#include <iostream>
using namespace std;


int main(void)
{
	// 일반 lvalue 참조
	{
		int a = 0;
		int& a_ref = a;
		a_ref = 1;
		cout << "a의 주소 : " << &a << "  a의 값 : " << a << endl;
		cout << "a_ref의 주소 : " << &a_ref << "  a_ref의 값 : " << a_ref << endl;
	
		// 참조변수 참조도 가능
		int a_ref_ref = a_ref;
		cout << "a_ref_ref의 주소 : " << &a_ref_ref << "  a_ref_ref의 값 : " << a_ref_ref << endl;
	}


	// rvalue 참조
	{
		const int& rvalue_ref1 = 100;	// C++
		int&& rvalue_ref2 = 200;		// 모던 C++
	}


	// const 참조
	{
		int a = 0;
		const int& ra = a;
	}


	// 참조변수는 선언과 동시에 초기화해야한다.
	// 여기서 초기화란 참조 대상인 변수의 참조를 의미한다.
	{
		//int& r1;
		//int& r2 = NULL;
		//int& r3 = 10;
		//
		//// 참조 변수는 참조 대상의 변경이 불가능하다
		//rra = &a;
	}
}