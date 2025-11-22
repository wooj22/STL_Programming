//가상 소멸자 문제

#include <iostream>
using namespace std;

class Base
{
public:
	~Base() { cout << "~Base()" << endl; }
};

class Derived : public Base
{
private:
	int* m_array;
public:
	Derived(int length) { m_array = new int[length]; }
	~Derived() { cout << "~Derived()" << endl;	delete[] m_array; }
};

int main()
{
	Base* base = new Derived(5);  // 다형성, 동적할당
	delete base;

	return 0;
}

//~Derived() 가 호출되지 않음 //해결책은?

//실형식이 안전하게 소멸되려면, 가상 소멸자를 선언해야 한다.
//자식 클래스를 만들게 되면, "소멸자는 가상 함수로 만들어야 한다"