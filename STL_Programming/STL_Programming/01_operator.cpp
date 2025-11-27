/*
	[ 연산자 재정의(operator overloading) ]

	클래스 객체를 다루기 위한 연산자 함수를 정의하는 것으로 
	전역함수, 멤버함수로 정의할 수 있다.


	<연산자 오버로딩 불가능 연산자>
	- 멤버 접근 연산자
	   .
	   .*	
	- 스코프 지정 연산자
	   ::
	- 조건 연산자
	   ? :
	- 컴파일 시 처리되는 연산자
	   sizeof, typeid, alignof 등
*/

#include<iostream> 
using namespace std;

class Num
{
private:
	int num;
public:
	Num(int n) : num(n) {}
	void Show() { cout << num << endl; }

	// 멤버 함수
	void operator+=(const Num& my)
	{
		this->num += my.num;
	}

	friend void operator-=(Num& my1, const Num& my2);
};

// 전역 함수
void operator-=(Num& my1, const Num& my2)
{
	my1.num -= my2.num;
}


int main()
{
	Num my1(1);
	Num my2(2);

	my1 += my2;
	my1.Show();
	my2.Show();

	my1 -= my2;
	my1.Show();
	my2.Show();
}