//상속
//	코드재사용, 규모확장을 위해 기존의 클래스를 기반으로 새로운 클래스를 구현하는 것.
//
//	기존 클래스 재활용 ***
//	공통 부분을 상위 클래스에 통합하여 반복 제거
//	공동의 조상을 가지는 클래스 계층을 형성하여 다형성 구현 ***

// class 자식클래스: public 부모클래스 {  }
// protected

#include <iostream>
#include <cstring>
using namespace std;

class CTest
{
private:								//private
	int nData1 = 0;
protected:								//protected	 //상속과 정보 은폐를 위해 추가된 접근지정자 ***
	int nData2 = 0;
public:									//public
	int nData3 = 0;
public:
	CTest() { cout << "CTest()" << endl; }
	~CTest() { cout << "~CTest()" << endl; }

	void CTestFunc()
	{
		cout << "CTest CTestFunc()" << endl;
	}
};

class CTestEx : public CTest			//CTest 클래스를 public 상속함 ***
{
	int nData = 0;
public:
	CTestEx() { cout << "CTestEx()" << endl; }
	~CTestEx() { cout << "~CTestEx()" << endl; }

	void CTestFunc()
	{
		cout << "CTestEx CTestFunc()" << endl;

		cout << nData << endl;		//본인의 맴버			//ok

		cout << nData1 << endl;		//부모의 private 맴버	//error 
		cout << nData2 << endl;		//부모의 protected 맴버  //ok
		cout << nData3 << endl;		//부모의 public 맴버		//ok

		//CTestFunc();					//CTestEx 클래스의 맴버함수
		//CTest::CTestFunc();			//CTest 클래스의 맴버함수
	}
};

void main()
{
	CTest a;	a.CTestFunc();			//CTest

	CTestEx b;	b.CTestFunc();			//CTest + CTestEx
		

	// 기본클래스와 파생클래스 관계는? -------------------------------------------------

	// 기본클래스와 파생클래스 생성자 관계는 ???
	//
	// 기본클래스, 파생클래스 는 각각 생성자와 소멸자를 가진다.
	
	// 기본클래스와 파생클래스 형변환은 ???
	//
	// 기본클래스는 파생클래스 포인트(참조) 가능	 //선언형식을 따른다. 단, virtual은 실형식
	//	CTest& c = b;
	//	c.CTestFunc();
	//
	// 파생클래스는 기본클래스 포인트(참조) 허용 안함
	//	CTestEx& d = a;
	//	d.CTestFunc();
}


