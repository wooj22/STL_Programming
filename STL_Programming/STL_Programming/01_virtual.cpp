/*
* 
	[ 정적 바인딩(static binding) / 동적 바인딩(dynamic binding) ]

    - 정적 바인딩 (compile-time dispatch)
        C++의 기본 동작 방식으로 함수 호출이 컴파일 시점에 결정되며,
        호출되는 함수는 포인터(또는 참조)의 타입을 기준으로 선택된다.
		ex) Base* b = new Derived(); 
			b->print(); // Base::print() 호출 (컴파일 타임 결정)

    - 동적 바인딩 (runtime dispatch)
        런타임에 호출 함수가 결정된다.
        다형성을 위해 사용되며, 이를 활성화하는 키워드가 virtual이다.
        virtual이 있는 경우, 실제 객체 타입 기준으로 함수가 호출된다.
		ex) Base* b = new Derived();
			b->print(); // Derived::print() 호출 (런타임 결정)
 

	[ 가상 함수 (virtual function) ]

	부모 클래스의 멤버 함수에 virtual을 붙이면 해당 함수는 가상 함수가 된다.
    가상 함수는 실제 객체 타입(Derived)에 따라 재정의된 함수가 호출되며,
    이를 통해 C++에서 런타임 다형성(polymorphism)을 구현한다.
    virtual은 상속되어, 자식에서 다시 virtual을 붙이지 않아도 계속 가상 함수로 동작한다.


	[ 가상 함수 테이블 (vtable) ]

    클래스가 하나라도 virtual 함수를 가진다면, 컴파일러는 그 클래스에 대해 가상 함수 테이블(vtable)을 생성한다.
    가상 함수 테이블에는 해당 클래스에서 사용할 virtual 함수들의 함수 포인터 목록이 들어있으며,
    이 클래스의 객체들은 가상 함수테이블을 가리키는 포인터(vptr)을 가진다.
    객체들이 함수를 호출하면 vptr → vtable을 통해 런타임에 어떤 함수를 호출할지 찾아 호출한다.
    - 가상함수테이블(vtable)은 클래스당 하나
    - 포인터(vptr)은 객체당 하나

    즉, vptr + vtable 구조 덕분에
    Base* 포인터로 Derived 객체를 가리켜도
    Derived에서 재정의한 함수가 실행되는 것이다.

    
    ! virtual 소멸자
    소멸자에 virtual키워드를 붙이는건 상속 구조에서 아주 중요한 문제다.
    다형성을 사용하는 상황에서 부모 타입의 포인터로 자식 객체를 가리키고
    delete한다면 C++의 기본인 정적 바인딩을 통해 부모의 소멸자만 호출될 것이다.
    때문에 올바른 소멸자 호출을 위해 상속구조에서는 무조건 소멸자에 virtual 키워드를 붙여줘야한다.
*/

#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Base::Base()" << endl; }
    virtual ~Base() { cout << "Base::~Base()" << endl; }

    // virtual
    virtual void Print()
    {
        cout << "Base::Print()" << endl;
    }
};

class Derived : public Base
{
public:
    Derived() { cout << "Derived::Derived()" << endl; }
    virtual ~Derived() { cout << "Derived::~Derived()" << endl; }

    // override
    void Print() override
    {
        cout << "Derived::Print()" << endl;
    }
};

class DerivedDerived : public Derived
{
public:
    DerivedDerived() { cout << "DerivedDerived::DerivedDerived()" << endl; }
    virtual ~DerivedDerived() { cout << "DerivedDerived::~DerivedDerived()" << endl; }

    // override
    void Print() override
    {
        cout << "DerivedDerived::Print()" << endl;
    }
};

int main()
{
    // virtual 함수 호출
    Base* base = new Derived();
    base->Print();          // Derived::Print()

    Base* basebase = new DerivedDerived();
    basebase->Print();      // DerivedDerived::Print()

    delete base;
    delete basebase;
}