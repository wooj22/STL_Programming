// find
//      특정 데이타 찾기

// find (InputIt first, InputIt last, const T& value)
//      (first, last, 찾을 데이타 값)
      

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void main()
{
    vector<int>  v(8);
    for (int i = 0; i < v.size(); i++)
        v[i] = i + 1;

    vector<int>::iterator iter;

    iter = find(v.begin(), v.end(), 2);      //find

    //위치(iterator) 반환, 결과가 v.end() 라는 것은 못찾고 끝까지 왔다는 의미.

    if (iter != v.end())    cout << *iter << "를 찾았습니다." << endl;
    else                    cout << "찾는 값이 없습니다." << endl;

    iter = find(v.begin(), v.end(), 20);     //find
    if (iter != v.end())    cout << *iter << "를 찾았습니다." << endl;
    else                    cout << "찾는 값이 없습니다." << endl;
}

/*
template <class InputIt, class T>
constexpr InputIt find(InputIt first, InputIt last, const T& value) {
  for (; first != last; ++first) {
    if (*first == value) {
      return first;
    }
  }
  return last;
}
*/

// find example ---------------------------------------------------

#include <algorithm>  // std::find
#include <iostream>   // std::cout
#include <vector>     // std::vector

int main()
{
    //with array and pointer: // 배열에서 찾기

    int arr[] = { 10, 20, 30, 40 };
    int* p;

    p = std::find(arr, arr + 4, 30);
    if (p != arr + 4)
        std::cout << "Element found: " << *p << '\n';
    else
        std::cout << "Element not found\n";


    //with vector and iterator: // vector에서 찾기

    std::vector<int> v(arr, arr + 4);   // 배열로 백터 초기화
    std::vector<int>::iterator it;

    it = find(v.begin(), v.end(), 30);
    if (it != v.end())
        std::cout << "Element found in myvector: " << *it << '\n';
    else
        std::cout << "Element not found in myvector\n";

    return 0;
}
