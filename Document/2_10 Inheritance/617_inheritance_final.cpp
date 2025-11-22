// final 추가 파생 금지 ----------------------------------------------
//		C++ 11에서 final 키워드의 추가로 간단하게 상속을 차단 가능
//		클래스에도 사용이 가능하고, 클래스의 메소드에도 가능.

#include <iostream> 
using namespace std;

class A
{
public:
	virtual void f1() {}
};

class B : public A
{
public:
	virtual void f1() override final {}		//
};

class C : public B
{
public:
	virtual void f1() override {}		// error.
};

void main()
{
	A a;
}


// 클래스 뒤에 붙이는 경우. 상속 금지 ----------------------------------

class A
{
public:
	virtual void f1() {}
};

class B final : public A		//
{
public:
	virtual void f1() override final {}
};

// error // Class B 는 final이 붙어 있어서 더 이상 상속할 수 없다.
class C : public B
{
public:
	// error. // f1은 final이 있으므로 더 이상 정의할 수 없다.
	virtual void f1() override {}
};

void main()
{
	bool b = is_final<B>::value;	//final로 표시된 클래스 종류인지 테스트 // <type_traits> //네임스페이스: std

	cout << b << endl;
}
