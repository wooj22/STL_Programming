//단순 자료형이 아닌 경우 - class, struct 

//객체를 vector 로 저장하기

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

class Foo
{
    int data = 0;
public:
    Foo() {}
    Foo(int a) :data(a) { }
    Foo(const Foo& a) :data(a.data) { }
    void Show() { cout << data << endl; }
    //int Get() { return data; }
};

int main()
{
    //vector<int> v = { 0,1,2,3,4 };
    //for (auto e : v) cout << e << endl;


    //객체를 배열로 저장하기 ---------------------------------------

    Foo arr1[3] = { Foo(1), Foo(2), Foo(3) };

    Foo arr2[3]{ 1,2,3 };
    for (auto& e : arr2) e.Show();

    //객체를 vector 로 저장하기 -----------------------------------

    vector<Foo> v1 = { Foo(1), Foo(2), Foo(3) };
    for (auto& e : v1) e.Show();

    //std::sort(v1.begin(), v1.end(), [](Foo a, Foo b) { return a.Get() < b.Get(); });
    //for (auto& e : v1) e.Show();

    //정적 생성과 동적 생성 --------------------------------------

    vector<Foo> v2(3, Foo());       //생성자 1번, 복사생성자 3번
    for (auto& e : v2) e.Show();

    vector<Foo*> v3(3, new Foo());  //생성자 1번, pointer들은 방금 생성된 같은 객체의 주소를 저장
    for (auto e : v3) {
        //cout << e << endl;
        e->Show(); 
    }
    for (auto& i : v3)  delete i;    

    return 0;
}

