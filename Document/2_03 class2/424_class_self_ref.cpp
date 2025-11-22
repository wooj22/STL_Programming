//자신 참조 반환
//		자신을 그대로 반환, 연속 호출이 가능.

#include <iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int n) : num(n)
	{
		cout << "객체생성" << endl;
	}
	CTest& Adder(int n)			//CTest& , 참조로 반환(변수)
	{
		num += n;
		return *this;			//*this 로 반환, 객체 자신을 반환  ***
	}
	CTest& ShowNumber()			//CTest&
	{
		cout << num << endl;
		return *this;			//*this 로 반환
	}
};

int main(void)
{
	CTest obj(3);
	CTest& ref = obj.Adder(2);		//obj 참조 리턴

	obj.ShowNumber();
	ref.ShowNumber();


	ref.Adder(1).ShowNumber().Adder(2).ShowNumber(); //자신 참조 반환

	return 0;
}


//연습)
//  객체를 선언하고, 객체 자신의 주소를 리턴하는 맴버함수와
//  객체 자신을 리턴하는 맴버함수를 각각 작성하세요. ***


#include <iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int n) : num(n) {}
	void Show() { cout << num << endl; }

	CTest& GetSelf() { return *this; }	//*this 로 반환, 객체 자신을 반환  ***
	CTest* GetThis() { return this; }	//this 로 반환, 객체 주소를 반환  ***
};

int main(void)
{
	return 0;
}

