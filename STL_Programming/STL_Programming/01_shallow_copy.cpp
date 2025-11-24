/*
	[ shallow copy (얕은 복사 ]

    class는 기본적으로 얕은 복사를 지원한다. 
    하지만 이는 단순히 해당 객체의 메모리에 있는 값을 복사하는 것이기 때문에
    동적멤버가 있을 경우 객체를 그냥 복사하면 두 객체는 메모리를 공유하게 된다.
    -> 복사생성자, 이동생성자로 깊은 복사(deep copy)의 구현이 반드시 필요하다.
*/

#include <iostream>
#include <cstring>
using namespace std;


class Shallow {
public:
    int num;
    char* str;

public:
    Shallow(int n, const char* s) : num(n) {
        str = new char[strlen(s) + 1];
        strcpy_s(str, strlen(s) + 1, s);
    }

    ~Shallow() {
        delete[] str;
    }

    void SetStr(const char* s)
    {
        strcpy_s(str, strlen(s) + 1, s);
    }
};

int main() {
    Shallow s1(1, "Shallow 1");
    Shallow s2 = s1;      // shallow copy, str멤버를 s1과 s2가 공유!

    cout << "값 변경 전" << endl;
    cout << "Shallow s1 >>  num : " << s1.num << ",  str : " << s1.str << endl;
    cout << "Shallow s2 >>  num : " << s2.num << ",  str : " << s2.str << endl;

    cout << "Shallow s2의 str을 \"Shallow 2\"로 변경" << endl;
    s2.SetStr("Shallow 2");

    cout << "Shallow s1 >>  num : " << s1.num << ",  str : " << s1.str << endl;     // s1도 Shallow 2가 됨!
    cout << "Shallow s2 >>  num : " << s2.num << ",  str : " << s2.str << endl;

    // 종료 소멸자 호출시 하나의 str을 두 객체가 delete[] 시도하여 크래시 발생!
}