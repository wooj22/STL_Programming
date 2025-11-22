// 원소를 탐색하는 함수(find, find_if 등등) 람다

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    // find, distance ----------------------------------------------------------

    vector<int> vec = { 5,3,1,2,3,4 };     //3 을 모두 찾아라

    auto current = vec.begin();
    while (true) {
        current = find(current, vec.end(), 3);     
        if (current == vec.end()) break;
        cout << "3 은 " << distance(vec.begin(), current) + 1 << " 번째 원소" << endl;  // distance()
        current++;
    }

    //find_if ----------------------------------------------------------------

    vector<int> vec = { 5,3,1,2,3,4 };     //3 으로 나눈 나머지가 2 인 원소를 찾아라

    auto current = vec.begin();
    while (true) {
        current =
            find_if(current, vec.end(), [](int i) { return i % 3 == 2; });
        if (current == vec.end()) break;
        cout << "3 으로 나눈 나머지가 2 인 원소는 : " << *current << " 이다 " << endl;
        current++;
    }
}

//find_end ---------------------------------------------------------------------------------
//      범위 안에 맨 마지막으로 등장하는 부분 원소열(subsequence)을 찾는다.

#include <algorithm>  // std::find_end
#include <iostream>   
#include <vector>     

bool myfunction(int i, int j) { return (i == j); }

int main() {
    int myints[] = { 1, 2, 3, 4, 5, 1, 2, 3, 4, 5 };
    std::vector<int> haystack(myints, myints + 10);

    int needle1[] = { 1, 2, 3 };

    // using default comparison:
    std::vector<int>::iterator it;
    it = std::find_end(haystack.begin(), haystack.end(), needle1, needle1 + 3);

    if (it != haystack.end())
        std::cout << "needle1 의 마지막 등장 위치 " << (it - haystack.begin())
        << '\n';

    int needle2[] = { 4, 5, 1 };

    // using predicate comparison:
    it = std::find_end(haystack.begin(), haystack.end(), needle2, needle2 + 3,
        myfunction);

    if (it != haystack.end())
        std::cout << "needle2 의 마지막 등장 위치 " << (it - haystack.begin())
        << '\n';

    return 0;
}

// 첫 번째로 등장하는 원소열을 찾고 싶다면 search 함수를 이용

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void main()
{
    vector<int> v1 = { 1,2,3,4,5,3,4 };
    vector<int> v2 = { 3,4 };

    vector<int>::iterator iter;

    iter = search(v1.begin(), v1.end(), v2.begin(), v2.end());      //search

    if (iter != v1.end()) {
        cout << " 첫 번째 서브 집합 시작 위치의 index는 "
            << iter - v1.begin() << "입니다." << endl;
    }
}
