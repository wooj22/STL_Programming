/*
* [ << 연산자 재정의 ]
	cout 의 '<<'또한 출력 연산자이다.
	사용자 정의 클래스에 << 연산자를 재정의하여 편하게 출력할 수 있다.
	이때 연산자 함수를 멤버함수로 구현할 경우, 객체가 왼쪽에 와야하는데
	cout으로 시작하는 << 연산자는 객체가 오른쪽에 오기 때문에
	전역 함수로 만들어야한다.

	cout 정의 : ostream cout;
	cout은 ostream을 넘겨가며 다음 객체에 정의되어있는 << 연산자 정의를 실행한다.
	매개변수로 ostream을 넘겨받아 원하는 결과를 출력하고 이어서 <<를 실행할 수 있도록
	다시 ostream을 넘겨주면 된다.
*/

#include <iostream>
using namespace std;

class Num
{
	int num = 0;

public:
	Num(int n) : num(n) {}

	// << 전역함수 friend 등록
	friend ostream& operator<<(ostream& os, const Num& my)
	{
		os << "Myclass : " << my.num << endl;
		return os;
	}
};

int main()
{
	Num my1(1);
	Num my2(2);

	cout << my1 << my2 << endl;
}