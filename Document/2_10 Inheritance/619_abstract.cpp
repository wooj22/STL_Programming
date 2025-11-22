//순수 가상 함수(Pure Virtual Function)
//      순수 가상 함수는 즉, 함수의 몸체가 정의되지 않는 함수를 의미한다.

//추상 클래스 
//      하나 이상의 멤버 함수를 순수 가상 함수로 선언한 클래스를 추상 클래스라고 한다.
//      객체를 생성할수 없다. (포인터 변수는 가능)
 
//abstract 키워드
//      원래 추상 클래스는 기본 class 형식에 순수 가상함수를 포함하는 것으로 
//      딱히 기본 class와 구분짓는 방식이 없었다.
//      하지만 이후에 abstract 라는 키워드가 생겨나서 이 키워드를 붙여서 추상 클래스라는 것을 구분할 수 있다.

class Parent abstract               //추상 클래스
{
public:    
    virtual void func() = 0;        //순수가상함수.
    //virtual void func() abstract;   
};

class Child : public Parent
{
public:
    virtual void func();
};