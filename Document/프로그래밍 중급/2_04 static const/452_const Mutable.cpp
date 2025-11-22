// mutable로 선언된 멤버변수

#include <iostream>
using namespace std;

class CTest
{
private:
	int num1;
	mutable int num2;		//mutable로 선언된 멤버변수는 const 함수 내에서 값의 변경이 가능 ***
public:
	CTest(int n1, int n2) : num1(n1), num2(n2)	{ 
	}

	void ShowSimpleData() const
	{
		cout << num1 << ", " << num2 << endl;
	}

	void CopyToNum2() const
	{
		num2 = num1;				//const 함수에서도 변경이 가능 
	}
};

int main(void)
{
	CTest sm(1, 2);
	sm.ShowSimpleData();
	sm.CopyToNum2();
	sm.ShowSimpleData();
	return 0;
}