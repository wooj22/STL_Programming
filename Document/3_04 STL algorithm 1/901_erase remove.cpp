// vector 의 원소 제거 ( erase, remove, remove_if )

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) { std::cout << "[" << *begin << "] "; begin++; }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec = { 5,3,1,2,3,4 };

    std::cout << "처음 vec 상태 ------" << std::endl;
    print(vec.begin(), vec.end());


    std::cout << "벡터에서 값이 3 인 원소 제거 ---" << std::endl;

    vec.erase(std::remove(vec.begin(), vec.end(), 3), vec.end());   //erase + remove

    print(vec.begin(), vec.end());
}

//remove 함수 -----------------------------------------------------------------------
//
//  함수의 원형은 이런 식이다.
//  std::remove(begin, end, val);   // 범위지정... , 지울 값.
//
//  std::remove 함수는 원소의 이동만을 수행하지, 실제로 원소를 삭제하는 연산을 수행하지는 않습니다. ***
//  std::remove의 동작방식이 함수호출시 3번째 인자로 넘어온 데이터와 같은 요소를 찾고
//  찾은 요소의 다음 요소에서부터 컨테이너의 마지막 요소까지 모두 한칸 앞으로 카피하는 방식.
 
// 따라서 std::vector 에서 실제로 원소를 지우기 위해서는 반드시 
//      맴버 erase 함수를 호출하여 실제로 원소를 지워야만 합니다. ***
/*
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    vec.erase( std::remove(vec.begin(), vec.end(), 1), vec.end() );
    // std::remove 반환 유ㅣ치로 부터 end() 까지 삭제
    // 결과 2,3 두개만 남는다.
*/

// std::list 에서는 
//      remove 맴버 함수를 제공하므로 
//      원하는 데이터를 가진 요소를 한꺼번에 모두 제거 가능하다.


// remove_if --------------------------------------------------------------------------
//      특정한 조건을 만족하는 원소들을 모두 제거하려면 어떻게 해야 할까요? 
//      remove_if 함수를 사용해야 합니다.


//연습) 벡터에서 홀수 인 원소 제거해 보세요.

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>    //벡터를 출력하는 템플릿
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

struct is_odd {                                                  //함수 객체 만들기
    bool operator()(const int& i) { return i % 2 == 1; }
};

int main() {
    std::vector<int> vec = {5,3,1,2,3,4};

    //std::cout << "처음 vec 상태 ------" << std::endl;
    print(vec.begin(), vec.end());

    //std::cout << "벡터에서 홀수인 원소 제거 ---" << std::endl;
    vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());
    print(vec.begin(), vec.end());
}

//실제 함수를 전달한다면 앞서 만들었던 함수 객체와 정확히 동일하게 동작합니다.
bool odd(const int& i) { return i % 2 == 1; }


//C++ 표준에 따르면 remove_if 에 전달되는 함수 객체의 경우, 
//  이전의 호출에 의해 내부 상태가 달라지면 안됩니다.
//  다시 말해, 함수 객체 안에 인스턴스 변수(num_delete) 를 넣는 것은 원칙상 안된다는 것이지요.
//  가장 이상적인 방법은 STL 알고리즘을 사용할 때 그 안에 직접 써놓는 것 -> 람다 함수 사용
//  람다를 적용해 보세요. 