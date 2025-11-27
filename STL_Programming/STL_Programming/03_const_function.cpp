/*
	함수에도 const가 쓰일 수 있으며, 방식은 크게 3가지로 분류된다.

	1. 매개변수 const	(참조, 포인터)
		매개변수의 const는 상수나 변수를 받아서 변경하지 않고 쓰겠다는 의미
		매개변수의 값을 변경하지 않고 사용할 때 사용된다.

	2. 반환 타입에 const (참조, 포인터)
		함수 앞에 붙은 const는 함수의 리턴값을 상수화 시키겠다는 의미
		반환된 값을 변경하지 못하도록 하기 위해서 사용된다.

	함수 자체에도 const가 쓰일 수 있으나, 이는 클래스의 멤버에만 해당한다.
*/

//-----------------------------------------------------------
// 1. 매개변수 const
// const T&
void Func2(const int& data)
{
	data = 10;		// 데이터 변경 불가
}

// const T*
void Func4(const int* ptr)
{
	*ptr = 20;		// 역참조 값 변경 불가
}

// T* const
void Func4(int* const ptr)
{
	int temp = 10;
	ptr = &temp;	// 포인터 주소 변경 불가
	*ptr = 20;		// 역참조 값 변경 가능
}

// const T* const
void Func4(const int* const ptr)
{
	int temp = 10;
	ptr = &temp;	// 포인터 주소 변경 불가
	*ptr = 20;		// 역참조 값 변경 불가
}


//-----------------------------------------------------------
// 2. 반환타입 const

// const &
const int& Func5()
{
	static int a;
	return a;
}

// const *
const int* Func6()
{
	int* a = new int();
	return a;
}


int main()
{
	const int& ref = Func5();
	ref = 20;	// 값 변경 불가

	const int* ptr = Func6();
	*ptr = 20;	// 역참조 값 변경 불가
	ptr = &ref;	// 주소 변경 가능
}
