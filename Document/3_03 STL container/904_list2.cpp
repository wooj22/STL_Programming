//리스트의 반복자는 
//  BidirectionalIterator 이기 때문에  ++ 과 -- 연산만 사용 가능. 
//  for 문으로 하나 하나 원소를 확인해 보는 것은 가능.
//  vector 와는 다르게 insert 작업은 O(1) 으로 매우 빠르게 실행.
//  벡터와는 다르게, 원소를 지워도 반복자가 무효화 되지 않습니다.

#include <iostream>
#include <list>
using namespace std;

// 전체 리스트를 출력하기 범위 기반 for 문
template <typename T>
void print_list(std::list<T>& lst) {
    std::cout << "[ ";    
    for (const auto& elem : lst) std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

int main() {
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);

    std::cout << "처음 리스트의 상태 " << std::endl;
    print_list(lst);

    // 목록을 순회하면서 찾아내기
    // 만일 현재 원소가 20 이라면, 그 앞에 50 을 집어넣는다.
    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) 
    {        
        if (*itr == 20) {     
            lst.insert(itr, 50);
        }
    }    
    print_list(lst);

    // 값이 30 인 원소를 삭제한다.
    //std::cout << "값이 30 인 원소를 제거한다" << std::endl;
    for (std::list<int>::iterator itr = lst.begin(); itr != lst.end(); ++itr) {
        
        if (*itr == 30) {
            lst.erase(itr);
            break;           // 이것 주의 !!!  내부에서 삭제하면 에러 발생
        }
    }    
    print_list(lst);
}