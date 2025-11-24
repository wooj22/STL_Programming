// 지역 변수를 return하면 함수의 종료와 함께 변수는 소멸되기 때문에
// 참조로 받을 경우, 댕글링을 유의해야한다.
// 
// ! rvalue return을 const&로 받는 경우를 제외하고 모두 댕글링임
//   C++에서는 rvalue를 const lvalue 참조로 바인딩할 수 있음
//	 값 자체는 함수에서 복사되어 새 객체가 만들어짐

#include <iostream>

// 지역 변수 return
int Function1()
{
	int a = 10;
	return a;
}

// 지역 변수 참조 return
int& Function2()
{
	int a = 10;
	return a;
}

int main()
{
	// 지역 변수를 참조로 받을 경우 
	// -> 이미 소멸된 a의 참조를 시도하여 컴파일 error
	int& ref1 = Function1();

	// 지역 변수를 const&로 받을 경우
	// -> 가능
	const int& ref2 = Function1();
	std::cout << ref2 << std::endl;

	// 지역 변수 참조 리턴을 참조로 받을 경우
	// -> 댕글링 참조지만 에러가 발생하지 않는다. (매우 위험)
	int& ref3 = Function2();
	std::cout << ref3 << std::endl;

	// 지역 변수 참조 리턴을 const&로 받을 경우
	// -> 댕글링 참조지만 에러가 발생하지 않는다. (매우 위험)
	const int& ref4 = Function2();
	std::cout << ref4 << std::endl;
}