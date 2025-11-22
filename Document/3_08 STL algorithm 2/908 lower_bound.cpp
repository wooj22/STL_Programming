//lower_bound, upper_bound
//	용도 : 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
//	       그러한 원소가 없다면 end값을 리턴.
//	사용 조건 : 탐색을 진행할 배열 혹은 벡터는 '오름차순' 정렬되어 있어야 함

//lower_bound - 시작 위치
//upper_bound - 초과 위치

#include <iterator>		// ostream_iterator
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void main()
{
	// lower_bound
	{
		int arr[6] = { 1,2,3,4,5,6 };
		cout << "lower_bound(6) : " << lower_bound(arr, arr + 6, 6) - arr;  
		// 결과 -> lower_bound(6) : 5   //찾으려는 key 값보다 같거나 큰 숫자가 나타나는 인덱스
	}
	{
		vector<int> arr = { 1,2,3,4,5,6,6,6 };
		cout << "lower_bound(6) : " << lower_bound(arr.begin(), arr.end(), 6) - arr.begin();
		// 결과 -> lower_bound(6) : 5	//처음으로 얻을 수 있는 위치
	}
	{

		vector<int> arr = { 1,2,3,4,5,6 };
		cout << "upper_bound(3) : " << upper_bound(arr.begin(), arr.end(), 3) - arr.begin();
		// 결과 -> upper_bound(3) : 3	//배열에서 처음으로 value값을 초과하는 원소의 주소
	}


	//정렬하여 사용 -------------------------------------------------------

	int arr[10] = { 30, 50, 10, 40, 30, 70, 30, 90, 20, 60 };

	vector<int> v(10);
	copy(arr, arr + 10, v.begin());			//배열을 벡터로 복사 copy

	ostream_iterator<int>  out_iter(cout, " : ");
	copy(v.begin(), v.end(), out_iter);	cout << endl;	// ostream 출력

	sort(v.begin(), v.end());				//정렬 후
	copy(v.begin(), v.end(), out_iter);	cout << endl;

	vector<int>::iterator iter;
	iter = lower_bound(v.begin(), v.end(), 80);
	cout << "\n삽입할 수 있는 정렬된 위치의 가장 첫 번째 위치 :";
	cout << *iter << "\n\n";

	v.insert(iter, 80);						//삽입 후   
	copy(v.begin(), v.end(), out_iter);	cout << endl;
}


/*

	//(예) 5 이상 11 이하의 숫자가 몇 개인지 구할 때 ***
	int main()
	{
		vector<int> arr = { 1,3,5,5,7,8,8,10,10,11,13 };
		cout << "5 이상 11 이하의 갯수 : " 
			 << upper_bound(arr.begin(), arr.end(), 11) - lower_bound(arr.begin(), arr.end(), 5);
		return 0;
	}

	//특정한 숫자가 몇 번 나오는지 탐색하고자 할 때 ***
	int main()
	{
		vector<int> arr = { 1,3,5,5,5,8,8,10,10,11,13 };
		cout << "5의 갯수 : " 
			 << upper_bound(arr.begin(), arr.end(), 5) - lower_bound(arr.begin(), arr.end(), 5);
		return 0;
	}
*/