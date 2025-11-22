// list sort, erase

// list 출력하기  >> 
// for_each

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

struct User {
    std::string name;
    int age;
    User(std::string name, int age) : name(name), age(age) {}

    bool operator<(const User& u) const { return age < u.age; }
    //bool operator>(const User& u) const { return age > u.age; }
};

std::ostream& operator<<(std::ostream& o, const User& u) {
    o << u.name << " , " << u.age;
    return o;
}

bool isValue(User& user)
{
    if (user.age > 20) return true;
    return false;
}

void printAddOne(User user)
{
    cout << user.name << "," << user.age + 1 << endl;
}

int main() {
    list<User> ls1;
    User user1 = User("1", 10);
    User user2 = User("2", 30);
    User user3 = User("3", 20);
    ls1.push_back(user1);
    ls1.push_back(user2);
    ls1.push_back(user3);

    //내림차순 정렬
    ls1.sort();
    //ls1.sort(greater<User>());
    for (auto e : ls1) cout << e.name << "," << e.age << endl;


    //특정 조건 삭제
    ls1.erase(remove_if(ls1.begin(), ls1.end(), isValue), ls1.end());
    //ls1.remove_if(isValue);
    for (auto e : ls1) cout << e.name << "," << e.age << endl;


    //기능 수행
    for_each(ls1.begin(), ls1.end(), printAddOne);

}
