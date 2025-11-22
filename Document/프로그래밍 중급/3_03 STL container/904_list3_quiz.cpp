//list 연습문제

#include<iostream>
#include<list>
using namespace std;

template <typename T>       // print_list 출력 템플릿 만들기
void print_list(list<T>& lst) {
    std::cout << "[ ";
    for (const auto& elem : lst) std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

bool predicate(char c)
{
    return (c != 'k' && c != 'o' && c != 'r' && c != 'e' && c != 'a');
}

bool predicate2(char c)
{
    return (c == 'k' || c == 'o' || c == 'r' || c == 'e' || c == 'a');
}

int main()
{
    list<char> alpha_list;

    // a ~ z 까지 추가하세요.
    for (char c = 'a'; c <= 'z'; c++) {
        alpha_list.push_back(c);
    }

    // k o r e a 만 남기고 삭제하세요.  //remove_if
    alpha_list.remove_if(predicate);
    print_list(alpha_list);

    //---------------------------------------------------------
    list<char> alpha_list2;

    // a ~ z 까지 추가하세요.
    for (char c = 'a'; c <= 'z'; c++) {
        alpha_list2.push_back(c);
    }

    // k o r e a 만 삭제하세요.
    alpha_list2.remove_if(predicate2);
    print_list(alpha_list2);

    //alpha_list 에 alpha_list2  merge ------------------------
    alpha_list.merge(alpha_list2);
    print_list(alpha_list);

    return 0;
}

// list 정렬해 봅시다.

#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

struct Item   // 사용할 구조체.
{
    string name;
    int level;

    /*bool operator<(Item item) {
        return this->level > item.level;
    }*/
};

//bool compare(Item a, Item b) { return a.level > b.level; }

int main(void)
{
    //list를 만들어  Item 추가하기
    list<Item> items = { Item{ "단검", 1},Item{ "장검", 2},Item{ "갑옷", 7},Item{ "반지", 3} };
    items.push_back(Item{ "벨트", 10 });

    //level 큰 순서대로 정렬

    //items.sort();                                                 // operator<   
    //items.sort(compare);                                          // 함수
    //items.sort([](Item a, Item b) { return a.level > b.level; });  // 람다    

    //목록 출력
    for (auto& e : items) cout << e.name << " " << e.level << endl;

}


/*

// list
//1. 고정길이인 배열에 비해 길이가 가변적입니다. 동적으로 크기가 변경이 가능합니다.
//2. 중간에 데이터 삽입이나 삭제가 가능합니다. 놀라운 건 상수시간 복잡도의 수행성능 ***
//3. 순차 접근은 가능하나, 랜덤 접근은 불가능합니다.  [0]

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
using namespace std;

template < typename T >
void print_list(list<T>& ls) {
    for (auto itr = ls.begin(); itr != ls.end(); ++ itr) cout << *itr << " ";
    cout << endl;
}

struct Item         // 사용할 구조체.
{
    string name;
    int level;
    bool operator<(Item a) { return level > a.level; }		// <
};
bool compare(Item a, Item b) { return a.level > b.level; }	// compare

int main(void)
{
    list<Item> mylist;
    for (size_t i = 1; i < 10; i++)	    // level 1 ~ 9 Item 추가
    {
        Item s; s.level = i; s.name = "item" + to_string(i);
        mylist.push_back(s);
    }
    mylist.sort();													// operator<
    mylist.sort(compare);											// 함수포인터
    mylist.sort([](Item a, Item b) { return a.level < b.level; });  // 람다
    mylist.sort([](Item a, Item b) { return a.name < b.name; });    // 람다

    for (auto& e : mylist )	cout << e.name  << " " << e.level << " ";

    return 0;
}
*/

