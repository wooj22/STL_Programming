//공변 반환 규칙 ( covariant return rule )
//		부모클래스의 함수 타입에 대하여 상속받은 클래스의 함수가 대체 가능한 경우
//		예외적으로 '리턴 타입'이 다른데도 오버라이딩이 가능하다.
 
// 리턴 타입은 달라도 부모-자식 관계이면서 자신의 타입을 리턴하는 경우

class Base
{
public:
	virtual Base* Clone() const { return new Base(); }			//Base*
};

class Derived : public Base
{
public:
	virtual Derived* Clone() const { return new Derived(); }	//Derived*
};

//파생 클래스에서 오버라이드하는 함수의 타입은 기본클래스의 그 가상 함수의 타입과 같아야 한다.
// 
// 단, 반환 타입 하나는 예외이다.
// C++에서는 원래의 반환 타입이 Base* 일 때 
// 파생 클래스 쪽에서 오버라이드한 함수의 반환 타입이 Derived* 이면 문제가 없다.
// 
// 단, 여기에도 단서가 하나 붙는데 
// Base는 Derived의 public 기본 클래스여야 한다. (B&, D& 까지 허용된다.)



#include <iostream>
using namespace std;

class A
{
public:
	void print() { cout << "A" << endl; }

	virtual A* getThis() { cout << "A::getThis()" << endl;	return this; }			//A* 
};

class B : public A
{
public:
	void print() { cout << "B" << endl; }

	virtual B* getThis() { cout << "B::getThis()" << endl;	return this; }			//B* 리턴 타입으로 오버라이딩
};

int main()
{
	A a;
	B b;

	A& ref = b;
	b.getThis()->print();			// B 출력
	ref.getThis()->print();			// A 출력	

	//virtual 이라 B::getThis() 가 호출되었으나
	//ref의 자료형이 A 클래스의 레퍼런스이므로, A* 형태의 주소로 인식되어 A::print()가 실행

	cout << typeid(b.getThis()).name() << endl;		// class B * 출력
	cout << typeid(ref.getThis()).name() << endl;	// class A * 출력

	return 0;
}

//Child와 Parent는 covariant한 타입이므로 
//오버라이딩시 타입을 각자 타입으로 다르게 해도 문제가 되지 않는다.
//파생된 클래스의 반환형이 호출에 따라, 상속한 여러 타입으로 반환될 수가 있다.


//Covariant Return Type (공변 반환)
// 
//	virtual 키워드를 통해 오버라이딩된 메서드에서
//	리턴 타입이 서로 상속 관계에 있고 해당 자료형은 포인터 형이거나 참조형
//	그리고 동일한 cv-qualifier 를 가져야 한다

//Covariant Return Type의 범위
//
//사용자가 함수를 바라볼 때 중요하게 여겨야 할 부분은 두 가지인데 바로 입력 값(범위)과 출력 값(범위)이다. 
//일반화된 용어를 사용하자면 "정의역"과 "공역" 이다.
//
//	입력 범위가 동일한 두 함수가 최종적으로 사용자에게 동일한 함수로 취급 받으려면, 
//	동일한 이름과 동일한 출력 범위를 가지기만 하면 된다
//
//	OOP에서 사용하는 상속 기능이 포함되어 조금 복잡해졌다.
//	상속을 받은 객체는 부모 객체와 동일한 범위를 가져야 한다고 생각해야 할까 말아야 할까 ?
//
//	자료를 제공하는 쪽에서는 원래 약속했던 범위 내에서 
//	제한적인 범위의 데이터만을 제공할 가능성이 존재한다고 해도, 
//	그걸 받는 쪽에서 이미 더 큰 범위의 데이터를 커버하기로 약속했기 때문에 문제가 발생하지 않는 것이다.
//	이게 바로 Covariant Return Type 이다.
//	구현 클래스는 부모 클래스보다 더 Specific 하기 때문에(즉, 부모 클래스가 더 General 하다) 
//	이렇게 사용해도 전혀 무리가 없다.

//Contravariant Type의 범위 (반공변 반환)
//
//	Covariant의 반대의 경우, 함수의 파라미터에서 이것의 적용이 가능
//	C++에서는 언어 차원의 기능을 제공하지 않는다. 
//	(기초클래스도 없고, 템플릿 사용으로, 형변환의 혼란이 적다)
// 
//	.Net의 경우 
//	Parameterize된 구조에서는 in 이라는 키워드와 out 이라는 키워드를 이용하여 
//	covariant, contravariant를 모두 제공

//불변성, 가변성(공변, 반 공변)
//가변성(Variance) : 특정 타입의 객체를 다른 타입의 객체로 변환할 수 있는 성격을 말한다.
//불변성(InVariance) : 원래 명시된 형식만 사용할 수 있는 성격을 말한다.

//C++에서 covariant return type을 사용할 때 주의를 해야할 점은 
//	반환되는 자료형이 LSP ( Liskov Substitution Principle )를 만족해야 한다는 것이다. 
//	즉,자식 객체에 접근할 때 그 부모 객체의 인터페이스로 접근하더라도 아무런 문제가 없어야 한다.
//	이 조건 범위에서는 자유롭게 사용하면 된다.
//	( 예를 들어 GoF 패턴 중 Prototype 패턴의 clone() 메서드 등 )

