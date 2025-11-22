
#include <tuple>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	// make tuple variable.
	typedef tuple<int, string, bool> OddOrEven;						
	OddOrEven myNumber = make_tuple(10, string("Even"), true);

	// get tuple size ***
	cout << "size : " << 
		tuple_size<decltype(myNumber)>::value << endl;

	// get , tuple_element
	tuple_element<0, decltype(myNumber)>::type nNum = get<0>(myNumber);		//int
	auto szVal = get<1>(myNumber);											//string
	bool bEven = get<2>(myNumber);
	cout << nNum << ", " << szVal << ", " << boolalpha << bEven << endl;

	// make_tuple()					//tuple 만들기
	typedef tuple<int, string, bool> OddOrEven;
	OddOrEven myNumber1 = make_tuple(10, string("Even"), true);
	OddOrEven myNumber2 = make_tuple(7, string("Odd"), false);

	// tie() and ignore.			//tuple의 각 위치의 값 가져오기
	int nVal;
	bool bEven2;
	tie(nVal, ignore, bEven2) = myNumber1;		//std::ignore 해당 위치 무시 
	cout << nVal << ", " << bEven2 << endl;

	// tuple_cat					// 두 타입의 tuple을 한 개로 연결
	auto myNums = tuple_cat(myNumber1, myNumber2);
	cout << "Value 1 : " << get<0>(myNums) << ", " << get<1>(myNums) << ", " << get<2>(myNums) << endl;
	cout << "Value 2 : " << get<3>(myNums) << ", " << get<4>(myNums) << ", " << get<5>(myNums) << endl;

	// foward_as_tuple //함수에 변수를 생성하지 않고 전달

	print(forward_as_tuple(nVal, bEven));

	return 0;
}

void print(std::tuple<int, bool> tVal)
{
	std::cout << std::get<0>(tVal) << ", " << std::get<1>(tVal) << std::endl;
}


/*
//tuple은 기존의 pair를 확장한 자료형입니다.

	pair가 2개의 값을 한 번에 저장할 수 있지만 tuple은 제한이 없습니다.

//tuple은 '2개 이상의 값'을 '한 번'에 반환하거나 전달할 때 사용하면 유용합니다. ***

	물론 구조체를 통해서 가능한 방법이긴 하지만 구조체는 정의를 해서 사용해야 합니다.
	tuple을 이용하면 간단하게 다양한 값들을 한 번에 전달이 가능하게 됩니다.
	tuple은 구조체를 정의하지 않고도 값의 조합을 생성할 수 있기 때문에 유용하게 활용이 가능합니다.

//make_tuple()

	tuple 변수에 값을 넣을 때는 make_tuple()을 사용하면 됩니다. 
	해당하는 위치에 해당하는 값을 넣으면 생성이 됩니다.

//tuple_size<decltype(myNumber)>::value

	tuple 안에 몇 개의 변수가 존재하는 지는 
	tuple_size<decltype(myNumber)>::value로 가능합니다.
	decltype(myNumber)는 C++11에서 생긴 문법으로 해당 변수의 타입을 유추해줍니다.
	간단하게 auto와 비슷한 기능이라고 할 수 있습니다.

//get<n>( myNumber )

	get<n>(myNumber)로 값을 가져올 수 있습니다.
	인덱스는 0부터 시작해서 해당하는 위치의 값을 가져옵니다.

//tuple_element

	tuple_element를 사용해서 tuple의 특정 위치의 타입을 가져올 수 있습니다.
	또한 auto 키워드, 혹은 직접 타입을 명시하는 것도 가능합니다.  //C++17

//tie

	tie는 개별 변수들을 tuple처럼 만들어서 tuple의 각 위치의 값을 가져옵니다.
	ignore를 사용하면 해당 위치는 값을 가져오지 않게 됩니다.

//tuple_cat

	tuple_cat은 서로 다른 두 타입의 tuple을 한 개로 연결해서 생성하는 역할을 합니다.

//forward_as_tuple

	그리고 tuple 타입을 받는 함수에 변수를 생성하지 않고 
	전달할 수 있는 forward_as_tuple도 존재합니다.

*/