/*
	[ 순수 가상 함수 (pure virtual function) ]
	 
	 몸체가 정의되지 않은 가상 함수
	 virtual void Print() = 0;


	[ 추상 클래스 (abstract class) ]

	클래스에 순수 가상 함수가 하나라도 있다면 해당 클래스는 추상클래스이다.
	추상 클래스는 객체를 생성할 수 없으며,
	추상 클래스를 상속받은 클래스는 순수 가상 함수를 필수로 override 해야한다.
	- C++에는 abstract 키워드가 없지만, visual studio에서는 인식해줌


	=> 추상클래스의 활용?
		인터페이스 역할

	=> 가상함수와의 차이점?
		가상함수는 구현이 있으므로 꼭 오버라이드하지 않아도 객체 생성이 가능하지만
		추상클래스는 꼭 오버라이드 해야 객체 생성이 가능하다
*/

#include <iostream>
using namespace std;

// 추상클래스
class Parent abstract
{
public:
	virtual void Print1() = 0;			// 순수 가상 함수 o
	virtual void Print2() abstract;		// 순수 가상 함수 o
	virtual void Print3() {};			// 순수 가상 함수 x

	// 순수 가상함수도 정의를 제공할 수 있다.
	// 하지만 꼭 오버라이드 해야함
	virtual void Print4() = 0
	{
		cout << "Parent::Print4()" << endl;
	}
};

class Child : public Parent
{
public:
	// 추상클래스를 상속 받으면,
	// 순수 가상 함수를 모두 override해야 객체 생성이 가능하다.
	void Print1() override
	{
		cout << "Child::Print1()" << endl;
	}

	void Print2() override
	{
		cout << "Child::Print2()" << endl;
	}

	void Print4() override
	{
		cout << "Child::Print4()" << endl;
	}
};

int main()
{
	//Parent parent;		// 순수 가상함수 객체 생성 불가

	Parent* list = new Child();

	list->Print1();
	list->Print2();
	list->Print3();
	list->Print4();
	list->Parent::Print4();

	delete list;
}