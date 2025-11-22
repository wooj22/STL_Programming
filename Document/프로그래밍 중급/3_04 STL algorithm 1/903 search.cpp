//search
//      첫 번째로 등장하는 '원소열'을 찾기
//      특정 범위의 데이타를 찾을때 사용

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void main()
{
    vector<int> v1 = {1,2,3,4,5};
    vector<int> v2 = {3,4};

    vector<int>::iterator iter;

    iter = search(v1.begin(), v1.end(), v2.begin(), v2.end());      //v1에서 v2를 search 한다

    if (iter != v1.end()) {
        cout << " v2는 v1의 서브 집합이며 순서가 같습니다." << endl;
        cout << " 첫 번째 서브 집합 시작 위치의 index는 "
            << iter - v1.begin() << "입니다." << endl;
    }
}


//예시) search ------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

// cont 안에 s 가 있는지 없는지를 리턴한다.
template <typename Container>
bool in_quote(const Container& cont, const std::string& s) {
    return std::search(cont.begin(), cont.end(), s.begin(), s.end()) != cont.end();     //search
}

int main()
{
    std::string str = "why waste time learning, when ignorance is instantaneous?";
    std::cout << std::boolalpha
        << in_quote(str, "learning") << '\n'
        << in_quote(str, "lemming") << '\n';

    // str.find() can be used as well ---------------------------------------

    std::vector<char> vec(str.begin(), str.end());
    std::cout << std::boolalpha
        << in_quote(vec, "learning") << '\n'    //vector
        << in_quote(vec, "lemming") << '\n';


    // Boyer-Moore 알고리즘을 사용해서 검색을 수행한다.  ----------------------

    std::string in =
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit,"
        " sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";
    std::string needle = "pisci";

    auto it =
        search(in.begin(), in.end(),                                          //search
            std::boyer_moore_searcher(needle.begin(), needle.end()));         //boyer_moore_searcher

    if (it != in.end())
        std::cout << "The string " << needle << " found at offset " << it - in.begin() << '\n';
    else
        std::cout << "The string " << needle << " not found\n";
}