//call by reference	//참조 전달 

#include <iostream>
using namespace std;

void SwapByRef(int &r1, int& r2)
{
	int temp = r1;
	r1 = r2;
	r2 = temp;
}

int main(void)
{
	int val1 = 10;
	int val2 = 20;

	SwapByRef(val1, val2); //매개변수의 형태로 구분하지 말자
	cout << "val1: " << val1 << endl;
	cout << "val2: " << val2 << endl;
	return 0;
}

/*
//연습) 절대값을 구하는 함수를 작성하세요.

	#include <iostream>
	using namespace std;

	void absolute(int &a)	// 참조 호출
	{
		if (a < 0) a = -a;
	}
	void absolute(int *a)	// 주소 호출
	{
		if (*a < 0) *a = -(*a);
	}

	int main(void)
	{
		int a = -1;
		cout << a << endl;

		absolute(a);	// 1번 참조 호출
		cout << a << endl;

		absolute(&a);	// 2번 주소 호출
		cout << a << endl;

		return 0;
	}
*/