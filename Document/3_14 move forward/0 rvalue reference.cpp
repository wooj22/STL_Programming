#include<iostream>
#include <vector>
using namespace std;

int main()
{
	int a = 0;
	int& b = a;				// Lvalue 참조 // 복사(copy)
	int&& c = 0;			// Rvalue 참조 // 임시값이므로 이동(move)하여 사용, 효율적

	const int& d1 = a;		// Lvalue 참조로 받아 변경 안하겠다.
	d1 = b;					// error
	const int& d2 = 0;		// const 이므로 Rvalue 가능 ***
	

	// Lvalue 를 이동하고 싶다 -------------------------------------------------------

	int&& e1 = a;			// error
	int&& e2 = move(a);		// Lvalue 를 이동하려면 move()사용 //Xvalue  ***

	//이동 연산
	//	사라질 임시변수에 대하여, 복사를 하지 않고 주소를 이전하여 효율적으로 이동
	//	Lvalue도 더이상 사용하지 않을 경우라면, 복사보다는 이동이 효율적이다.
	//  Lvalue 이동을 하기 위해 move() 함수 사용, 
	//	std::move()를 사용하여 인자를 rValue참조자로 변환 (xvalue)


	// Lvalue, Rvalue 알아서 받았으면 좋겠다. ----------------------------------------
	 
	//보편 참조  ***
	auto&& f1 = 0;			// ok //int&&
	auto&& f2 = a;			// ok //int&

	//forward<T>(val) 사용하면, val에 따라 Lvalue, Rvalue 로 리턴
	//std::forward가 가장 많이 쓰이는 곳은 보편 참조 매개변수로 받아서 처리하는 로직
}

