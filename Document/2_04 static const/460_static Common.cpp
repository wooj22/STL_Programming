//static 변수		
//	static 키워드를 사용해 선언한 변수로, 
//	프로그램 실행 동안 메모리에 한 번만 할당되고, 
//	프로그램이 종료될 때까지 그 값이 유지되는 변수
//
//	지역 한정된 전역변수

#include <iostream>
using namespace std;

void Counter()
{
	static int cnt;			//프로그램 실행시 생성 // 자동 초기화
	cnt++;
	cout << "Current cnt: " << cnt << endl;
}

int main(void)
{
	for (int i = 0; i < 10; i++)
		Counter();
	return 0;
}

// static 선언 위치 ***
// 
// 함수(지역) 내의 static 변수
//		함수 내부에서 접근 가능
// 전역/파일 (static 전역 변수)
//		해당 소스 파일에서만 접근 가능
//		일반 전역 변수와 달리, 링크 단위(translation unit) 내부에서만 유효합니다
// 클래스의 static 멤버 변수
//		static으로 선언된 멤버 변수는 모든 객체가 값을 공유
//		클래스 이름으로 직접 접근
//		선언만 클래스 내부에서 하고, 정의(초기화)는 클래스 외부에서 해야 합니다
//		(C++17부터는 inline으로 클래스 내부에서 초기화 가능)
