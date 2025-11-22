//추상 클래스(abstract class)
//      하나 이상의 순수 가상 함수를 포함하는 클래스
//      순수 가상 함수를 포함하고 있으므로, 인스턴스를 생성할 수 없다.
//      상속을 통해 멤버 함수를 반드시 만들어서 사용해야 한다.

//순수 가상 함수(pure virtual function)
//
//    가상 함수(virtual function)는 파생 클래스에서 재정의할 것으로 기대하는 멤버 함수를 의미합니다.
//    따라서 가상 함수는 반드시 재정의해야만 하는 함수가 아닌, 재정의가 가능한 함수를 가리킵니다.
//
//    이와는 달리 순수 가상 함수(pure virtual function)란 
//    파생 클래스에서 '반드시' 재정의해야 하는 멤버 함수를 의미합니다. ***


/*
    class Animal abstract {
    public:
        Animal() {}
        virtual ~Animal() {}          //추상클래스도 일반함수 선언 가능
        virtual void speak() = 0;
    };
*/

#include <iostream>
using namespace std;

class Electronics                           // abstract
{
public:
    virtual void power_on() = 0;            //
    virtual ~Electronics() = 0 {}
};

void Electronics::power_on() { cout << "Electronics Power ON !!" << endl; }    //추상클래스에서 내부를 구현도 가능 ***

class Television : public Electronics
{
public:
    void power_on()                         //반드시 재정의
    {
        Electronics::power_on();            //기본 구현 호출
        cout << "Television Power ON !!" << endl;
    }
};

class PlayStation : public Electronics
{
public:
    void power_on()                         //반드시 재정의
    {
        Electronics::power_on();
        cout << "PlayStation Power ON !!" << endl;
    }
};

int main()
{
    //Electronics *pElectronic = new Electronics(); // 생성할 수 없음


    Electronics* pTV = new Television();                // 업캐스팅
    Electronics* pPlayStation = new PlayStation();

    pTV->power_on();
    pPlayStation->power_on();

    delete pTV;
    delete pPlayStation;

    return EXIT_SUCCESS;
}

/*
추상 클래스의 용도 제한
        C++에서 추상 클래스는 다음과 같은 용도로는 사용할 수 없습니다.

    1. 변수 또는 멤버 변수
    2. 함수의 전달되는 인수 타입
    3. 함수의 반환 타입
    4. 명시적 타입 변환의 타입

추상 클래스는
    비록 객체는 생성할 수 없지만,
    추상 클래스를 가리키는 '포인터'는 문제 없이 만들 수 있다.

*/


//Pure Virtual Destructor(순수 가상 소멸자)
//
//  순수 가상 함수가 하나도 없는 클래스를, 추상 클래스로 만들고 싶을때에는 
//  소멸자를 순수 가상 함수로 만든다.
//  순수 가상 소멸자의 정의를 반드시 해줘야 한다. ***

/*
struct MyClass {
    MyClass();
    virtual ~MyClass() = 0;  //순수 가상 소멸자  
};

MyClass::~MyClass() {} // 반드시 정의 필요

*/

#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() {}
    virtual ~MyClass() = 0 {}; //순수 가상 소멸자 
};

class MyClass2: public MyClass {
public:
    MyClass2() {}
    virtual ~MyClass2() {}
};

int main(int argc, const char* argv[])
{
    MyClass a;		//error
    MyClass2 b;

    return 0;
}

//가상 소멸자
//  가상 소멸자는 상속과 다형성 구조에서 객체의 안전한 소멸과 메모리 누수 방지를 위해 필수적입니다.
//  다형성을 가진 기본 클래스에는 반드시 가상 소멸자를 선언하세요.
//  순수 가상 소멸자는 추상 클래스 설계에도 활용할 수 있습니다

//객체 생성 및 소멸 과정 중에는 절대로 가상 함수를 호출하지 말자. ***
//  가상 함수라고 해도, 
//  지금 실행중인 생성자나 소멸자에 해당되는 클래스의 파생 클래스 쪽으로는 이동하지 않는다.


