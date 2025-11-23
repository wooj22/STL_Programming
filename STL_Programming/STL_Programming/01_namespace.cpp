/*
	[ namespace ]

	namespace는 '이름 공간'으로 모든 식별자가 고유하도록 보장하는 코드 영역을 정의하여 이름 충돌 문제를 해결한다.
	C++ 표준 라이브러리의 모든 식별자는 'std' namespace 안에 있다.

	- namespace 정의
	- 중첩 namespace 정의
	- using namespace
	- namespace 별칭
*/

#include <iostream>

// using namespace
using namespace std;

// namespace 별칭
namespace AAAAAA = AAA::AA::A;

// namespace 정의
namespace A
{
	int dataA;
}

namespace B
{
	int data;
}

// namespace 중첩 선언 (동일한 namespace)
namespace B
{
	int dataB;
}

// 중첩 namespace 정의
namespace AAA
{
	namespace AA
	{
		namespace A { int data; }
	}

	namespace BB
	{
		namespace B { int data; }
	}
}

// namespace 함수 선언부, 구현부 분리
namespace Monster
{
	void Func1();

	namespace Inventory {
		class Item {
		public:
			void Func2();
		};
	}
}

void Monster::Func1() {}
void Monster::Inventory::Item::Func2() { cout << "Func2()" << endl; }

int main()
{
	// namespace가 달라 식별자 이름이 같아도 구분이 가능하다
	A::dataA = 1;
	B::data = 2;

	// namespace의 이름이 같더라도, 상위 namespace가 다르면 다른 namespace이다.
	AAA::AA::A::data = 3;
	AAA::BB::B::data = 4;

	cout << A::dataA << endl;
	cout << B::data << endl;
	cout << AAA::AA::A::data << endl;
	cout << AAA::BB::B::data << endl;

	// namespace 별칭
	namespace MonsterInven = Monster::Inventory;
	MonsterInven::Item item;
	item.Func2();
}
