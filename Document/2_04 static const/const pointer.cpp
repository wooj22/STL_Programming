//상수 (Constant)
//		변수와 반대로, 처음 정의시 그 값이 바로 주어지고, 그 값이 영원히 바뀌지 않습니다.
//		리터럴상수, 심볼릭상수
//심볼릭 상수(symbolic constant)
//		형한정어 const는 변수를 '상수화'하는 역할

#include <stdio.h>

int main()
{
	const int size = 20;  // a라는 변수는 이제 상수로 사용하겠다. 즉 앞으로 바뀌지 않는다.
	printf("%d", size);

	//size = 30   //error

	return 0;
}

// 함수의 매개변수가 상수형 포인터인 경우
// 함수에서 포인터가 가리키는 대상 메모리에 쓰기를 시도할 수 없다.

void PrintString(const char* pszParam) {
	puts(pszParam);
}

int main(void) {
	char szBuffer[32] = { "I'm a human" };
	// 함수를 호출하더라도 szBuffer의 내용은 변하지 않을 것이다. // 매개변수로 넘길 때 const로 읽기만 가능하게 설정을 해뒀기 때문에.  
	PrintString(szBuffer);
	// 상수를 직접 전달하는것도 가능.
	PrintString("No. You are a dog");
	return 0;
}


//상수화하는 이유는 '유지보수를 쉽게 하기 위함'이다.
//그리고 컴파일러의 입장에서는 줄어든 변수의 수만큼 번역도 유리하며, 성능향상의 효과도 가질 수 있다.
//const가 붙는지 여부에 따라 
//프로그램의 성능이 달라지기도 하고, 실수를 줄여줄 안전장치가 되어주기도 한다. ***


// const 예약어는 
// 위험이 도사리고 있는 포인터를 제한하여, 프로그램의 안전성을 높이는 역할을 한다.
// 함수 내부에서 대상 메모리에 쓰기를 할 일이 없다는 확신이 있다면, 
// 위의 예제처럼 매개변수를 상수형 포인터로 선언하는 것이 중요하다. 

//연습) 해석하기

int main()
{
	//--------------------------------------
	const char* cpch;
	volatile char* vpch;

	//--------------------------------------
	char* const pchc;
	char* volatile pchv;

	//--------------------------------------
	char ch = 'B';
	const char cch = 'A';

	const char* pch1 = &ch;
	char* pch2 = &ch;
	char* const pch3 = &ch;
	const char* const pch4 = &ch;

	const char* pch5 = &cch;
	char* pch6 = &cch;				// Error
	char* const pch7 = &cch;		// Error
	const char* const pch8 = &cch;

	*pch1 = 'A';	// Error: object declared const
	pch1 = &ch;		// OK: pointer not declared const
	*pch2 = 'A';	// OK: normal pointer
	pch2 = &ch;		// OK: normal pointer
	*pch3 = 'A';	// OK: object not declared const
	pch3 = &ch;		// Error: pointer declared const
	*pch4 = 'A';	// Error: object declared const
	pch4 = &ch;		// Error: pointer declared const

}


// 개체에 포인터에 대한 포인터가 있는 경우, 개체를 const로 선언하는 방법
struct X {
	X(int i) : m_i(i) { }
	int m_i;
};

int main() {
	// correct
	const X cx(10);
	const X* pcx = &cx;
	const X** ppcx = &pcx;

	// also correct
	X const cx2(20);
	X const* pcx2 = &cx2;
	X const** ppcx2 = &pcx2;
}

//const 키워드는 
//  const 초기화 후 포인터를 수정할 수 없으므로, 포인터가 수정되지 않도록 보호되도록 지정합니다.

//volatile 키워드는 
//  volatile 다음 이름과 연결된 값을 사용자 애플리케이션의 작업 이외의 작업으로 수정할 수 있도록 지정합니다.
//	따라서 컴파일러는 volatile 선언된 변수에 대해서는 최적화를 수행하지 않는다.

//cv 는 비슷한 성질을 지니는 키워드 ***
