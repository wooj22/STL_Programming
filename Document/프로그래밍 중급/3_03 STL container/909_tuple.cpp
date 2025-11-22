// tuple
//		튜플을 통해 각각 자료형이 다른 두개 이상의 리턴값을 받을 수 있다.
//		서로 다른 타입의 데이타를 하나로 묶어서 취급하는 방법. 

#include <iostream>
#include <tuple>					//tuple
using namespace std;

/*
//구조체를 리턴

struct S { int a; double b; };

S getStruct()
{
	S my_s{ 1, 2.5 };
};

int main()
{
	S my_s = getStruct();
	cout << my_s.a << endl;
	cout << my_s.b << endl;
	return 0;
}
*/
 
//구조체를 리턴받아 값을 받을 경우 한번에 여러개의 값을 받을 수 있다.
//함수를 하나 만들 때마다 구조체 또한 또 만들어야 하는게 단점
//튜플(Tuple)로 극복할 수 있다.

// 튜플을 리턴
std::tuple<int, double> getTuple()
{
	int a = 10; double d = 3.14;
	return std::make_tuple(a, d);
}

int main()
{
	//tuple 선언 하기 
	//1, 3.14
	std::tuple<int, double> tp1 = std::make_tuple(1, 3.14);
	//1, 3.14, "hello"
	std::tuple<int, double, string> tp2 = std::make_tuple(1, 3.14, "hello");


	//개별 요소 얻기
	std::tuple<int, double> my_tp = getTuple();

	cout << std::get<0>(my_tp) << endl;				// a. int다 	
	cout << std::get<1>(my_tp) << endl;				// b. double이다.  

	std::get<0>(my_tp) = 11;						// 변경.


	//두 정수 몫과 나머지 구하는 함수 작성 후, 리턴받아 출력하세요.


	//C++ 17 -------------------------------------------------
	//		get() 함수 없이 튜플 요소 분해 가능
	auto [a, d] = getTuple();				//대괄호 []를 쓴다.
	cout << a << ", " << d << endl;

}

//C++ 17 사용하는 방법 ***
//		프로젝트 우클릭 / 속성 / C/C++ / 언어 / C++언어 표준 / C++17 standard 선택