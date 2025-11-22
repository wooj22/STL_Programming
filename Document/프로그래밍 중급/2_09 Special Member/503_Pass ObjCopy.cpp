//묵시적으로 복사 생성이 일어나는 경우는 다음 3가지이다
// 
//	1) SampleClass x = y;								//객체 x가 y로 초기화되어 생성
//	2) void func(SampleClass x) { … }					//함수 f()가 호출되어 객체 x가 생길 때.
//	3) SampleClass f() { SampleClass x; …; return x; }	//함수가 객체를 리턴하여 반환 받을 때.


//복사 생성호출 확인하기 // 함수호출

#include <iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int n) : num(n)
	{ 
		cout<<"CTest(int)"<< endl;
	}
	CTest(const CTest& copy) : num(copy.num)
	{
		cout<<"CTest(const CTest& copy)"<<endl;
	}
	void ShowData()
	{
		cout<<"num: "<<num<<endl;
	}
};
	
void SimpleFuncObj(CTest ob)	//call by value 방식 함수호출
{
	ob.ShowData();
}

int main(void)
{
	CTest obj(7);
	cout << "----------------- 1" << endl;

	SimpleFuncObj(obj);
	cout << "----------------- 2" << endl;

	return 0;
}

// 복사 생성이 일어나는지 확인해보세요.