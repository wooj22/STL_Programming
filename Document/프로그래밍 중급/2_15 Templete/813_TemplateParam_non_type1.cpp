// non-type template paramete 와 template 인자 추론

#include <iostream>
using namespace std;

template<int i> void func1(int a[i]) { std::cout << i << endl; }

template<int i> void func2(int(*a)[i]) { std::cout << i << endl; }

template<int i> void func3(int(&a)[i]) { std::cout << i << endl; }

template<int i> void func4(int a[5][i]) { std::cout << i << endl; }

int main()
{
	int a[5];
	int b[10][10];

	func1(a);		//error	//int* 이므로 i 는 사용 안함
	func2(&a);
	func2(b);
	func3(a);
	func4(b);		//int(*a)[i]
}

//-------------------------------------------------------

template<int i>
class MyClass { static constexpr int var = i; };

template<int i>
void process1(MyClass<i> c) { std::cout << i << std::endl; }

template<int i>
void process2(MyClass<i - 0> c) { std::cout << i << std::endl; }

int main()
{
	MyClass<10> c;
	process1(c);
	process2(c);  // <i - 0> 표현식은 추론 안됨
}