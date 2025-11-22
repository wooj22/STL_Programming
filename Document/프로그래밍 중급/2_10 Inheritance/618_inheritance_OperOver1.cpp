//연산자 오버로딩도 상속이 되는가?

#include <iostream>
using namespace std;

class CMyData
{
private:
	int m_nData = 0;
public:
	CMyData(int nParam) : m_nData(nParam) {}

	//CMyData operator + (const CMyData& rhs)  //연산자 오버로딩
	//{
	//	return CMyData(m_nData + rhs.m_nData);
	//}
};

class CMyDataEx : public CMyData
{
public:
	CMyDataEx(int nParam) : CMyData(nParam) {}
};

int main(int argc, const char* argv[])
{
	CMyData a(3), b(4);
	CMyData	c = a + b;

	CMyDataEx d(3), e(4);
	CMyData	f = d + e;		//???

	return 0;
}


//연산자 오버로딩과 상속
// 
//		대입연산자 함수를 제외한 나머지 연산자는 상속된다. *** 

#include <iostream>
using namespace std;

class CMyData
{
private:
	int m_nData = 0;
public:
	CMyData(int nParam) :m_nData(nParam) {}

	CMyData operator + (const CMyData &rhs)  //연산자 오버로딩
	{
		return CMyData(m_nData + rhs.m_nData);
	}

	CMyData& operator = (const CMyData &rhs)
	{
		m_nData = rhs.m_nData;	return *this;
	}

	operator int() { return m_nData; }
};

class CMyDataEx : public CMyData
{
public:
	CMyDataEx(int nParam) : CMyData(nParam) {}

	//인터페이스를 맞춰주기 위한 연산자 오버로딩.
	using CMyData::operator+;
	using CMyData::operator=;
};

int main(int argc, const char* argv[])
{
	CMyData a(3), b(4);
	cout << a + b << endl;

	CMyDataEx c(3), d(4), e(0);
	e = c + d;
	cout << e << endl;
	return 0;
}

//operator 연산자도 상속이 가능한가요? -------------------------------------------------------------------

//일반 operator 연산자는 상속됩니다.
//부모 클래스의 대입연산자가 public이라면 사용은 할 수 있지만 상속은 안됩니다.

//일반적인 public 멤버라면 상속이 됩니다만, 
//개체의 생성, 소멸, 복사에 관한 멤버는
//특별한 의미를 갖기 때문에 각 클래스에서 책임지고 정의하게 되어 있습니다.

//생성자, 소멸자, 대입연산자, 프렌드는 상속되지 않습니다. ***

#include <iostream>
using namespace std;

class B
{
public:
	void f() {}
	B& operator=(const B&) {
		cout << "bbb" << endl;
		return *this;
	}
};

class D : public B {
public:
	//D& operator=(const D&) {
	//	cout << "ddd" << endl;
	//	return *this;
	//}
};

int main()
{
	D d1, d2;
	d1.f();     // B::f()

	d1 = d2;    // D::operator=()  //B::operator=()와는 다른 함수

	return 0;
}