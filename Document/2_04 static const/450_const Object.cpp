//상수 멤버 변수(constant member variable)
//		상수 멤버 변수란 한 번 초기화하면, 그 값을 변경할 수 없는 멤버 변수를 의미합니다.
//		const double pi = 3.141592;

//상수 멤버 함수(constant member function)
//		상수 멤버 함수란 호출한 객체의 데이터를 변경할 수 없는 멤버 함수를 의미합니다.
//		이러한 상수 멤버 함수는 함수의 원형 마지막에 const 키워드를 사용하여 선언합니다.
//		const 멤버 함수
//		const 함수내에서는 동일 클래스에 선언된 멤버변수의 값을 변경하지 못한다 ***

//const 객체 (상수 객체) ---------------------------------------------------------------- 
//		멤버변수나 멤버함수 뿐만 아니라, 객체에도 const 키워드를 사용할 수 있다. 
//		객체 생성시에 const 키워드를 사용하면, 
//		그 객체는 상수로 취급되어 초기화된 데이터 외의 다른 데이터로 변경할 수 없다.(읽기전용 객체)
// 
//		const 객체는 당연하게도 const 멤버함수만을 제대로 사용할 수 있다. ***


//클래스의 const 맴버함수 -----------------------------------------------------------------

class SimpleClass
{
	int num1;
	const int num2;
public:
	SimpleClass(int n1 = 0, int n2 = 0)
	{
		num1 = n1; num2 = n2;
	}
	void ShowData() const		//const 함수 //맴버값 변경하지 않음 ***
	{
		cout << num1 << ' ' << num2 << endl;

		num1++;					//error
	}
};

//상수화 된 객체 (상수 객체) ----------------------------------------------------------------

#include <iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int n) : num(n) { }

	void ShowData() const	// 1. 상수 맴버함수. '멤버변수의 값'을 변경하지 않겠다.
	{
		cout << "num: " << num << endl;
		//num++;			// const 함수는 동일 클래스에 선언된 '멤버변수의 값'을 변경하지 못한다.
		//AddNum(1);		// const 함수는 const가 아닌 함수를 호출하지 못한다! ***
	}
	CTest& AddNum(int n)		// 참조로 반환, 즉 객체를 그대로 받음
	{
		num += n;
		return *this;			// *this - 객체
	}
};

int main(void)
{
	const CTest obj(7);		// 2. 상수 객체. 이 객체의 데이터 변경을 허용하지 않겠다 ***
	obj.ShowData();

	// obj.AddNum(20);		// const로 상수화 된 객체는 const로 선언되지 않는 멤버함수의 호출이 불가능 ***

	return 0;
}

//const 객체 (상수 객체) ---------------------------------------------------------------- 
//		멤버변수나 멤버함수 뿐만 아니라, 객체에도 const 키워드를 사용할 수 있다. 
//		객체 생성시에 const 키워드를 사용하면, 
//		그 객체는 상수로 취급되어 초기화된 데이터 외의 다른 데이터로 변경할 수 없다.(읽기전용 객체)
// 
//		const 객체는 당연하게도 const 멤버함수만을 제대로 사용할 수 있다. ***


class Something
{
public:
	int m_Value;

	Something() : m_Value(0) { }

	void SetValue(int value) { m_Value = value; }
	int GetValue() { return m_Value; }
};

int main()
{
	const Something something{};	//const 객체 // 기본 생성자 호출

	something.m_Value = 5;      // 컴파일 에러: const 위반
	something.SetValue(5);      // 컴파일 에러: const 위반

	return 0;
}


// const 멤버함수 ***
// 
//		멤버함수에 const를 사용하는 이유는 객체의 멤버변수를 변경시킬 수 없도록 하기 위해서이다.
// 
// 상수 멤버 함수는 아래와 같은 특징을 가지고 있다.
// 
//		상수 멤버 함수안에서	멤버 변수 값을 바꾸는 행위를 할 수 없다.
//		상수 멤버 함수안에서	비-상수 멤버 함수를 호출할 수 없다.
// 
//		상수 객체에서 호출할 수 있다. ( 비-상수 객체도 호출 가능 )