//partial_sort 함수 //부분 소트
//      first 부터 middle 전 까지 범위 내의 정렬 배치한다.

/*
    template <class RandomIt>
    void partial_sort(RandomIt first, RandomIt middle, RandomIt last);  // (1)

    template <class RandomIt, class Compare>
    void partial_sort(RandomIt first, RandomIt middle, RandomIt last,  Compare comp);  // (2)
*/

//예를 들어서 시험 성적의 하위 100 명만 추려내고 싶다면 
//partial_sort 를 통해서 first 와 middle 을 딱 100 명만 되게 하면 된다.
//이를 통해 sort 를 사용해서 전체 응시자를 정렬하는 것보다 더 효율적으로 수행할 수 있다

#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
using namespace std;

template <typename Iter>
void prn(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

int main()
{
    //------------------------------------------------
    vector<int> vec = { 5,3,1,6,4,7,2 };

    prn(vec.begin(), vec.end());

    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());     //부분 소트

    prn(vec.begin(), vec.end());        //1 2 3 6 5 7 4  

    //------------------------------------------------
    std::array<int, 10> s = { 5, 7, 4, 2, 8, 6, 1, 9, 0, 3 };

    std::partial_sort(s.begin(), s.begin() + 3, s.end());
    for (int a : s) {
        std::cout << a << " ";
    }
    std::cout << endl;


}