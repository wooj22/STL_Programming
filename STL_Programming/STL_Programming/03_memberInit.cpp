// 클래스 멤버변수 초기화
// 멤버를 초기화하지 않으면 쓰레기값이 들어있기 떄문에 꼭 초기화 후 사용해야한다.
// C++11이전은 std::initializer_list<>타입의 자료가 매개변수로 넘어와도
// C++11부터는 {}를 지원하여 std::initializer_list<>의 우선 호출이 가능하다.
// C++11부터는 ()와 {}를 통한 초기화 모두 0으로 초기화해준다.

// C++11 이후 부터는 초기화 할때 {}를 사용하여 안전하게 초기화하기~!

// 초기화 순서대로
// 1. 멤버변수 정의시 초기화
// 2. 생성자 초기화 리스트로 초기화
// 3. 생성자 초기화

#include <iostream>
using namespace std;

class Num {
private:
	int value = 0;			// 1
	const char* text = "";  // 1
	int arr[3];				// 1
	
	// 비정적 상수 멤버
	// C++11 이전 -> 반드시 초기화 리스트에서만 초기화 가능
	// C++11 이후 -> 선언과 동시에 초기화 가능
	const int num = 10;		

public:
	Num() : value(0), text(""), arr{ 1,2,3 } {}	// 2
	Num(int v, const char* t, int a[3]) : value(v), text(t)	// 2
	{
		value = v;			// 3
		text = t;			// 3
		for (int i = 0; i < 3; i++) arr[i] = a[i]; // 3
	}

	// C++ 11이후 {} 초기화로 initializer_list 전달 가능
	Num(int v, const char* t, std::initializer_list<int> list)
		: value(v), text(t)	
	{
		int i = 0;
		for (auto it = list.begin(); it != list.end() && i < 3; ++it, ++i)
			arr[i] = *it;
		for (; i < 3; ++i) arr[i] = 0;
	}
};

class InitTest
{
public:
	int num1;
	int num2;
};

int main()
{
	// C++11 이전
	int arr[3] = { 1,2,3 };
	Num my1(1, "Hi", arr);

	// C++11 이후 {} 초기화
	Num my2{1, "Hi", { 1,2,3 }};


	// 일반 변수 초기화
	int num1 = 5;
	int num2(5);
	int num3{ 5 };

	// 객체 멤버 변수 초기화
	InitTest n1;		// 주의. 멤버가 초기화되지 않음
	InitTest n2();		// 주의. 이건 함수 선언임
	InitTest n3{};		// {} 초기화. 보호 수준과 상관 없이 모든 멤버가 0으로 초기화됨
	InitTest n4{1, 2};  // {} 초기화. public 멤버에 대해 순서대로 할당

	InitTest* n5 = new InitTest;	// 언제나 쓰레기값
	InitTest* n6 = new InitTest();	// C++11 이전 쓰레기값, C++11 이후 0 초기화
	InitTest* n7 = new InitTest{};	// 언제나 {} 0 초기화

	cout << n3.num1 << n3.num2 << endl;
	cout << n4.num1 << n4.num2 << endl;
	cout << n5->num1 << n6->num2 << endl;
	cout << n6->num1 << n6->num2 << endl;
	cout << n7->num1 << n6->num2 << endl;
}

InitTest n2()
{
	return InitTest{};
}