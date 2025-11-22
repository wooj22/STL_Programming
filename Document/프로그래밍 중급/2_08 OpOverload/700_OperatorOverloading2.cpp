//연습)  연산자 오버로드  // + - - << 연산자를 정의하세요.

#include <iostream>
using namespace std;

class MyClass
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
	MyClass x; x.Set(1);
	MyClass y;

	//아래 코드처럼 사용가능하도록 연산자를 추가해 봅시다.

	cout << x + y << endl;
	cout << x - y << endl;
	
	cout << -x << endl;
	cout << x << " " << y << endl;

	return 0;
}

// 연산자 오버로딩 + -
MyClass MyClass::operator+(MyClass rightHand)
{
	MyClass res;
	res.num = this->num + rightHand.num;
	return res;
}
MyClass MyClass::operator-(const MyClass& rightHand) const
{
	MyClass res;
	res.num = this->num - rightHand.num;
	return res;
}

// 연산자 오버로딩 - 음수
MyClass MyClass::operator-() const
{
	MyClass res;
	res.num = -num;
	return res;
}

// 연산자 오버로딩 <<  //맴버가 아닌 일반함수로 구현
ostream& operator<<(ostream& os, const MyClass& obj)
{
	os << obj.num;
	return os;
}