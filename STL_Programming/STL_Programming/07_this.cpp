/*
	[this]
	this가 사용된 객체 자신의 주소값을 가지고 있는 포인터
	
	- 멤버 함수 안에서만 사용 가능
	- static 멤버 함수에서 사용 불가
	  객체가 생기기 전에 static 함수 호출이 있을 경우 객체가 없기 때문에
*/

#include <iostream>
using std::cout;
using std::endl;

class Num
{
private:
	int num;

public:
	Num(int num)
	{
		this->num = num;
	}

	void Show()
	{
		cout << this << endl;
	}

	// this return
	Num* GetInstance_Pointer() 
	{
		return this;
	}

	// this return
	Num& GetInstance_Ref()
	{
		return *this;
	}

	static void Print()
	{
		// 불가
		//cout << this << endl;
	}
};

int main()
{
	Num my(1);
	my.Show();

	Num* ptr = my.GetInstance_Pointer();
	ptr->Show();

	Num& ref = my.GetInstance_Ref();
	ref.Show();
}