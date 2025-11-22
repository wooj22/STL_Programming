// Callable 이란 
// 
//   이름 그대로 나타내듯이 호출(Call) 할 수 있는 모든 것 (함수, 함수객체, 람다)
/*
	#include <iostream>										
	using namespace std;
	
	void func() {
		std::cout << "Func 호출! " <<std::endl;
	}

	struct S {
		void operator()(int a, int b) { std::cout << "a + b = " << a + b << std::endl; }
	};

	int main()
	{
		func();				//호출 (함수)

		S some_obj;
		some_obj(3, 5);		//호출 (함수객체) 

		auto f = [](int a, int b) { std::cout << "a + b = " << a + b << std::endl; };
		f(3, 5);			//호출 (람다) 
	}
*/

// std::function 
// 
//		Callable 들을 객체의 형태로 보관할 수 있는 클래스
//		함수(Callable)를 매개변수로 전달 받거나 리턴할 때, 보관할 때 편리
//		#include <functional> 
/*
	function< 함수형식 > 변수명 = 함수;
	함수형식 = 반환형(입력형식)

	예) bool foo1(int a) { return true; }		// bool(int)
	예) void foo2(int a, int b) { }				// void(int,int)
	예) string foo3(float a, double b) { }		// string(float,double)
*/

#include <functional>   //
#include <iostream>
#include <string>
using namespace std;

int some_func1(const std::string& a) {
	std::cout << "Func1 호출! " << a << std::endl;
	return 0;
}

struct S {
	void operator()(char c) { std::cout << "Func2 호출! " << c << std::endl; }
};

int main() 
{
	std::function<int(const std::string&)> f1 = some_func1;							//함수
	std::function<void(char)> f2 = S();												//함수객체
	std::function<void()> f3 = []() { std::cout << "Func3 호출! " << std::endl; };	//람다

	f1("hello");
	f2('c');
	f3();
}
