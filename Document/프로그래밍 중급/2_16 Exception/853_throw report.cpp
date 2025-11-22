//예외처리 예시
//
//		함수가 에러를 보고하는 전통적인 방법은 에러 코드를 리턴하는 것

#include <iostream>
using namespace std;

enum E_Error { OUTOFMEMORY, OVERRANGE, HARDFULL };		// 에러 코드정의

void report() throw(E_Error)
{
	if (true) throw OVERRANGE;		//예외발생

	//	throw 자체가 함수를 종료하므로 별도의 return 문을 쓸 필요 없다	 
	// 여기까지 왔으면 무사히 작업 완료
}

int main()
{
	try
	{
		report();
		puts("작업을 완료했습니다.");
	}
	catch (E_Error e)
	{
		switch (e)
		{
		case OUTOFMEMORY:
			puts("메모리가 부족합니다.");
			break;
		case OVERRANGE:
			puts("연산 범위를 초과했습니다.");
			break;
		case HARDFULL:
			puts("하드디스크가 가득 찼습니다.");
			break;
		}
	}
}

// 아예 '객체'를 던지는 것이 더 활용성이 높다.