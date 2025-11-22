// 정적 배열
//		컴파일 타임에 배열의 크기가 미리 정해져 있는.
//		프로그램 실행 전 미리 배열의 크기만큼 스택 메모리로부터 메모리를 할당 받는다.
//		따라서 배열의 크기 지정이 필수

#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

int main()
{
	int array[5] = { 1, 2, 3, 4, 5 };					//C

	std::array<int, 5> my_arr = { 1, 2, 3, 4, 5 };		//C++

	my_arr.at(3);						// 맴버 함수 제공
	my_arr.size();

	//array = { 2, 3, 4, 5, 6 };		// 불가능.
	my_arr = { 2, 3, 4, 5, 6 };			// 가능 ***

	std::sort(my_arr.begin(), my_arr.end());	

	for (auto& element : my_arr) { cout << element << " "; }

	return 0;
}

//파라미터로 std::array를 보낼 때 원래 성질이 그대로 유지된다
//배열과 달리 std::array인 정적 배열은 매개변수 타입이 될 수 있다. ***
void printLength(array<int, 5> my_arr)
{
}


//매개변수 타입을 참조 혹은 const 참조로 하여 복사(copy) 없이 
//std::array 정적 배열을 참조할 수 있도록 하는 것이 성능면에서 좋다

#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

void printLength(const array<int,5>& my_arr) 
{
}

int main()
{
	array<int, 5> my_arr = { 1, 2, 3, 4, 5 };

	printLength(my_arr);
}
