//부모클래스 포인터 일 때, 어떤 자식클래스타입 인지 알아내기

#include <iostream>   

class Base
{
public:
    virtual ~Base() { }
};

class Derived1 : public Base { };

class Derived2 : public Base { };

void F(Base* pB)        // pB 가 어떤 객체를 가르키고 있을까?  
{
    // typeid 를 이용한 RTTI( Run Time Type Info ).   
    if (typeid(*pB) == typeid(Derived2))
    {
        std::cout << typeid(*pB).name() << std::endl;
    }
    else
    {
        std::cout << "No!" << std::endl;
    }

    // dynamic_cast 를 이용한 RTTI. ( 성공하면 cast된 pointer, 실패하면 null ( 0 ) 을 retrurn 한다. )   
    if (dynamic_cast<Derived2*>(pB))
    {
        std::cout << typeid(*pB).name() << std::endl;
    }
    else
    {
        std::cout << "No!" << std::endl;
    }
}

int main()
{
    Base* pB = new Derived2;
    Derived1* pD = new Derived1;
    F(pB);
    F(pD);

    return 0;
}


//부모클래스 포인터 일 때, 어떤 자식클래스타입 인지 알아내기

#include<iostream>
#include<typeinfo>
using namespace std;

class Parent {
public:
    Parent() {}
    virtual ~Parent() {}
};

class Child : public Parent {
public:
    Child() {}
};

int main()
{
    // 부모 클래스 선언
    Parent* pParent = new Parent();
    cout << typeid(pParent).name() << endl;

    // 다운 캐스팅
    Child* pChild = dynamic_cast<Child*>(pParent);
    cout << typeid(pChild).name() << endl;

    return 0;
}

//주의)
//  가상 함수가 없다면 dynamic_cast가 되지 않는다.