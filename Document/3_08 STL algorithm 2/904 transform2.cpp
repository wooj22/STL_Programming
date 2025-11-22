//원소 수정하기 (transform)
//  컨테이너 전체 혹은 일부를 순회하면서 값들을 수정하는 작업
//  transform ( 시작 반복자, 끝 반복자, 결과를 저장할 컨테이너의 시작 반복자, Pred )

#include <algorithm>
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
    //vec1 전체에 1 을 더한 것을 vec2 에 저장하기 ***

    std::vector<int> vec1 = { 5,3,1,2,3,4 };
    std::vector<int> vec2(6, 0);                        // vec2 6개, 0 으로 초기화 한다.

    //처음 vec 과 vec2 상태 
    //print(vec1.begin(), vec1.end());
    //print(vec2.begin(), vec2.end());

    std::transform(vec1.begin(), vec1.end(),
        vec2.begin(), [](int i) { return i + 1; } );    //람다

    print(vec1.begin(), vec1.end());
    print(vec2.begin(), vec2.end());
}


// std::back_inserter ------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::fill_n(std::back_inserter(v), 3, -1);
    for (int n : v)
        std::cout << n << ' ';
}

//back_inserter 함수는 컨테이너를 받아 back_insert_iterator 타입의 객체를 생성하여 반환합니다.
//back_insert_iterator 클래스는 이름 그대로 뒤에 삽입을 위한 일종의 반복자 클래스입니다.
//이 클래스는 내부적으로 대입(= ) 연산자 오버로딩이 되어있습니다.

//back_inserter : 벡터의 맨 끝에 값을 삽입한다.
//front_inserter : 벡터의 맨 앞에 값을 삽입한다.