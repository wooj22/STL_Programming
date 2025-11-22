//가상화 - 미래에 만들 함수를 호출, 프래임워크 구현, 설계

//가상함수
//  포인터의 형에 상관 없이 포인터가 가리키는 객체의 마지막 오버라이딩 함수를 호출한다.
//  오버라이딩 된 함수가 virtual이면 오버라이딩 한 함수도 자동 virtual

//순수 가상함수
//  몸체가 정의되지 않은 함수를 가리켜 '순수 가상함수'라하며, 
//  하나 이상의 순수 가상함수를 멤버로 두어서 객체생성이 불가능한 클래스를 가리켜 '추상 클래스'라 한다.

//가상함수를 호출한다는 의미
//
//	미래의 함수 설계 //코드 공존 //프레임워크 설계, 추후에 결정될 내용에 대해 흐름 정의, 관계 + 흐름 파악
//  
//	가상함수가 있으면 관계, 흐름 파악하라.

#include <iostream>
using namespace std;

class C2000
{
public:
	virtual void OnFunc()			//가상함수는 최종 상속클래스의 함수 실행
	{
		cout << "C2000 OnFunc" << endl;
	}

	void C2000Func()
	{
		OnFunc();					// 가상함수 호출	//called by framework //미래에 만들어질 함수 호출
		cout << "C2000Func" << endl;
	}
};

class C2020 : public C2000			//
{
public:
	void OnFunc()					//재정의 // 자동으로 가상  //final 재정의 금지
	{
		cout << "C2020 OnFunc" << endl;
	}
	void C2020Func()
	{
		C2000::C2000Func();			//가상함수 호출시점을 알고 써야 한다.
		cout << "C2020Func" << endl;
	}
};

int main(void)
{
	C2020* p2020 = new C2020();
	C2000* p2000 = p2020;			//상위클래스로 포인팅

	//p2000->OnFunc();
	//p2020->OnFunc();				//가상화하면 실형식을 따른다 

	p2000->C2000Func();				// 코드의 흐름을 미리 정의한다

	p2020->C2020Func();

	delete p2020;

	return 0;
}