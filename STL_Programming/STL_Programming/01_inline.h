/*
	[ inline ]

	inline은 컴파일러에게 인라이닝을 요청하는 키워드로,
	함수 호출 오버헤드를 줄이기 위해 함수의 기계어 코드를 호출 지점에 그대로 붙여 넣어달라고 요청하는 것이다.
	즉 헤더에 함수 구현을 넣을 수 있게 해주는 문법 장치로 작동한다.
	하지만 최종적으로 인라인할지 말지는 전적으로 컴파일러가 결정한다.
	(함수가 너무 크거나 복잡할 때, 가상 함수일 때 등 인라이닝이 무시됨)


	위는 일반적으로 알고있는 inline의 기능이다.
	하지만 이는 성능 최적화(인라이닝)는 부수적 효과일 뿐이며,
	inline의 핵심적인 기능은 'ODR(One Definition Rule) 완화'이다.

	inline을 선언하면 헤더에 구현부가 정의되어, 여러 곳에서 헤더를 include할 경우
	원래대로라면 중복 정의 오류가 발생하여야한다.
	하지만 inline은 중복 정의를 허용하여 오류를 발생시키지 않는다. (ODR 예외)
	따라서 inline은 헤더에 함수를 정의해도 문제가 없다. 이게 inline의 핵심이다.
*/

#pragma once

// 일반적인 함수 선언 -> 구현부는 cpp에 분리.
// 이 헤더를 여러곳에서 include해도 링크는 cpp로 되기 때문에 중복 정의 오류 발생 x
int Add(int a, int b);

// 일반 함수를 헤더에 구현할 경우
// 이 헤더를 여러곳에서 include할 경우 중복 정의 오류 발생
int Add2(int a, int b)
{
	return a + b;
}

// Inline 함수
// 헤더에 정의하여도 중복 정의 오류가 발생하지 않는다.
inline int Add_Inline1(int a, int b)
{
	return a + b;
}

// Inline 함수
// cpp에서 inline으로 구현하여 선언부와 구현부를 분리한다.
inline int Add_Inline2(int a, int b);


// class
class Inline {
public:
	// inline 멤버 함수
	// 클래스의 멤버함수를 클래스 내에 구현하면 자동 inline이 된다.
	int Add_Inline1(int a, int b)
	{
		return a + b;
	}

	// inline 멤버 함수
	// cpp에서 inline으로 구현하여 선언부와 구현부를 분리한다.
	inline int Add_Inline2(int a, int b);


	// template은 자동 inline
	// 템플릿은 반드시 헤더에 정의가 있어야한다.
	// 때문에 template은 inline을 선언하지 않아도 자동으로 중복 정의가 허용된다.
	template <class T>
	void Template(T t)
	{

	}
};