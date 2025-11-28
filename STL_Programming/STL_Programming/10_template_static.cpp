/*
	템플릿에서 static은?
	-> 템플릿 인스턴스마다 따로 존재한다!

	MyClass<T> 클래스 템플릿에 static 멤버가 있다고 할 떄,
	 - MyClass<int> 의 static 멤버
	 - MyClass<float> 의 static 멤버
	 - MyClass<std::string> 의 static 멤버
	 - ...
*/

#include <iostream>
using namespace std;

// 클래스 템플릿 Test<T>
template <typename T>
class Test
{
public:
	static int count;
};

// static member init
template <typename T>
int Test<T>::count = 0;

int main()
{
	// Test<int>와 Test<float>는 다른 클래스이다.
	Test<int>::count = 10;		
	Test<float>::count = 20;	

	cout << Test<int>::count << endl;   // 10
	cout << Test<float>::count << endl; // 20

	// Test<float> 클래스에 대해서는 static 변수가 공유된다.
	Test<float> t1;
	t1.count = 30;
	cout << Test<float>::count << endl; // 30
}