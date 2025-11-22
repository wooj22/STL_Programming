//unordered_set 과 unordered_map 은 
//      원소를 삽입하거나 검색 하기 위해 먼저 "해시함수"라는 것을 사용. *** 
// 
//직접 만든 클래스를 unordered_set 혹은 unordered_map 에 넣으려면   
//      operator< 는 필요하지 않습니다. ( 순서대로 정렬하지 않기 때문에 )
//      하지만 operator== 는 필요. ***

#include <functional>
#include <iostream>
#include <string>
#include <unordered_set>

// 모든 원소들을 출력하기
template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {    
    for (const auto& elem : m) {
        std::cout << elem << std::endl;
    }
}

template <typename K>
void is_exist(std::unordered_set<K>& s, K key) {
    auto itr = s.find(key);
    if (itr != s.end()) { std::cout << key << " 가 존재!" << std::endl; }
    else                { std::cout << key << " 가 없다" << std::endl; }
}

class Todo {
    int         priority;   //중요도 (높을 수록 급한 것)
    std::string job_desc;   //할일

public:
    Todo(int priority, std::string job_desc) : priority(priority), job_desc(job_desc) {}

    friend struct std::hash<Todo>;                  //friend 해시함수

    bool operator==(const Todo& t) const {          //operator==
        if (priority == t.priority && job_desc == t.job_desc) return true;
        return false;
    }

    friend std::ostream& operator<<(std::ostream& o, const Todo& t);
};

// '해시함수'를 위한 함수객체(Functor) 를 만들어줍니다! // namespace std
namespace std {
    template <>
    struct hash<Todo> {
        size_t operator()(const Todo& t) const {  //해시함수는 내부 원소값을 변경하지 않아야 한다.
            hash<string> hash_func;
            return t.priority ^ (hash_func(t.job_desc));
        }
    };
}  

std::ostream& operator<<(std::ostream& o, const Todo& t) {
    o << "[중요도 : " << t.priority << " ] " << t.job_desc;
    return o;
}

int main() {
    std::unordered_set<Todo> todos;

    todos.insert(Todo(1, "농구 하기"));
    todos.insert(Todo(2, "수학 숙제 하기"));
    todos.insert(Todo(1, "프로그래밍 프로젝트"));
    todos.insert(Todo(3, "친구 만나기"));
    todos.insert(Todo(2, "영화 보기"));

    print_unordered_set(todos);
    std::cout << "----------------" << std::endl;
}


  
//해시 테이블(Hash Table)
//    key와 value로 된 쌍을 저장하는 자료구조이다.
//    해시 함수를 사용하여 입력 키 값으로부터 해시 값을 얻어 
//    그것을 인덱스로 사용하는 것은 효율적인 검색 방식 중 하나이다. (상수 시간)
//    이와 같은 해시 값으로 이루어진 자료구조를 '해시 테이블'이라고 부른다.

//해시 함수(Hash Function)
//    해시 함수는 임의의 길이의 문자열을 받아서 고정 문자열로 바꾸어주는 함수 
//    같은 입력에 같은 출력 보장, 가능한 고르게 균등한 분포하는 특성을 지닌다.
//    암호학적 해시함수의 종류로는 MD5, SHA계열 해시함수가 있으며 비암호학적 해시함수로는 CRC32등이 있다.
// 
//    해시함수 알고리즘은     
//    긴 길이의 데이터를 짧은 길이의 데이터로 변환하는 알고리즘으로     
//    따라서 제3자는 짧은 길이의 데이터로부터 원래의 데이터를 복구할 수 없어야 하며, 
//    동일한 출력을 갖는 서로 다른 데이터를 찾을 수 없어야 한다.

//해시 충돌(Hash Collision)
//    해시 함수가 무한한 가짓수의 입력값을 받아 유한한 가짓수의 출력값을 생성하는 경우, 
//    해시 충돌은 항상 존재한다.
// 
//    서로 다른 문자열을 해시한 결과가 동일한 경우
//    Chaining 혹은 Open Addressing을 통해서 해결
// 
//    해시 충돌을 처리하는 방식 중 가장 많이 쓰이는 것이 
//   '체이닝'(chaining, 각각의 해시 테이블 인덱스에 해당하는 자료구조를 연결 리스트로 만드는 방법)과 
//   '개방 번지화'(open addressing, 해시 테이블 인덱스 중 비어있는 공간을 할당하는 방법)'이다. 

//https://woo-dev.tistory.com/106

