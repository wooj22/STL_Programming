/*
	[ 상수 객체 ]

	객체를 cosnt로 선언할 경우 상수 객체가 되며
	객체는 상수로 취급되어 초기화된 데이터 외의 다른 데이터로 변경할 수 없다.
	상수객체는 const 멤버 함수만 호출 가능하다.
*/
#include <iostream>

class MyClass
{
public:
	int data = 10;
	void Show() const { std::cout << "Show() const\n"; }
	void Show()  { std::cout << "Show() non const\n"; }
};

int main()
{
	// 상수객체
	const MyClass my;	
	my.data = 20;			// 변경 불가
	my.Show();				// Show() const


	// 동적 할당시 const 위치에 주의!
	// 상수 객체
	const MyClass* myptr1 = new MyClass();
	myptr1->Show();			// Show() const

	// const 포인터 (상수 객체가 아님)
	MyClass* const myptr2 = new MyClass();
	myptr2->Show();			// "Show() non const
}