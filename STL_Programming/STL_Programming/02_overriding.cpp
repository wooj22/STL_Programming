/*
	[ overriding ]

	오버라이딩은 기반 클래스(Base)의 가상 함수(virtual)를
    파생 클래스(Derived)에서 동일한 함수 시그니처로 재정의하여,
	부모 클래스의 virtual 함수에 대응하는 가상함수테이블 슬롯을
	재정의한 함수 포인터로 교체함으로써 동적 바인딩을 가능하게 하는 기능이다.
	
	함수의 확장이 아닌 재정의이기 때문에 부모의 함수까지 사용하고싶다면
	함수 본문에서 부모의 함수를 따로 호출해줘야한다. Base::print()

	overriding 조건
	1) virtual 키워드가 붙은 가상 함수여야함
	    -> virtual이 있으면 동적 바인딩
		-> virtual이 없으면 오버라이딩이 아니라 함수 숨김(hiding)이 됨
	
	2) 반환 타입, 함수 이름, 매개변수 타입이 모두 같아야함
		-> 다르면 오버로딩임
		-> 반환타입에 대해서만 예외 적용(공변 반환 규칙)

	3) override 키워드
		virtual 함수를 재정의했다면 오버라이딩이 되지만,
		코드의 직관성을 위해 override 키워드를 붙이는 것이 좋다.
		override 키워드를 붙이면 오버라이드가 아닐 경우의 오류까지 잡아준다.


	[ final ]

	virtual 함수가 더이상 오버라이딩되지 않도록 막는 키워드이다.

	- class final : 더 이상 상속 불가
	- function final : 더 이상 오버리아딩 불가
*/

#include<iostream> 
using namespace std;

class Base {
public:
	virtual void Print()	    // vritual
	{
		cout << "Base::Print()" << endl;
	}
};

class Derived1 : public Base {
public:
	void Print() override final   // overriding
	{
		cout << "Derived1::Print()" << endl;
	}
};

class Derived2: public Base {
public:
	void Print() override final   // overriding
	{
		cout << "Derived2::Print()" << endl;
	}
};


class Sub : public Derived1 {
public:
	//void Print() override;		   // overriding 불가
};


void main()
{
	Base* list[3];

	list[0] = new Base();
	list[1] = new Derived1();
	list[2] = new Derived2();

	list[0]->Print();
	list[1]->Print();
	list[2]->Print();

	delete list[0];
	delete list[1];
	delete list[2];
}
