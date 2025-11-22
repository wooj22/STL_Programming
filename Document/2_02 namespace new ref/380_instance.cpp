//초기화 ----------------------------------------

#include <iostream>
using namespace std;

void TestFunc(int)
{}

void main(void)
{
	int a = 1;			//C
	int a(1);			//C++	//객체 초기화
	int a{ 1 };			//C++11 //중괄호 초기화 // uniform initialization

	int b(a);			//copy // int b = a;

	int(10);			//?? //이름없는 인스턴스

	//auto -----------------------------------  

	auto c(a);			//자동 형식 지정

	//auto 활용 1
	//void(*pfTest)(int) = TestFunc;
	auto pfTest(TestFunc);			//형 자동 설정
		 
	//auto 활용 2
	int buffer[5] = { 0,1,2,3,4 };
	for (auto i : buffer)			//형 자동 설정
	{
		cout << i << endl;
	}

	//r-value 참조 -------------------------------

	int d = 10;			//값 할당		// l-value = r-value;
	int &r = d;			//l-value 참조	// 주소를 가지고 있는 것들.
	int &&rr = 5;		//r-value 참조  // 임시객체에 대한 참조 //상수, 곧 사라질 대상.

	const int& cr = d;	//const l-value 참조 // 값 변경 안함.
	const int& cr = 5;	//const l-value 참조 // 상수값 수명 연장.

	
	//임시객체 -----------------------------------

	int n = 1 + 2 + 4;	// 1+2 = 3, 3+4 = 7		

	//클래스 객체의 초기화 - 생성자
	class A 
	{
	public: 
		A(int a) { } 
	};
	A a(1); 
	A(1);
}

//초기화 관련 문제.
{
	//출력은?
	int a = 1;
	int& r(a);
	r = 2;
	cout << a + sizeof(&r) << endl;		// 2 + 8

	//출력은?
	cout << int() << endl;				// () 초기화 //int{}
}