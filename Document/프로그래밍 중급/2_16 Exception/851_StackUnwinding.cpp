// 스택 프레임
// 
//	함수가 호출될 때 
//	스택에는 매개변수로 전달되는 인자 값, 함수의 반환 값, 함수를 마치고 복귀할 번지수, 지역변수 등의 정보가 저장되는데, 
//	이러한 정보를 '스택프레임' 이라고 합니다.
// 
//  스택 풀기 (Stack Unwinding)
//	스택프레임의 항상성 유지를 위해, 호출원을 거슬러 올라가 스택을 정리하며 빠져나가게 됩니다.

// Stack Unwinding (스택 풀기, 스택 되감기)	//디버그 
//
//	함수 내에서 try, catch 구문이 없고, throw 만 발생시키는 함수의 경우에는
//	catch를 찾기 위해 함수 외부를 찾게 됩니다.
//	예외를 던진 함수의 외부에서 catch를 찾기 위해, 
//	현재의 스택정보를 정리하고 빠져나가는 현상을 Stack Unwinding 이라 한다.

// 예외의 전달
//		예외가 처리되지 않으면, 
//		예외가 발생한 함수를 호출한 영역으로 예외 데이터가(더불어 예외처리에 대한 책임까지) 전달된다.
//		자료의 불일치로 인해 예외는 처리되지 않아는 경우도, 예외 데이터는 전달된다. 

#include <iostream>
using namespace std;

void SimpleFunc1(void);
void SimpleFunc2(void);
void SimpleFunc3(void);

int main(void)
{
	try
	{
		SimpleFunc1();
	}
	catch (int expn)
	{
		cout << "예외코드: " << expn << endl;
	}
	return 0;
}

void SimpleFunc1(void) {
	cout << "Func1(void)" << endl;
	SimpleFunc2();
}
void SimpleFunc2(void) {
	cout << "Func2(void)" << endl;
	SimpleFunc3();
}
void SimpleFunc3(void) {
	cout << "Func3(void)" << endl;
	throw - 1;			//예외 발생 시키기
}

