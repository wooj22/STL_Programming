//multimap
//      맵과 다르게, 한 개의 키에 '여러개의 값'이 대응될 수 있다. 
//      하지만, 이 때문에 [] 연산자를 멀티맵의 경우 사용할 수 없다.

#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(const std::multimap<K, V>& m)  // 맵의 모든 원소들을 출력하기
{
    for (const auto& kv : m) {
        std::cout << kv.first << " " << kv.second << std::endl;
    }
}

int main() {
    std::multimap<int, std::string> m;
    m.insert(std::make_pair(1, "hello"));
    m.insert(std::make_pair(1, "hi"));
    m.insert(std::make_pair(1, "ahihi"));
    m.insert(std::make_pair(2, "bye"));
    m.insert(std::make_pair(2, "baba"));

    print_map(m);
    std::cout << std::endl;

    // find // 뭐가 나올까요?        
    std::cout << m.find(1)->second << std::endl;


    //해당 키값을 가지는 value 를 전부 출력하려면 ***
    auto range = m.equal_range(1);
    for (auto itr = range.first; itr != range.second; ++itr) {
        std::cout << itr->first << " : " << itr->second << " " << std::endl;
    }

    //만약 키값을 기준으로 삭제를 하면, 
    //한 개가 지워지는 것이 아니라 키값이 1인 모든 원소가 삭제되어 버린다! ***
    m.erase(1);
    print_map(m);
}