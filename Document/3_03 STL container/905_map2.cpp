//map 예제  //추가
// 
// 아래의  투수 방어율을 map 에 추가한 후, 출력하세요.
// 
//"박세웅", 2.23
//"해커 ", 2.93
//"차우찬", 3.04
//"장원준 ", 3.05
//"니퍼트", 3.56
//"박종훈", 3.76

#include <iostream>
#include <map>
#include <string>

template <typename K, typename V>
void print_map(std::map<K, V>& m)  // 맵의 모든 원소들을 출력하기
{
    for (auto itr = m.begin(); itr != m.end(); ++itr) {
        std::cout << itr->first << " " << itr->second << std::endl;
    }
}

int main() 
{
    std::map<std::string, double> pitcher_list;

    // 맵의 insert 함수는 pair 객체를 인자로 받는다.
    pitcher_list.insert(std::pair<std::string, double>("박세웅", 2.23));
    pitcher_list.insert(std::pair<std::string, double>("해커 ", 2.93));

    // 타입을 지정하지 않아도 간단히 std::make_pair 함수로 std::pair 객체를 만들 수 도 있다.
    pitcher_list.insert(std::make_pair("차우찬", 3.04));
    pitcher_list.insert(std::make_pair("장원준 ", 3.05));

    // 혹은 insert 를 안쓰더라도 [] 로 바로 원소를 추가할 수 있다.
    pitcher_list["니퍼트"] = 3.56;
    pitcher_list["박종훈"] = 3.76;

    print_map(pitcher_list);

    //std::cout << "박세웅 방어율은? :: " << pitcher_list["박세웅"] << std::endl;
}

