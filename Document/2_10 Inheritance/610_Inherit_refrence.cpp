//기반 클래스의 레퍼런스인 경우

#include <iostream>
using namespace std;

class First
{
public:
	//void FirstFunc() { cout << "FirstFunc()" << endl; }
	virtual void SimpleFunc() { cout << "First's SimpleFunc()" << endl; }
};

class Second : public First
{
public:
	//void SecondFunc() { cout << "SecondFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Second's SimpleFunc()" << endl; }
};

class Third : public Second
{
public:
	//void ThirdFunc() { cout << "ThirdFunc()" << endl; }
	virtual void SimpleFunc() { cout << "Third's SimpleFunc()" << endl; }
};

int main(void)
{
	Third obj;
	obj.SimpleFunc();		//출력은?

	Second& sref = obj;		//참조할 경우에도 가상함수 동작은 포인터와 동일
	sref.SimpleFunc();		//출력은?

	First& fref = sref;
	fref.SimpleFunc();		//출력은?

	return 0;
}


//문제) 호출 결과는? -------------------------------------------

#include <iostream>
using namespace std;

class CBase
{
	int baseNum = 1;
public:
	virtual void Show() { cout << baseNum << endl; }
};

class CDerived : public CBase
{
	int derivNum = 2;
public:
	void Show() { cout << derivNum << endl; }
};

void main()
{
	CDerived obj;
	CBase b = obj;
	b.Show();               //호출 결과는?
}

//% 동적바인딩은 *, & 의 경우에 일어난다.