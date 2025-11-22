// override 키워드
//		override : 기반 클래스의 함수를 재정의한다고 컴파일러에게 알려줌

#include <iostream> 
using namespace std;

class Base
{
public:
	virtual void f1(int) {}
	virtual void f2() const {}
	virtual void f3() {}
	void f4() {}
};

class Derived : public Base
{
	// 실수로 잘못 정의
public:
	virtual void f1(double) {}	// 의도 f1(int)
	virtual void f2() {}		// 의도 f2() const
	virtual void foo3() {}		// 의도 f3()
	void f4() {}				// 네이밍이 같음, virtual 빠짐

	// 잘못 만들었어도 에러가 없다. // 새로운 가상함수를 만들었다고 생각함
};


// override : 기반 클래스의 함수를 재정의한다고 컴파일러에게 알려줌
//		잘못된 오버라이드를 컴파일 에러를 통해 알 수 있게 된다.
// 
//class Derived : public Base
//{
//public:
//	virtual void f1(double) override {}
//	virtual void f2() override {}
//	virtual void foo3() override {}
//	void f4() override {}
//};

int main(void)
{
    return 0;
}

