/*
	클래스의 멤버로 const를 사용할 수 있다.

	- const 멤버 변수	
	   초기화 리스트를 통해 초기화해아한다.

	- const 멤버 함수
	   함수 내에서 멤버변수의 변경을 금지하며, 비 상수 멤버 함수를 호출할 수 없다.
	   만약 비 상수 멤버함수를 참조 return하는 cosnt 함수의 경우, 
	   반환 타입을 const로 하던가 애초에 const 함수로 선언하면 안된다.
	   const 유무에 따라 오버로딩이 가능하다.
*/

#include <iostream>
using namespace std;

class MyClass
{
public:
	int num1;
	// const 멤버 변수
	// 반드시 초기화리스트를 통해 초기화해야한다.
	const int num2 = 0;	

	MyClass(int n1, int n2) : num1(n1), num2(n2) {}

	// const 멤버 함수
	// : 멤버변수의 변경 금지
	void Show() const
	{
		cout << num1 << ' ' << num2 << endl;
		//num1 = 10;		// error
	}

	const int& GetNum1() const
	{
		return num1;	// 멤버의 const 보장을 위해 const return
	}

	// overloading
	int& GetNum1()
	{
		return num1;
	}
};

int main()
{
	MyClass my(1,2);
	my.Show();
}