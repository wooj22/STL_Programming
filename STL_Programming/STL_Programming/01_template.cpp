/*
 	[ 제네릭 프로그래밍(generic programming) ]

	데이터 형식에 의존하지 않고 하나의 값이 여러 데이터 타입들을 가질 수 있는 기술에 중점을 두어
	재사용성을 높일 수 있는 프로그래밍 방식


	[ 템플릿 (template) ]

	C++에서 제네릭 프로그래밍을 위해 제공하는 키워드
	사용자가 템플릿 매개변수에 제공하는 인수를 기반으로
	'컴파일 타임'에 함수를 생성한다.

	- 함수 템플릿 : 타입 매개변수를 갖는 일반적인 함수 정의
				   컴파일 시점에 실제 타입(T)을 넣어 함수가 생성됨
	- 템플릿 함수 : 컴파일러가 T를 int, double 등으로 대체해 생성한 함수

	
	- 템플릿 인수가 생략된 경우
		1. 타입 추론(type deduction)이 가능하면, 전달된 인수로 T를 추론
		2. 타입 추론이 불가능하면, default type 사용. 없다면 컴파일에러

	- 비타입(non-type) 템플릿 매개변수
		템플릿에서는 타입 뿐만 아니라 값도 매개변수로 전달 가능하다.
		여기서 값 매개변수는 '컴파일 타임 상수'이어야 한다.
*/

#include <iostream>
using namespace std;

// 함수 템플릿
template <class T = int>		// default type = int
T Add(T n1, T n2)
{
	return n1 + n2;
}

template<class T, size_t N = 10>		// N은 컴파일 타임 상수
void ShowArray(T(&arr)[N])
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
}

// 템플릿 함수 (T = int)
/*
int Add<int>(int num1, int num2)
{
	return num1 + num2;
}
*/

int main()
{
	int result1 = Add<int>(2, 3);		// 템플릿 명시적 인스턴스화
	int result2 = Add<>(2, 3);			// 템플릿 자동 인스턴스화
	cout << result1 << " " << result2 << endl;

	// 비타입(non-type) 템플릿 매개변수 전달
	const int size = 5;
	int array[size] = { 1,2,3,4,5 };
	ShowArray<int, size>(array);
}