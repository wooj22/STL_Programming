
// 클래스의 '멤버 함수'를 std::function 으로 선언하는 경우는
//
//		멤버 함수 내에서 this 의 경우 자신을 호출한 객체를 의미하기 때문에, 
//		만일 멤버 함수를 그냥 function 에 넣게 된다면 this 가 무엇인지 알 수 없는 문제가 발생
//		따라서, & 연산자를 통해 명시적으로 주소값을 전달해줘야 합니다.

#include <functional>
#include <iostream>
#include <string>

class A {
	int c;

public:
	A(int c) : c(c) { }

	int some_func() {
		std::cout << "비상수 함수: " << ++c << std::endl;
		return c;
	}

	int some_const_function() const {
		std::cout << "상수 함수: " << c << std::endl;
		return c;
	}

	static void st() {
		std::cout << "static 함수 " << std::endl;
	}
};

int main() {
	A a(5);

	//멤버 함수들의 경우 
	//		암시적 변환이 발생하지 않으므로,
	//		& 연산자를 통해 명시적으로 주소값을 전달해줘야 합니다. ***

	std::function<int(A&)> f1 = &A::some_func;		//원래 인자에 추가적으로 객체를 받는 인자를 전달
	f1(a);

	std::function<int(const A&)> f2 = &A::some_const_function;
	f2(a);

	//std::function<void()> f3 = &A::st;
	//f3();

	//std::function<int(A)> f4 = &A::some_func;	f4(a);
	//std::function<int(A*)> f5 = &A::some_func;	f5(&a);
	//std::function<int(A&)> f6 = &A::some_func;	f6(a);

}
