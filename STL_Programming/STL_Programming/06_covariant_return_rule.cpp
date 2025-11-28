/*
	[ 공변 반환 규칙 (covariant return rule) ]

	가상함수 오버라이드로 리턴타입에 대해서만 예외로 작용하는 규칙으로,
	public 상속 관계이면서 각자 자신의 타입을 포인터 또는 참조형으로 return하는 경우
	override로 인정한다.
*/
#include <iostream>
using namespace std;

class Base
{
public:
	virtual ~Base() = default;

	// 가상함수
	virtual Base* Clone_pointer()
	{
		cout << "Base::Clone()" << endl;
		return new Base();
	}

	virtual Base& Clone_ref()
	{
		cout << "Base::Clone()" << endl;
		Base* temp = new Base();
		return *temp;

		// 주의 delete 못함 (예제를 위한 코드)
	}
};

class Derived : public Base
{
public:
	// 반환타입이 다르지만 override 인정
	Derived* Clone_pointer() override
	{
		cout << "Derived::Clone()" << endl;
		return new Derived();
	}

	Derived& Clone_ref() override
	{
		cout << "Derived::Clone()" << endl;
		Derived* temp = new Derived();
		return *temp;

		// 주의 delete 못함 (예제를 위한 코드)
	}
};

int main()
{
	Base* derived = new Derived();
	auto* ptr = derived->Clone_pointer();
	auto& ref = derived->Clone_ref();
}