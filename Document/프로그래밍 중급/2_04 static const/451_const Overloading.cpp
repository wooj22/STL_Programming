//함수의 const 선언과 함수 오버로딩

#include <iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int n) : num(n)
	{ }
	CTest& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void Print()			//함수의 const 선언 유무는 함수 오버로딩의 조건이 된다
	{
		cout << "Print: " << num << endl;
	}
	void Print() const		//함수의 const 선언 유무는 함수 오버로딩의 조건이 된다
	{
		cout << "const Print: " << num << endl;
	}
};

void YourFunc(const CTest& obj)	//const, non-const 객체 입력가능
{
	obj.Print();				//const 객체에서 부르기 위해 const 함수 필요.
}

int main(void)
{
	CTest obj1(1);
	obj1.Print();

	//-------------------------------------
	const CTest obj2(2);
	obj2.Print();			//const 객체는 non-const 멤버 함수를 호출할 수 없다.	

	//((const CTest)obj1).Print();

	//-------------------------------------
	YourFunc(obj1);			//일반 객체 전달
	YourFunc(obj2);			//const 객체 전달

	return 0;
}

//상수 멤버함수와 비-상수 멤버함수의 오버로딩 (Overloading const and non-const function)
//	같은 멤버 함수에 대해 상수 버전과 비-상수 버전으로 오버로딩이 가능하다.

//상수 참조로 전달하는 경우가 매우 많고 일반적이므로, const 키워드에 친숙해져야 한다.
//즉, 객체의 상태를 수정하지 않는 멤버 함수를 만드는 것이다.

//const 함수는 non-const 객체나 const 객체 모두에 의해 사용될 수 있다.
//즉, 데이타 변경이 없다면 const 선언으로 모두 사용 가능.