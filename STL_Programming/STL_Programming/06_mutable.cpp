/*
	[ mutable ]

	mutable은 상수 객체에서도 변경 가능한 멤버 변수를 정의하는 키워드로,
	mutable 키워로 선언된 멤버변수는 const 멤버 함수나 상수 객체에서 변경이 가능하다.
*/

#include <iostream>

class MyClass
{
public:
	mutable int data = 0;				// mutable
	void Add() const { data += 1; }		// const 멤버 함수에서 mutable 변수 변경
};

int main()
{
	// 상수객체에서 mutalbe 변수 변경
	const MyClass my;
	my.data = 20;			
	my.Add();
}