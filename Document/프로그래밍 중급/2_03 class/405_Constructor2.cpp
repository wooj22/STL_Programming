//연습) 생성자와 소멸자의 호출 순서를 확인하자  --------------------------------

#include<conio.h>
#include<iostream>
using namespace std;

class Circle
{
public:
	int radius;
	Circle();
	Circle(int r);
	~Circle();
};
Circle::Circle()
{
	radius = 1;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}
Circle::Circle(int r)
{
	radius = r;
	cout << "반지름 " << radius << "인 원 생성" << endl;
}
Circle::~Circle()
{
	cout << "반지름 " << radius << "인 원 소멸" << endl;
}

int main()
{
	Circle c1;				//Circle() 생성자 호출로 초기화
	Circle c2(2);			//Circle(int r)
	Circle c3(3);
	return 0;
}

//연습) 객체 선언과 함수 선언을 구별하자 ---------------------------

#include <iostream>
using namespace std;

class SimpleClass
{
	int num1;
	int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0)		//생성자
	{
		num1 = n1; num2 = n2;
	}
	void ShowData()							//맴버함수
	{
		cout << num1 << ' ' << num2 << endl;
	}
};

int main(void)
{
	SimpleClass sc;						// 객체 생성. //기본 생성자
	SimpleClass sc = SimpleClass();		// 객체 생성. 

	SimpleClass sc();					// 함수의 선언 !!! ***

	SimpleClass mysc = sc1();
	mysc.ShowData();
	return 0;
}

SimpleClass sc1()						// SimpleClass 리턴하는 함수
{
	SimpleClass sc(20, 30);				// 클래스 객체 생성
	return sc;
}
