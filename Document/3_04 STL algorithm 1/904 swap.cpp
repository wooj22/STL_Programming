//swap
//		변수 값 교환.

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(void)
{
	//swap

	int x = 3, y = 5;
	swap(x, y);
	cout << x << " " << y << endl;

	//swap_ranges() 함수		//구간 전체를 바꾸는 함수

	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 6, 7, 8, 9, 10 };
	swap_ranges(a, a + 3, b);
	//첫 번째 구간의 시작과 끝을 알면 이미 크기가 정해지므로, 두 번째 구간은 시작만 필요.***

	return 0;
}
