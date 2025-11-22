//copy		
//		범위 안의 값을 복사한다.

#include <iterator>		
#include <vector>
#include <iostream>
using namespace std;

void main()
{
	//copy() 함수			//범위 안의 값을 모두 복사
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 6, 7, 8, 9, 10 };
	copy(a + 1, a + 4, b + 1);


	//배열을 벡터로 복사

	int arr[10] = { 3, 5, 1, 4, 8, 7, 0, 9, 2, 6 };
	vector<int> v(10);

	copy(arr, arr + 10, v.begin());		


	//copy 를 이용해 출력하기 --------------------------------------

	//요소들을 구분자 없이 표준 출력 장치로 출력
	copy(v.begin(), v.end(), ostream_iterator<int>(cout));
	cout << "\n\n";

	//요소들을 구분자(:)와 함께 표준 출력 장치로 출력
	ostream_iterator<int>  out_iter(cout, " : ");
	copy(v.begin(), v.end(), out_iter);
	cout << "\n\n";

	//역방향 반복자로 요소들을 역으로 출력 
	copy(v.rbegin(), v.rend(), out_iter);
	cout << "\n\n";

	// 0-1-2-3-4-5-6-7-8-9  출력하세요.

}