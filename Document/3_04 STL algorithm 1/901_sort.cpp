// sort 함수 사용하기 --------------------------------------------------

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

int main() 
{
    vector<int> vec = {5,3,1,6,4,7,2};

    //정렬 전 -----------------------------
    print(vec.begin(), vec.end());

    std::sort(vec.begin(), vec.end());

    //std::sort(vec.begin(), vec.end(), greater<int>()); //함수객체 참고
     
    //정렬 후 -----------------------------
    print(vec.begin(), vec.end());       
    
}

//참고로 sort 에 들어가는 반복자의 경우 
//반드시 임의접근 반복자(RandomAccessIterator) 타입을 만족해야 하므로, ***
// 
//컨테이너들 중에선 vector 와 qeque 만 가능하고 
//나머지 컨테이너는 sort 함수를 적용할 수 없습니다. ( 자체 sort 사용 ) ***

