//move 함수(move semantics)
// 
//  우측값 레퍼런스를 통해서, 기존에는 불가능하였던 우측값에 대한 (복사가 아닌) 이동의 구현이 가능해졌다.
//  좌측값도 이동을 시키고 싶다면 어떨까?
//  C++ 11 부터 <utility> 라이브러리에서, 좌측값을 우측값으로 바꾸어주는 move 함수를 제공

#include <iostream>
#include <utility>

class Foo {
public:
	Foo()				{ std::cout << "일반 생성자 호출!" << std::endl; }
	Foo(const Foo& a)	{ std::cout << "복사 생성자 호출!" << std::endl; }
	Foo(Foo&& a)		{ std::cout << "이동 생성자 호출!" << std::endl; }
};

int main() {
	Foo a;

	std::cout << "---------" << std::endl;
	Foo b(a);

	std::cout << "---------" << std::endl;
	Foo c(std::move(a));
}

//std::move 함수는 이동을 수행하지 않는다. 그냥 인자로 받은 객체를 우측값으로 변환할 뿐이다.
//		이동 자체는 std::move 를 실행함으로써 발생하는 것이 아니라, 
//		우측값을 받는 함수들이 오버로딩 되면서 수행되는 것. ***

/*

//문제) 

// 만약 B 객체를 생성할 때, 
// 이미 생성되어 있는 A 객체를 B 의 객체안으로 집어 넣고 싶다면 어떻게 할까요 ?
// 복사없이 이동되도록 구현해 보세요.

	#include <iostream>

	class A {
	public:
		A() { std::cout << "A()\n"; }
		A(const A& a) { std::cout << "A() copy\n"; }
		A(A&& a) { std::cout << "A() move\n"; }
	};

	class B {
	public:
		B(A a) {  }
		A m_a;
	};

	int main() {
		A a;
		std::cout << "create B \n";
		B b(a);							//???
	}


정답 ---------------------------------

	class A {
	public:
		A() { std::cout << "A()\n"; }
		A(const A& a) { std::cout << "A() copy\n"; }
		A(A&& a) { std::cout << "A() move\n"; }
	};

	class B {
	public:
		B(const A& a): m_a(a) { }					//lvalue
		B(A&& a) : m_a(std::move(a)) {}				//rvalue
		A m_a;
	};

	int main() {
		A a;
		std::cout << "create B \n";
		B b(std::move(a));
	}
*/
