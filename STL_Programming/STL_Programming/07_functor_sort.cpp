/*
	[ sort ]

	std::sort는 함수 객체(functor)를 통해 정렬 옵션을 전달할 수 있다.
	std::sort는 전달받은 comparator를 const 객체 취급하기 때문에
	operator함수는 const 함수로 만들어야 한다. (상수객체는 const 멤버함수만 호출 가능)
	sort함수 내부에서 함수 객체 comparator는 아래와 같이 쓰인다.

	if(comparator(v[i], v[j])
	{
		swap(v[i], v[j]);
	}
*/

#include <iostream>	
#include <vector>
#include <algorithm>

// 오름차순 functor
struct Less
{
	bool operator()(int n1, int n2) const
	{
		return n1 < n2;
	}
};

// 내림차순 functor
struct Greater
{
	bool operator()(int n1, int n2) const
	{
		return n1 > n2;
	}
};

int main()
{
	std::vector<int> vec = { 1,5,3,2,4 };

	// 기본 오름차순 정렬 (<)
	std::sort(vec.begin(), vec.end());		

	// 오름차순 functor
	std::sort(vec.begin(), vec.end(), Less());

	// 내림차순 functor
	std::sort(vec.begin(), vec.end(), Greater());
	std::sort(vec.begin(), vec.end(), std::greater<int>());
}