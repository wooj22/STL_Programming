//C++ 상속 받은 맴버 접근 변경하기, 감추기
//using, delete

#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;
public:
	Base(int value) : m_i(value) {}
	void print() {
		cout << "I'm base" << endl;
	}
};

class Derived : public Base
{
	double m_d;
public:
	Derived(int value) : Base(value) {}
	using Base::m_i;		//부모클래스 멤버변수(m_i)가 public으로 변환이 된다.
};

int main()
{
	Derived derived(7);
	derived.m_i = 1024;		//정상적으로 실행이 되는 것을 볼 수 있다.
}


//C++ 상속 받은 맴버 감추기
//Base 클래스에서 print 함수를 Derived에서 외부 접근을 못하게 하려면 어떻게 해야 될까 ?
// 
//Base 클래스에서 private으로 선언을 하는 방법이 있겠지만 다른 예를 보이겠다.

#include <iostream>
using namespace std;

class Base
{
protected:
	int m_i;
public:
	Base(int value) : m_i(value) {}
	void print() { cout << "I'm base" << endl; }
};

class Derived : public Base
{
	double m_d;
	using Base::print;				//private 으로 선언, main에서 접근을 못하게 한다. 
public:
	//void print() = delete;		//이렇게도 가능하다. delete 로 삭제 - 보통 public으로 사용 ***
	Derived(int value) : Base(value) {}
	using Base::m_i;
};

int main()
{
	Derived derived(7);

	derived.m_i = 1024;
	derived.print(); //error
}

