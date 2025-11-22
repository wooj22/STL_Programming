//상속과 오버로드

#include <iostream>
using namespace std;

class AAA {
public:
	void Show(int n) { cout << "Show(int n)" << endl; }
};
class BBB : public AAA
{
public:
	void Show(int n, int m) { cout << "Show(int n, int m)" << endl; }
};

int main(void) {
	BBB b1; 
	b1.Show(3, 5);

	b1.Show(3);			//error 이유는?

	return 0;
}


//c++ 에서는 상속을 했다고 해서 오버로딩을 자동적으로 해주지 않는다 ***
// 
//		기초클래스와 유도클래스는 일단 다른 네임스페이스고 네임스페이스는 말그대로 이름만 가지고 구분
//		오버로딩된 함수 시그니처에 상관없이 하이딩이 된다.
//
//이런 경우, 파생클래스에서 모두 재정의 해주어야 할까?		
//		using AAA::Show;
//		using CBase::operator=; 또는 그냥 CBase::operator=; 이렇게 유도클래스에 선언해주면 된다.

// using
// 
//		파생 클래스 내에 using 선언을 해줌으로써 가려진 이름을 사용한다. ***
// 
//		기본 클래스로부터 상속을 받으려고 하는데, 오버로드된 함수가 그 클래스에 들어 있고
//		이 함수 중 몇개만 재정의하고 싶다면,각 이름에 대해 using 선언을 붙여 주면 된다.
//
//		using 선언은 소괄호, 함수 시그내처, 리턴형 없이 멤버 이름만 사용한다.

#include <iostream>

class Base {
public:
	virtual void mf1() { std::cout << 0 << "\n"; }
	virtual void mf1(int a) { std::cout << a << "\n"; };
};

class Derived : public Base {
public:
	using Base::mf1;			//using 선언
	virtual void mf1() {}		//재정의
};

int main(void) {
	Derived d;
	d.mf1();
	d.mf1(1);			//Base::mf1(int) Call

	return 0;
}

//오버로드 vs 오버라이딩
//	오버로딩   - 다른 함수에 대해 같은 이름 사용, 시그니처 변화
//	오버라이딩 - 상속관계에서 같은 함수 재정의,   시그니처 안 변함

/*
class Base
{
public:
	Base(int n) : val(n) {}

private:
	int val;
};

class Derived : public Base
{
public:
	using Base::Base;		//using으로 기반 클래스의 생성자를 사용하겠다고 지정해주면, 기반 클래스로부터의 생성자가 상속이 된다.
	Derived() : Base(0) {}
};

int main()
{
	Derived d1;
	Derived d2(7);
}

*/

//연습) 아래 오류를 해결하세요.

#include <iostream>
using namespace std;

class AAA {
public:
	void func() { }
	virtual void func(int n) { }
};
class BBB : public AAA
{
public:
	void func(int n) { } //override
};

int main(void)
{
	BBB b1;
	b1.func();		//error
	return 0;
}