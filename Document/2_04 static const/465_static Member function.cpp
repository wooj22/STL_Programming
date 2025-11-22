
//static 함수 -------------------------------------------------------------

//static 함수는 객체 내에 존재하는 함수가 아니기 때문에, 
//		non-static 멤버변수나 멤버함수에 접근이 불가능하다. 
//		static 함수에서는 
//		static 변수에만 접근 가능하고, static 함수만 호출 가능하다. ***

#include <iostream>
using namespace std;

class CTest
{
private:
	int num1 = 0;
	static int num2;
public:
	static void Add()
	{
		//num1++;			//error //static 함수는 객체 사용 못함.
		num2++;
	}
};

int CTest::num2 = 0; //static 변수의 초기화


//static 맴버는 멀티쓰레드와 관련하여 동시성 문제 우려. 주의해서 사용해야 한다.

//멤버 함수는 모두 code 영역에 저장되며, 멤버 함수는 객체마다 다르게 동작하는 것이 아니다.
 

//객체의 멤버변수에 접근할 필요가 없는 메소드는 static을 붙이는 게 당연히 효율적일까?
//
//절차 지향에 가까운 키워드, 객체 지향에서 멀어지고, 메모리 공간 효율이 떨어질 수 있다.
//다형성 활용 안됨, Overriding(메소드 재정의)과 Dynamic Binding(동적 바인딩)이 불가
//자주 사용하는 함수의 경우에 적절히 사용하자. 

