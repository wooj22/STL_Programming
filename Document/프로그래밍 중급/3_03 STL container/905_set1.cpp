//set - key 만 저장하는 균형 이진 트리
//  1. 크기가 가변적이다.
//  2. 기본적으로 하나의 데이터를 정렬해야 할 때 사용한다. // 셋의 중요한 특징, 중복된 원소들이 없다.
//  3. key가 있는지 없는지 알아야 할 때 
//  4. 많은 자료를 저장하면서 동시에 빠른 검색을 원할 때

#include <iostream>
#include <set>

template <typename T>
void print_set(std::set<T>& s) // 셋의 모든 원소들을 출력하기 
{
    std::cout << "[ ";
    for (typename std::set<T>::iterator itr = s.begin(); itr != s.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << " ] " << std::endl;
}

int main() 
{
    std::set<int> s;
    s.insert(10);
    s.insert(50);
    s.insert(20);
    s.insert(40);
    s.insert(30);

    std::cout << "순서대로 정렬되서 나온다" << std::endl;
    print_set(s);

    //20 이 s 의 원소인지 출력하세요.

    std::cout << "20 이 s 의 원소인가요? :: ";
    auto itr = s.find(20);
    if (itr != s.end()) {  
        std::cout << "Yes" << std::endl;    
    }
    else {  
        std::cout << "No" << std::endl;  
    }

    std::cout << "25 가 s 의 원소인가요? :: ";
    itr = s.find(25);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    }
    else {
        std::cout << "No" << std::endl;
    }
}


// 연관 컨테이너 ---------------------------------------------------------------------

// 시퀀스 컨테이너 (vector, list, deque), 
// 연관 컨테이너 (associative container) 
//      - 연관 컨테이너는 시퀀스 컨테이너와는 다르게 키(key) - 값(value) 구조

// 셋(set) 과 멀티셋(multiset), 
// 맵(map) 과 멀티맵(multimap)  
//      중복된 원소들이 없느냐에 따라

// 맵은 셋과 거의 똑같은 자료 구조 입니다. (균형 이진 트리)
//      다만 셋의 경우 키만 보관했지만, 맵의 경우 키에 대응되는 값(value) 까지도 같이 보관.
//      맵은 셋 보다 사용하는 메모리가 크기 때문에, 키의 존재 유무만 궁금하다면 셋을 사용하면 된다.

// 그렇다면 뭘 써야 될까?
// 
//  1. 데이터의 존재 유무 만 궁금할 경우 
//      → set
//      중복 데이터를 허락할 경우 
//      → multiset      ( insert, erase, find 모두 O(logN). 최악의 경우에도 O(logN) )
// 
//  2. 데이터에 대응되는 데이터를 저장하고 싶은 경우 
//      → map
//      중복 키를 허락할 경우 
//      → multimap      ( insert, erase, find 모두 O(logN).최악의 경우에도 O(logN) )
// 
//  3. 속도가 매우 중요해서 최적화를 해야하는 경우
//      → unordered_set, 
//      → unordered_map ( insert, erase, find 모두 O(1).최악의 경우엔 O(N) 그러므로 해시함수와 상자 개수를 잘 설정해야 한다! )
