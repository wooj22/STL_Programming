// namespace 활용해보기

#include <iostream>
using namespace std;

namespace MyNamespace
{
	int number = 1;

	void func() { }

	class A {
	public:
		int a = 0;
		void f() { cout << a << endl; }
	};

	struct B {
		int a = 0;
	};
}

void main()
{
	cout << MyNamespace::number << endl;

	MyNamespace::A a;
	a.f();

	MyNamespace::B b;
	cout << b.a << endl;
}