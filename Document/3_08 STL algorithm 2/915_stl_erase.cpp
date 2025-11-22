#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> v(10);
    for (int i = 0; i < 10; i++)  v[i] = i;

    // 5 인덱스 (6 번째)를 삭제하라

    v.erase(v.begin() + 5);

    for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;

    return 0;
}

/*
//erase - remove_if ----------------------------------------------

bool badValue(int x)
{
    if (x == 0) {
        std::cout << "same 0" << std::endl;
        return true;
    }
    return false;
}

void main()
{
    std::vector<int> c;
    c.push_back(0);
    c.push_back(1);
    c.push_back(2);
    c.push_back(0);
    c.push_back(10);
    std::cout << "vector size = " << c.size() << std::endl;

    // 0을 모두 삭제하라

    c.erase(std::remove_if(c.begin(), c.end(), badValue), c.end());     // remove_if

    std::cout << "vector size = " << c.size() << std::endl;

    for (int i : c) {
        std::cout << i << " " << std::endl;
    }
}

/*

//컨테이너에서 특정한 값을 가진 객체를 모두 없애려면?
- vector, string, deque이면               erase - std::::remove
- list이면                                list::remove
- 연관 컨테이너(set, multiset, map)면?     erase 멤버 함수

//컨테이너에서 특정한 술어 구문을 만족하는 객체를 모두 없애려면?
- vector, string, deque이면               erase - remove_if 합성문을 사용한다.
- 컨테이너가 list이면                      list::remove_if 를 쓴다.
- 컨테이너가 표준 연관 컨테이너면?          remove_copy_if와 swap을 쓰던가,
  컨테이너 내부를 도는 루프에서 erase를 호출하면서 erase에 넘기는 반복자를 후위 증가 연산자로 증가시킨다.


//루프 안에서 무엇인가를 하려면?--------------------------------------------------------------

    표준 시퀀스 컨테이너
    - 컨테이너 요소를 하나씩 사용하는 루프를 작성한다.
    - erase를 호출할 때마다 그 함수의 반환값으로 반복자를 업데이트하는 일을 꼭 해야한다.

    표준 연관 컨테이너
    - 컨테이너 요소를 하나씩 사용하는 루프를 작성한다.
    - erase를 호출하면서 erase에 넘기는 반복자를 후위 증가 연산자로 증가시킨다.


//remove 활용하는 방법 ----------------------------------------------------------------------
//
//  연속 메모리 컨테이너(vector, deque, string) - erase와 remove 합성문이 가장 좋은 방법이다.
//      양방향 반복자를 지원하는 list에도 통하지만, list는 remove를 사용하는 것이 좋다.
//
//  표준 연관 컨테이너일 때에는(set, multiset, map) remove라는 이름을 가진 어떤 것도 소용없다.
//      remove 알고리즘을 사용하면 컨테이너 값을 덮어써서 컨테이너를 변형시킬 수 있다.

//표준 알고리즘 ( algorithm 헤더 내에 있는 ) 함수들은
//      절대 요소를 삽입하거나 삭제하지 않습니다.   ***
//      프로그래머가 관리하여야 합니다.
//      즉, 컨테이너에서 push, pop, insert, erase 등으로 삽입, 삭제 관리한다.
//
//  std::remove - 찾은 요소 찾은 후 다음 요소부터 끝까지 앞으로 한칸 카피하는 방식.
//  list.remove - 요소를 삭제.

//remove-erase idiom 은
//  std::remove는 forward_iterator를 받는데, 지우는 방법을 모르기 때문에
//  move(copy)를 이용한 값을 앞으로 이동시키만 할 뿐이며
//  표준 컨테이너에서 erase의 2회 이상의 호출을 막기위해서 생성된 것이며
//  실제적으로 삭제를 위해선 erase 함수를 호출하여야 합니다.  ***


//시퀀스 컨테이너에 사용하는 remove 방법은 선형시간. O(n)
//연관 컨테이너는 erase 를 사용한다. 로그시간. O(n log N)

//연관 컨테이너의 erase는 상등성이 아닌 동등성에 기반하고 있다.
// 상등성 ==, 동등성 <



//C++20 //erase_if  - remove-erase idiom 대신 사용 ***
/*
    std::vector< int > v1 = { -2, -1, 0, 1, 2 };

    // 0 미만 삭제
    std::erase_if( v1, []( int InNum ) { return InNum < 0;  } );

    for ( auto num : v1 )
        std::cout << num << " ";
*/