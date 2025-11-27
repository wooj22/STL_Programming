//연습)  연산자 오버로드  // + - - << 연산자를 정의하세요.

#include <iostream>
using namespace std;

class Num
{
	int num = 0;
public:
	int Get() { return num; }
	void Set(int a) { num = a; }

	//MyClass operator+(MyClass rightHand);
	//MyClass operator-(const MyClass& rightHand) const;
	//MyClass operator-() const;
	
	//friend ostream& operator<<(ostream& os, const MyClass& obj);
};

int main(void)
{
	Num x; x.Set(1);
	Num y;

	//아래 코드처럼 사용가능하도록 연산자를 추가해 봅시다.

	cout << x + y << endl;
	cout << x - y << endl;
	
	cout << -x << endl;
	cout << x << " " << y << endl;

	return 0;
}

// 연산자 오버로딩 + -
Num Num::operator+(Num rightHand)
{
	Num res;
	res.num = this->num + rightHand.num;
	return res;
}
Num Num::operator-(const Num& rightHand) const
{
	Num res;
	res.num = this->num - rightHand.num;
	return res;
}

// 연산자 오버로딩 - 음수
Num Num::operator-() const
{
	Num res;
	res.num = -num;
	return res;
}

// 연산자 오버로딩 <<  //맴버가 아닌 일반함수로 구현
ostream& operator<<(ostream& os, const Num& obj)
{
	os << obj.num;
	return os;
}