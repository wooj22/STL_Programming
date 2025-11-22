//템플릿 인자 추론

#include <iostream>
#include <typeinfo>

template<typename T1 = int, typename T2>
void foo(T1 a, T2 b) {
	std::cout << a << " " << b << std::endl;
}

int main()
{
	foo<int, int>(1.5, 2.3);		//파라미터 명시적 지정

	foo<int>(1.5, 2.3);			//첫번째 파라미터 명시적 지정

	foo(1.5, 2.3);			//출력은?

	foo<>(1.5, 2.3);		//출력은? //인자추론에 의해 기본 값은 사용 안함 //함수 템플릿
}

//---------------------------------------------------------------

//template<typename T1 = int, typename T2>		//error
//class CTest1 { };

template<typename T1 = int, typename T2 = int>
struct CTest
{
	T1 a;
	T2 b;
	T1 n = T1();
	CTest(T1 a, T2 b) :a(a), b(b) {}
	void print() { std::cout << a << " " << b << " " << n << std::endl; }
};

int main()
{

	CTest<> c(1.5, 2.3); c.print();		//파라미터 기본값 사용 //생성자로 인수추론 안함

}