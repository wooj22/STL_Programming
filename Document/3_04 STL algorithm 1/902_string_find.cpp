// string 에서 find 사용하기 

#include <iostream>
#include <string>

void print(std::string::size_type n, std::string const& s) 
{
    if (n == std::string::npos) {
        std::cout << "not found\n";
    }
    else {
        std::cout << "found: " << s.substr(n) << '\n';
    }
}

int main() {
    std::string::size_type n;
    std::string const s = "This is a string";

    // s 의 처음 부터 찾는다.
    n = s.find("is");
    print(n, s);

    // s 의 5번째 문자부터 찾는다.
    n = s.find("is", 5);
    print(n, s);

    // 단일 문자 (a) 를 찾는다.
    n = s.find('a');
    print(n, s);

    // 단일 문자 (q) 를 찾는다.
    n = s.find('q');
    print(n, s);
}

/*

strstr: 문자열에서 원하는 부분 문자열을 리턴한다.

strchr : 문자열에서 특정 문자의 위치를 찾는다.

rfind : 문자열에서 특정 문자열이 마지막으로 나타나는 위치를 찾는다.

find_first_of : 주어진 문자들 중 가장 먼저 나타나는 문자의 위치를 찾는다.

find_first_not_of : 주어진 문자가 아닌 문자가 가장 먼저 나타나는 문자의 위치를 찾는다.

find_last_of : 주어진 문자들 중 가장 끝에 나타나는 문자의 위치를 찾는다.

find_last_not_of : 뒤에서 부터 주어진 문자에 포함되지 않는 문자의 위치를 찾는다.

search : 특정 범위의 원소를 찾는다.

*/