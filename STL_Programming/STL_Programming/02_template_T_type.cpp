/*
  [ 템플릿의 형식 연역(type deduction) 규칙]

	템플릿 형식 연역(type deduction) 규칙은 T를 명시하지 않았을 때 컴파일러가 자동으로 T를 추론하는 규칙을 말한다.
	const, volatile, 참조(&), rvalue, 배열, 함수 포인터 등은 타입이 그대로 전달되지 않고 변환/조정될 수 있다.
	따라서 기대한 타입과 다르게 추론될 수 있으며, 필요하면 템플릿 인수 명시나 &/const 조합을 조정해야 함
	
	! 템플릿은 initializer_list<T> 타입 형식 추론 불가
	 { ... } 중괄호 초기화 자체는 타입이 없는 리터럴이다.
	 따라서 함수 템플릿에서 인수로 { ... }를 넘기면 템플릿 타입 추론이 불가능하다.
	 {}의 형식 연역을 위해서는 T 타입을 명시하거나 템플릿 특수화 또는 오버로딩이 필요하다.

    ! 템플릿의 T 형식 연역은 cosnt, volatile을 무시한다.
      cosnt, volatile을 유지하고싶다면 추가로 타입을 선언하거나
      참조 또는 포인터로 T를 받아야 한다.

    ! 일반 함수와 마찬가지로 배열을 T arr[] 혹은 T* arr로 받으면 
      배열은 포인터로 변환(decay) 되므로 원본 배열의 크기를 알 수 없다.
      T(&arr)[N]처럼 배열 참조와 비타입 템플릿 매개변수 N을 같이 사용하면
      decay 되지 않고 배열 원본처럼 안전하게 사용 가능하다.
*/

#include <iostream>
using namespace std;

// 1. T (값 전달)
template<class T>
void Func1(T n)
{
	// const, volatile 제거
}

// 2. T& (lvalue 참조)
template<class T>
void Func2(T& n)
{
	// const, volatile 속성 유효
}

// 3. T&& (보편참조)
template<class T>
void Func3(T&& n)
{
	// const, volatile 속성 유효
}

// 4. T* (포인터)
template<class T>
void Func4(T* n)
{
	// const, volatile 속성 유효
}

// 5. 배열
template<class T, size_t N>
void FuncArray(T(&arr)[N])
{
	// 배열을 그냥 T arr[] 또는 T* arr처럼 받으면 포인터로 deacy되어 size 정보가 사라짐
    // 배열포인터 형식으로 매개변수를 선언하여 배열 원본 속성 유지
}

// 6. 함수포인터
template<class T>
void FuncFuncPtr(T* func)
{
	
}

// 7. initializer_list (추론 불가, T 명시 필요)
template<class T>
void FuncInitList(initializer_list<T> il)
{
	
}

void MyFunc(int) {}

int main()
{
    int x = 10;
    const int cx = 20;
    volatile int vx = 30;

    int arr[5] = { 1,2,3,4,5 };

    // 1. T
    Func1(x);      // int
    Func1(cx);     // int (const 제거)
    Func1(vx);     // int (volatile 제거)

    // 2. T&
    Func2(x);      // int
    Func2(cx);     // const int
    Func2(vx);     // volatile int

    // 3. T&&
    Func3(100);    // int
    Func3(x);      // int&
    Func3(cx);     // const int&

    // 4. 포인터
    Func4(&x);     // int
    Func4(&cx);    // const int
    Func4(&vx);    // volatile int

    // 5. 배열
    FuncArray(arr);          // int, N = 5
    const int carr[3] = { 1,2,3 };
    FuncArray(carr);         // const int, N = 3

    // 6. 함수 포인터
    FuncFuncPtr(&MyFunc);    // void(int)

    // 7. initializer_list
    // FuncInitList({1,2,3});     // 타입 추론 불가
    FuncInitList<int>({ 1,2,3 }); // T 명시 필요

    return 0;
}