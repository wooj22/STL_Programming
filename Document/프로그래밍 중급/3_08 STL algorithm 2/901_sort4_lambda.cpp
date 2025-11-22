
// sort 함수 사용하기 --------------------------------------------------

// 함수, 함수 객체, 람다

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

bool compare(const int& a, const int& b) { return a > b; }

int main()
{
    vector<int> vec = { 5,3,1,6,4,7,2 };
    print(vec.begin(), vec.end());

    std::sort(vec.begin(), vec.end());
    print(vec.begin(), vec.end());


    //sort 함수는 기본적으로 오름차순으로 정렬을 해줍니다. 
    //만약에 내림 차순으로 정렬하고 싶다면 어떻게 할까요? ***

    // 1. 함수 포인터 사용 ------------------------------------
    std::sort(vec.begin(), vec.end(), compare);

    // 2. 함수객체 전달 ---------------------------------------
    struct int_compare {
        bool operator()(const int& a, const int& b) const { return a > b; }
    };
    std::sort(vec.begin(), vec.end(), int_compare());


    // 3. 미리 정의된 함수객체, functional 해더 ---------------
    std::sort(vec.begin(), vec.end(), greater<int>());

    // 4. 람다 사용 ------------------------------------------
    std::sort(vec.begin(), vec.end(), [](int a, int b)-> bool { return  a < b; });

}

//참고로 sort 에 들어가는 반복자의 경우 
//  반드시 임의접근 반복자(RandomAccessIterator) 타입을 만족해야 하므로, 
//  우리가 봐왔던 컨테이너들 중에선 '벡터'와 '데크'만 가능하고 
//  나머지 컨테이너는 sort 함수를 적용할 수 없습니다.
