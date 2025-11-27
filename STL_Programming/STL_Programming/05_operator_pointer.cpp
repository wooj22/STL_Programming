/*
	[ 포인터 접근 연산자 *, -> 재정의]
	const 멤버 함수로 선언하는 이유는 상수 객체에서도 호출할 수 있게 하기 위함이다.

	* : 포인터 역참조 값 반환
	-> : 포인터 반환
*/

#include <iostream>	
using namespace std;

struct Position
{
	int x, y;
	friend ostream& operator<<(ostream& os, const Position& pos)
	{
		os << pos.x << " " << pos.y << endl;
		return os;
	}
};

class Position_Pointer
{
private:
	Position* ptr;

public:
	Position_Pointer(){ ptr = new Position(); }
	~Position_Pointer(){ delete ptr; }

	// *
	Position& operator*() const
	{
		return *ptr;
	}

	// ->
	Position* operator->() const
	{
		return ptr;
	}
};

int main()
{
	Position_Pointer ptr;
	ptr->x = 10;
	ptr->y = 20;

	cout << *ptr;
}