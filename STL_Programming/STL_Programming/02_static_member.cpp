/*
	static 멤버 변수
		객체 단위가 아닌 클래스 단위로 존재하며, 모든 객체가 값을 공유한다.
		객체 없이 클래스 이름으로 접근이 가능하다
		반드시 클래스 외부에서 초기화가 필요하다.

	static 멤버 함수
		객체 없이 클래스 이름으로 호출 가능하다.
		static 멤버 변수만 사용할 수 있으며, this의 사용이 불가능하다.
		why? -> 아직 객체가 생성되지 않았을 수 있으므로
*/

#include <iostream>
using namespace std;

class MyClass
{
	int data = 0;

public:
	// static 멤버 변수
	static int count;

	// satic 멤버 함수
	static void Counting()
	{
		count++;
		//data++;				// 비정적 멤버 사용 불가
		//this->count++;		// this 사용 불가
	}
};

// 정적 멤버변수는 반드시 클래스 외부에서 초기화 필요
int MyClass::count = 0;

int main()
{
	// 객체 없이 이름으로 접근
	cout << MyClass::count << endl;
	MyClass::Counting();

	// 객체들끼리 공유
	MyClass my1;
	MyClass my2;
	cout << my1.count << endl;
	cout << my2.count << endl;
}