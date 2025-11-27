/*
	[ static ]

	static 키워드는 정적 선언 키워드로
	프로그램 실행동안 메모리에 한번만 할당되고, 프로그램이 종료될 떄 까지 그 값이 유지된다.


	1. 함수 내의 static 지역 변수
		함수 내부에서 접근 가능하며,
		함수 종료 후에도 값이 유지되어 다음 호출 시 공유 가능하다.

	2. static 전역 변수
		일반 전역변수는 프로그램 전체에서 접근이 가능하지만
		static 전역변수는 해당 소스파일 내에서만 접근이 가능하다.

	3. static 함수
		파일 단위 접근 제한으로, 해당 파일 내에서만 호출 가능하다.
		객체와 무관하게 호출 가능하며, 모듈 내부 구현용 함수로 사용.

	4. 클래스의 static 멤버 변수
		객체 단위가 아닌 클래스 단위로 존재하며, 모든 객체가 값을 공유한다.
		객체 없이 클래스 이름으로 접근이 가능하다
		반드시 클래스 외부에서 초기화가 필요하다.

	5. static 멤버 함수
		객체 없이 클래스 이름으로 호출 가능하다.
		static 멤버 변수만 사용할 수 있으며, this의 사용이 불가능하다.
*/

#include <iostream>
using namespace std;

// static 전역 변수
static int counter;	     // 다른 파일에 counter 이름을 사용해도 이름 충돌 x

// static 전역 함수
static void Counter() {} // 다른 파일에 counter 이름을 사용해도 이름 충돌 x

void AddData()
{
	// static 지역 변수
	static int data;		// 함수 종료 후에도 유지.
	data++;
	cout << data << endl;
}

int main()
{
	for (int i = 0; i < 10; i++) AddData();
}