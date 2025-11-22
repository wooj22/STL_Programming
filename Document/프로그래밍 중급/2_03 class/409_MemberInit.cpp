//클래스 멤버 변수 초기화
//		변수 초기화를 하지 않으면 쓰레기값으로 설정됨, 초기화 하자. 

//Member Initializer list ( 콜론 초기화 ) ( 맴버 이니셜라이저 ) 
//		생성자 뒤에 : 을 쓰고 맴버를 초기화 하는것.

//C++ 11 부터는 Braced-Init-list를 지원 
//		- { } 중괄호 초기화  
//		- std::initializer_list<> 로 구현되어 있다.


//변수 초기화를 하지 않으면 ---------------------------------------------------

#include <iostream>
using namespace std;

struct MyStruct {
	int val;
};

class MyClass {
public:
	int val;
};

int main(void)
{
	MyStruct mystruct;						//mystruct 초기화되지 않음
	cout << mystruct.val << endl;			//error 

	MyClass myclass;
	cout << myclass.val << endl;			//error

	return 0;
}

/*
	class MyClass {
	public:
		int val;
	};

	MyClass myclass;							//전역 객체의 경우

	int main(void)
	{
		cout << myclass.val << endl;			//????
		return 0;
	}
*/


//클래스 멤버 변수 초기화 방법 3가지 ------------------------------------------------------
// 
//	1) 멤버변수 정의시 초기화 하기
//	2) 생성자에서 초기화 하기
//	3) 생성자에서 초기화 리스트로 초기화 하기 ( 맴버 이니셜라이저 )

class ClassA {
public:
	int var1 = 10;						//1.멤버변수 정의시 초기화	

	ClassA() {
		var1 = 10;						//2.생성자에서 초기화 // Default 생성자 
	}
	ClassA(int var) {					//2.생성자에서 초기화 // 생성자 오버로딩
		var1 = var;
	}

	ClassA(int v1) : var1(v1)			//3.초기화 리스트 사용 
	{}
};

//초기화 우선 순위(메모리 할당, 처리 순서) ----------------------------------------------

class Something
{
private:
	int m_i = 100;							// 1번 
	double m_d = 12.34;
public:
	Something() : m_i{ 10 }, m_d{ 3.14 }	// 2번 
	{
		m_i = 3;							// 3번
		m_d = 3.0f;
	}
};
//우선순위는 1번 < 2번 < 3번 순서이다. ***


//멤버 초기화는 ---------------------------------------------------------------------
//
//      = 연산자를 이용한 복사 초기화 방식              int x = 5;  을 지원
//      {}를 이용한 유니폼 초기화 방식                  int x{ 5 };  을 지원하지만
//      ()를 이용한 직접 초기화방식은 지원하지 않는다.   int x(5); 는 error

class Something
{
private:
	int a1 = 0;
	int a2(0);						//error
	int a3{ 0 };					// { } 초기화
public:
};


//생성자 멤버 초기화 목록 예시  ---------------------------------------------------------

class Something
{
private:
	int m_i;
	double m_d;
	char m_c;
	int m_arr[5];

public:
	Something() : m_i{ 10 }, m_d{ 3.14 }, m_c{ 'a' }, m_arr{ 1, 2, 3, 4, 5 }	// { } 초기화
	{
		//
	}
};

//다른 클래스를 멤버로 가질 때 ----------------------------------------------------------

class ABC
{
private:
	int m_abc;
public:
	ABC(const int& n) : m_abc{ n }
	{
	}
};

class Something
{
private:
	int	m_i;
	int	m_arr[5];
	ABC abc;		//다른 클래스 타입의 객체를 멤버로 가질 때

public:
	Something()
		: m_i{ 10 }, m_arr{ 1, 2, 3, 4, 5 }, abc{ m_i - 1 }
		//ABC의 생성자를 불러와 ABC abc{9}; 으로 넘어가게 된다. abc(9)
	{ }
};


//상속 받은 클래스의 경우 처리 순서 ------------------------------------------------------

//생성자의 인수를 받는 부분
//생성자 초기화 리스트 부분
//		메모리를 할당 받는다. 부모 생성자를 호출한다. 부모로부터 상속받은 멤버들을 초기화
//자신의 생성자 {} 중괄호 부분 처리
//		자신만의 멤버들을 초기화한다.

//1 메모리 할당(생성자 초기화 리스트에 있는 자기 자신 멤버들은 쓰레기값만 들어있는 상태)
//2 부모 생성자 호출(물려 받은 멤버는 할당 + 초기화까지 완료)
//3 초기화(생성자 초기화 리스트에 있는 자기 자신 멤버들 초기화)
//4 자신의 생성자 내부 { } 중괄호 부분 처리