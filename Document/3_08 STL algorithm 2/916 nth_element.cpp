//nth_element 
//	first 부터 last 전 까지의 원소들을 부분적으로 정렬합니다. 
//	이 때, 정렬하는 방식은 다음과 같습니다.

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
	std::vector<int> v{ 5, 6, 4, 3, 2, 6, 7, 9, 3 };

	std::nth_element(v.begin(), v.begin() + v.size() / 2, v.end());
	std::cout << "중간값은 " << v[v.size() / 2] << '\n';

	std::nth_element(v.begin(), v.begin() + 1, v.end(), std::greater<int>());
	std::cout << "두 번째로 큰 원소는 " << v[1] << '\n';
}