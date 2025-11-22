//unique
//      중복되지 않는 원소들을 앞에서부터 채워나가는 함수
//      erase 함수를 사용하여 뒷 부분에 필요없는 값들을 삭제
//      sort 한 후 사용하라. 

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 중복을 제거하세요 -------------------------

    vector <int> v = { 1,1,2,3,3,4,5,5,5,6 };

    for (const auto& n : v) cout << n << ' ';
    cout << endl;

    //erase와 unique 같이 사용하기   //vector 배열에서 중복제거 
    v.erase(unique(v.begin(), v.end()), v.end());

    for (const auto& n : v) cout << n << ' ';
    cout << endl;


    // 중복을 제거하세요 -------------------------

    vector <int> v = { 1,1,2,3,3,4,5,1,1,6 };


    return 0;
}

/*
int main()
{
    // a vector containing several duplicate elements
    std::vector<int> v{ 1,2,1,1,3,3,3,4,5,4 };

    //람다 출력함수.
    auto print = [&](int id) {
        std::cout << "@" << id << ": ";
        for (int i : v)
            std::cout << i << ' ';
        std::cout << '\n';
    };
    print(1);

    // remove consecutive (adjacent) duplicates
    auto last = std::unique(v.begin(), v.end());
    // v now holds {1 2 1 3 4 5 4 x x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    print(2);


    // sort followed by unique, to remove all duplicates
    std::sort(v.begin(), v.end()); // {1 1 2 3 4 4 5}
    print(3);

    last = std::unique(v.begin(), v.end());
    // v now holds {1 2 3 4 5 x x}, where 'x' is indeterminate
    v.erase(last, v.end());
    print(4);
}
*/

/*
//템플릿

https://en.cppreference.com/w/cpp/algorithm/unique
template<class ForwardIt>
ForwardIt unique(ForwardIt first, ForwardIt last)
{
    if (first == last)
        return last;

    ForwardIt result = first;
    while (++first != last) {
        if (!(*result == *first) && ++result != first) {
            *result = std::move(*first);
        }
    }
    return ++result;
}
*/