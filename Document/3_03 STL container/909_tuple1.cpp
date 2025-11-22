//tuple은 기존의 pair를 확장한 자료형입니다.
//		pair가 2개의 값을 한 번에 저장할 수 있지만 tuple은 제한이 없습니다.
//		서로 다른 타입의 데이타를 하나로 묶어서 취급 

#include <tuple>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	// make tuple variable. ----------------------------------------------------	
	
	//서로 다른 타입의 데이타를 하나로 묶어서 취급 
	 
	// 10, "Even", true  를 튜플로 묶어 선언하세요.
	tuple<int, string, bool> tp = make_tuple(10, "Even", true);

	//위 선언을 출력해 보세요.
	auto nNum   = get<0>(tp);	//int
	auto szVal	= get<1>(tp);	//string
	bool bEven	= get<2>(tp);	//bool
	cout << nNum << ", " << szVal << ", " << boolalpha << bEven << endl;


	//튜플의 개수 얻기. tuple_size< >::value

	tuple<int, double> tp = make_tuple<int, double>(1, 1.0);
	auto nTupleCount = tuple_size <decltype(tp)>::value;
	cout << nTupleCount << endl;


	//tuple의 각 위치의 값을 변수에 한꺼번에 담기 --------------------------------
	
	tuple<int, string, bool> myNumber1 = make_tuple(10, string("Even"), true);
	tuple<int, string, bool> myNumber2 = make_tuple(7, string("Odd"), false);
		
	// tie() and ignore. 

	int  nVal;
	bool bEven2;
	tie(nVal, ignore, bEven2) = myNumber1;		//std::ignore 해당 위치 무시 
	cout << nVal << ", " << bEven2 << endl;

	// auto [] 를 사용  //C++17

	auto [a, d] = myNumber2;				 
	cout << a << ", " << d << endl;

	return 0;
}


// 이름과 나이를 담기 위해 <string, int> 튜플을 선언 후 출력해 보세요. //make_tuple()

// 선언된 튜플을 함수에 전달해 출력해 보세요.

//void print(std::tuple<int, bool> tVal)
//{
//	std::cout << std::get<0>(tVal) << ", " << std::get<1>(tVal) << std::endl;
//}

// 선언된 튜플을 name, age 변수에 분해해 보세요. // tie, auto[]