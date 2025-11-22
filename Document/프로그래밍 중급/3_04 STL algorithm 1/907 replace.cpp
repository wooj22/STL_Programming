// replace
//		특정값을 다른 값으로 변경하기

#include <iterator>	// ostream_iterator
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void main()
{
	int arr[10] = { 3, 5, 1, 4, 3, 7, 3, 9, 2, 6 };
	vector<int> v(10);
	copy(arr, arr + 10, v.begin()); 

	ostream_iterator<int>  out_iter(cout, " : ");
	copy(v.begin(), v.end(), out_iter);	cout << endl;

	replace(v.begin(), v.end(), 3, 10);					//replace 3 -> 10
		
	copy(v.begin(), v.end(), out_iter);	cout << endl;
}