//C++의 네가지 타입변환 연산자 
//	    satic_cast, dynamic_cast, reinterpret_cast, const_cast

//dynamic_case<new_type>(expression)
//		safe downcasting(안전한 다운캐스팅)에 사용이 됩니다.
//      부모 클래스의 포인터에서 자식 클래스의 포인터로 다운 캐스팅 해주는 연산자.
//      런타임 시간에 실제로 해당 타입이 다운 캐스팅이 가능한지 검사. ***

//      Class의 포인터 간 형 변환 시, 안전하게 down casting을 위해 사용합니다.
//      Class의 참조변수 간 형 변환 시, 안전하게 down casting을 위해 사용합니다.
//      단, parent에 virtual 함수가 존재해야 정상 동작합니다.

//  성공할 경우 : new_type의 value를 return 합니다.
//  실패할 경우(new_type = pointer) : null pointer 
//  실패할 경우(new_type = reference) : bad_cast(exception 처리됩니다.)


/*
"부모클래스의 생성자로 생성되었고 부모 포인터가 가리키고 있는 클래스"를 
자식클래스 포인터로 형변환(dynamic_cast) 할 때.
	- runtime error, 자식클래스는 생성되지도 않았으므로.

"자식클래스의 생성자로 생성되었고 부모클래스 포인터가 가리키고 있는 클래스"를 
자식클래스로 형변환(dynamic_cast) 할 때
	- 자식클래스의 포인터로 다운캐스팅이 잘 됩니다

"자식클래스의 생성자로 생성되었고 자식클래스 포인터가 가리키고 있는 클래스"를, 
부모클래스로 형변환 할 때는 
	- dynamic_cast를 사용하지 않고 static_cast를 사용합니다.
*/

#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Base()\n"; };
    virtual ~Base() { cout << "~Base()\n"; };

    void Show() { cout << "This is Base Class\n"; }
};

class Derived : public Base
{
public:
    Derived() { cout << "Derived()\n"; };
    virtual ~Derived() { cout << "~Derived()\n"; };

    void Show() { cout << "This is Derived Class\n"; }
};

int main(void)
{
    Base* pBase = new Derived();
    pBase->Show();

    Derived* pDerived = dynamic_cast<Derived*>(pBase);
    if (pDerived == nullptr)
    {
        cout << "Runtime Error\n";
    }
    else
    {
        pDerived->Show();       //Derived 로 생성되었으므로 문제없음
    }

    delete pBase;

    system("pause");
    return 0;
}