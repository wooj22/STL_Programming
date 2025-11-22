//함수 오버라이딩(overriding)이란 
//		이미 정의된 함수를 무시하고, 같은 이름의 함수를 새롭게 정의하는 것
//		함수의 원형은 기존 멤버 함수의 원형과 같아야 한다.
//
//		1. 파생 클래스에서 직접 오버라이딩하는 방법
//		2. 가상 함수를 이용해 오버라이딩하는 방법

//오버라이딩을 한 이유는 새로운 함수를 사용하기 위한 것
// 
//		부모로 자식을 지칭하여 관리하고자 하는 경우, (업캐스트)
//		부모 객체는 자식 클래스의 재정의된 함수에 접근할 때, 형변환을 통해 접근해야 함. (다운캐스트)
//		부모객체로 
//		자동으로 오버라이드된 함수를 호출해주는 방법이 있으면 편리 -> 동적 바인딩 ***

//가상 함수 - virtual
//		가상테이블을 만들어 '동적 바인딩'을 한다.
//		동적 바인딩이란 '포인터' 변수가 실제로 가리키는 객체에 따라 호출의 대상이 결정하는 것.
// 
//		포인터의 형에 상관 없이, 포인터가 가리키는 객체의 '마지막 오버라이딩' 함수를 호출한다. ***
//		오버라이딩 된 함수가 virtual이면, 오버라이딩 한 함수도 자동 virtual ***

//가상 함수 재정의 (override)
//		가상 함수 재정의(override)시에는 virtual 키워드는 붙여도 되고 붙이지 않아도 됨
//		가상 함수 재정의시 실수를 막기 위해서 override 키워드를 사용하자 (C++11)
//		가상 함수를 선언과 구현으로 분리 할때는 선언부에만 virtual, override을 표기

#include <iostream>
using namespace std;

class First
{
public:
	virtual void MyFunc()		//가상함수는 최종 상속클래스의 함수를 실행한다.
	{
		cout << "FirstFunc" << endl;
	}
};

class Second : public First
{
public:
	void MyFunc()				//재정의(override) // 자동으로 가상 ***
	{
		cout << "SecondFunc" << endl;
	}
};

class Third : public Second
{
public:
	void MyFunc()				//재정의 // 자동으로 가상
	{
		cout << "ThirdFunc" << endl;
	}
};

int main(void)
{
	Third* tptr = new Third();
	Second* sptr = tptr;		//상위클래스로 포인팅
	First* fptr = sptr;			//상위클래스로 포인팅

	fptr->MyFunc();				
	sptr->MyFunc();				//가상화하면 실형식을 따른다 ***
	tptr->MyFunc();		

	delete tptr;
	return 0;
}


//가상 함수의 구현 원리 - 가상테이블
//https://modoocode.com/211
 

/*

//가상화 - 미래에 만들 함수를 호출하는 것이 가능, 프래임워크 구현, 설계를 위해 사용

//순수 가상함수와 추상 클래스
//	몸체가 정의되지 않은 함수를 가리켜 순수 가상함수라 하며, 
//	하나 이상의 순수 가상함수를 멤버로 두어서 객체생성이 불가능한 클래스를 추상 클래스라 한다.

	class CTest
	{
	public:
		virtual void MyFunc() = 0;		//순수 가상함수
	};

*/


