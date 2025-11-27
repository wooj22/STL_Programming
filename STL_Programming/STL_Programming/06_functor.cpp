/*
	[ 함수객체 (functor) ]

	' functor = function + object '
	() 연산자 오버로딩을 통해 함수의 기능을 하는 객체를 함수객체라고 한다.
	마치 함수를 호출하듯 객체를 호출할 수 있다.

	객체를 함수처럼 사용하는 이유
	 - 함수를 객체처럼 다루면 값의 전달이나 관리하기에 편리하다. ( 데이타 - 상태와 행동 )
	 - 변수와 함수를 구분하지 않고 객체로 일관성 있게 처리가능하다. ( 변수객체, 함수객체 )
	 - 변수객체는 값으로 사용, 함수객체는 호출해서 사용
*/

#include <iostream>
using namespace std;

struct Position
{
	int x, y;
	Position(int x = 0, int y = 0) : x(x), y(y) { }

	/*Position operator+(const Position& p)
	{
		Position temp;
		temp.x = x + p.x;
		temp.y = y + p.y;

		return temp;
	}*/

	friend ostream& operator<<(ostream& os, const Position& pos)
	{
		os << "x : " << pos.x << ", y : " << pos.y << endl;
		return os;
	}
};

// 함수객체
struct Adder
{
	Position operator()(const Position& pos1, const Position& pos2)
	{
		Position temp;
		temp.x = pos1.x + pos2.x;
		temp.y = pos1.y + pos2.y;

		return temp;
	}
};

int main()
{
	Position p1(10, 10);
	Position p2(5, 5);

	/*Position p3 = p1 + p2;
	cout << p3;*/

	Adder adder;
	Position p3 = adder(p1, p2);
	cout << p3;
}