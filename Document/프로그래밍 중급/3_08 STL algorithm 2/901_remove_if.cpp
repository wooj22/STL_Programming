//람다 함수 Lambda
//  익명 함수(Anonymous functions), 함수를 보다 단순하게 표현하는 방법
//  코드를 데이타처럼 사용 (매개변수로 전달, 리턴)
//  장점 코드의 간결함, 지연 연산을 통한 퍼포먼스 향상, 
//  이터레이션 관련 코드를 구현하는 데 있어 불필요한 부분들을 제거할 수 있다


//람다 함수
//    [capture list](받는 인자) -> 리턴 타입 { 함수 본체 }    
//    [capture list](받는 인자) {함수 본체}   //리턴 타입을 생략할 경우


//람다 함수 실행
//    auto func = [](int i) { return i % 2 == 1; }; func(4);  // false;
//    [](int i) { return i % 2 == 1; }
//    [](int i) { return i % 2 == 1; }(3);  // true


//캡쳐 목록(capture list)을 사용, 외부 변수 접근
// [] : 아무것도 캡쳐 안함
// [=] : 외부의 모든 변수들을 복사본으로 캡쳐
// [&] : 외부의 모든 변수들을 레퍼런스로 캡쳐
// [&a, b] : a 는 레퍼런스로 캡쳐하고 b 는(변경 불가능한) 복사본으로 캡쳐// 


#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";  begin++;
    }
    std::cout << std::endl;
}

int main() 
{
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    //std::cout << "처음 vec 상태 ------" << std::endl;
    print(vec.begin(), vec.end());
    
    //벡터에서 홀수인 원소를 제거하세요.

    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int i) -> bool { return i % 2 == 1; }),
        vec.end());

    print(vec.begin(), vec.end());
}


//캡쳐 사용 예제 //벡터에서 홀수인 원소를 제거하고, 지운 갯수 기록하세요. ----------------

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

int main() 
{
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    print(vec.begin(), vec.end());

    std::cout << "벡터에서 홀수인 원소 ---" << std::endl;
    int num_erased = 0;                                         //지운 갯수 기록
    vec.erase(std::remove_if(vec.begin(), vec.end(),
                    [&num_erased](int i) {                      //람다 캡쳐
                        if (num_erased >= 2)  return false;
                        else if (i % 2 == 1) { num_erased++; return true; }
                        return false;
                    }),
            vec.end());
    print(vec.begin(), vec.end());
}
