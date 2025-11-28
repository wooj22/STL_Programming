/*
	클래스 템플릿 상속

	- 템플릿 클래스는 일반 클래스를 상속받을 수 있다.
	- 템플릿 클래스는 템플릿 클래스를 상속받을 수 있다.
		이 경우, 부모의 인자 개수가 동일하다면 인자를 전달하고
		부모의 인자 개수가 더 많다면 개수를 맞춰 특수화 상속하던가
		부모의 인자에 default type을 지정해야한다.
	- 일반 클래스는 템플릿 클래스를 상속받을 수 있다.
	    단, 특수화한 구체 타입이어야 한다. 
*/

// 1. 템플릿 클래스 - 템플릿 클래스 상속
template<typename T1, typename T2>
class Base {};

// 1) 인자 개수가 부족하지 않을 경우 인자 전달
template<typename T1, typename T2>
class Derived1 : public Base<T1, T2> {};

// 2) 인자 개수가 부족하다면 특수화 상속
template<typename T>
class Derived2 : public Base<T, int> {};


// 2. 일반 클래스 - 클래스 템플릿 상속
class Derived3 : public Base<int, int> {};


// 3. 클래스 템플릿 - 일반 클래스 상속
template<typename T>
class Derived4 : public Derived3 {};


int main()
{
	Base<int, int> b;
	Derived1<int, int> d1;
	Derived2<int> d2;
	Derived3 d3;
	Derived4<int> d4;
}