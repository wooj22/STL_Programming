//fill 
//		지정된 범위를 동일한 값으로 모두 채우는 함수

#include <iterator>// ostream_iterator
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void main()
{
	//fill
	int a[5] = { 1, 2, 3, 4, 5 };
	int b[5] = { 6, 7, 8, 9, 10 };
	fill(a + 2, a + 5, 0);
	fill(b, b + 4, 3);


	//fill
	int arr[10] = {3, 5, 1, 4, 3, 7, 3, 9, 2, 6}; 

	vector<int> v(10); 
	copy(arr, arr+10, v.begin());	//배열을 벡터로 복사

	ostream_iterator<int>  out_iter( cout, " : " );
	copy(v.begin(), v.end(), out_iter);   cout <<endl;

	fill(v.begin(), v.end(), 10);            //fill
     
	copy(v.begin(), v.end(), out_iter);   cout <<endl;
}


