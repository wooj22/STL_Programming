// stable_sort //클래스 정렬하기

// stable_sort 의 경우 그 순서를 처음에 넣었던 상태 그대로 유지함.
//
//  이러한 제약 조건 때문에 stable_sort 는 그냥 sort 보다 좀 더 오래걸립니다.
//  C++ 표준에 따르면 sort 함수는 최악의 경우에서도 O(nlogn) 이 보장되지만 
//  stable_sort 의 경우 최악의 경우에서 O(n(log n)^2) 으로 작동. 조금 더 느린 편.

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) { std::cout << "[" << *begin << "] ";  begin++; }
    std::cout << std::endl;
}

struct User         //클래스 정렬하기
{
    std::string name;
    int age;

    User(std::string name, int age) : name(name), age(age) {}

    bool operator<(const User& u) const { return age < u.age; }
};

std::ostream& operator<<(std::ostream& o, const User& u) {
    o << u.name << " , " << u.age;
    return o;
}

int main()
{
    std::vector<User> vec;

    for (int i = 0; i < 100; i++) {
        std::string name = "";
        name.push_back('a' + i / 26);
        name.push_back('a' + i % 26);
        vec.push_back(User(name, static_cast<int>(rand() % 10)));
    }
    print(vec.begin(), vec.end());

    std::vector<User> vec2 = vec;
    std::stable_sort(vec2.begin(), vec2.end());     //stable_sort
    std::cout << "stable_sort 의 경우 ---" << std::endl;
    print(vec2.begin(), vec2.end());

    std::cout << "sort 의 경우 ---" << std::endl;
    std::sort(vec.begin(), vec.end());              //sort
    print(vec.begin(), vec.end());

}

