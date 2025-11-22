//'예외' 데이터가 catch 블록으로 전달되지 않은 경우는 어떻게 될까?
// 그때는 terminate 함수의 호출로 인해서 프로그램은 종료된다.
 
//예시 // unhandle_exp

#include <iostream>
using std::endl;
using std::cout;
using std::cin;

int divide(int a, int b);	// a/b의 몫만 반환

int main(void)				
{
	int a, b;
	cout << "두개의 숫자 입력 : ";
	cin >> a >> b;
	cout << "a/b의 몫 : " << divide(a, b) << endl;

	return 0;
}

int divide(int a, int b)
{
	if (b == 0) throw b;
	return a / b;
}

/*
// 예외를 처리해 보세요 -------------------------------------

	try {
		cout << "a/b의 몫 : " << divide(a, b) << endl;
	}
	catch (char exception)	//자료형 주의
	{
		cout << exception << " 입력." << endl;
		cout << "입력 오류! 다시 실행 하세요." << endl;
	}
*/


//try 블록을 묶는 기준 ---------------------------------------------------
//
//	try 블록을 묶는 기준은 예외가 발생할만한 영역을 묶는 것이 아니다!
//	예외가 발생할만한 영역만 묶는 것이 아니라, 그와 관련된 모든 문장을 함께 묶어서 
//	이를 하나의 '일(work)'의 단위로 구성해야 한다.

