// 원소를 탐색하는 함수(find, find_if)

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main() 
{
    // using std::find with array and pointer:              //배열에서 찾기
    int myints[] = { 10, 20, 30, 40 };
    int* p;
    p = std::find(myints, myints + 4, 30);                  // find, 위치 반환
    if (p != myints + 4)  std::cout << "Element found in myints: " << *p << '\n';
    else                  std::cout << "Element not found in myints\n";


    // using std::find with vector and iterator:            //백터에서 찾기
    std::vector<int> myvector(myints, myints + 4);
    std::vector<int>::iterator it;
    it = find(myvector.begin(), myvector.end(), 30);        // find, 못 찾으면 v.end()                              
    if (it != myvector.end()) std::cout << "Element found in myvector: " << *it << '\n';
    else                      std::cout << "Element not found in myvector\n";


    // find, distance                                       // 모두 찾기 ***

    std::vector<int> vec = { 5,3,1,2,3,4 };
    auto current = vec.begin();
    while (true) {
        current = std::find(current, vec.end(), 3);
        if (current == vec.end()) break;
        std::cout << "3 은 " << std::distance(vec.begin(), current) + 1 << " 번째 원소" << std::endl;
        current++;
    }
}


/*
//정의
template <class InputIterator, class T>
InputIterator find(InputIterator first, InputIterator last, const T& val);

//구현
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