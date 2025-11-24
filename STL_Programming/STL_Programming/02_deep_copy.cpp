/*
    [ Deep Copy (깊은 복사) ]

    얕은 복사는 동적 멤버를 복사할 때 포인터 주소만 복사하기 때문에 두 객체가 동일한 메모리를 공유하게 된다.
    -> 데이터 공유 문제 발생!
    -> 소멸 시 double delete 문제 발생!

    깊은 복사는 동적 멤버를 "새로운 메모리에 다시 할당"하여 객체마다 독립적인 데이터를 가지도록 하는 방식으로
    특수 멤버함수인 복사 생성자를 직접 구현해주면 된다.
*/

#include <iostream>
#include <cstring>
using namespace std;

class Deep
{
public:
    int num;
    char* str;

public:
    Deep(int n, const char* s) : num(n)
    {
        str = new char[strlen(s) + 1];
        strcpy_s(str, strlen(s) + 1, s);
    }

    ~Deep()
    {
        delete[] str;
    }

    // 복사 생성자 (Deep Copy)
    Deep(const Deep& other) : num(other.num)
    {
        str = new char[strlen(other.str) + 1];
        strcpy_s(str, strlen(other.str) + 1, other.str);

        cout << "[Deep Copy Constructor 호출]\n";
    }

    // 복사 대입 연산자 (Deep Copy)
    Deep& operator=(const Deep& other)
    {
        cout << "[Deep Copy Assignment 호출]\n";

        // 자기 자신 대입 방지
        if (this == &other)
            return *this;

        // 기존 메모리 해제
        delete[] str;

        // 새 메모리 할당 및 복사
        num = other.num;
        str = new char[strlen(other.str) + 1];
        strcpy_s(str, strlen(other.str) + 1, other.str);

        return *this;
    }

    void SetStr(const char* s)
    {
        delete[] str;
        str = new char[strlen(s) + 1];
        strcpy_s(str, strlen(s) + 1, s);
    }
};

int main()
{
    Deep d1(1, "Deep 1");
    Deep d2 = d1;              // deep copy, 두 객체는 각자의 str을 가짐

    cout << "값 변경 전\n";
    cout << "Deep d1 >> num : " << d1.num << ", str : " << d1.str << endl;
    cout << "Deep d2 >> num : " << d2.num << ", str : " << d2.str << endl;

    cout << "\nDeep d2의 str을 \"Deep 2\"로 변경\n";
    d2.SetStr("Deep 2");

    cout << "Deep d1 >> num : " << d1.num << ", str : " << d1.str << endl;   // d1은 그대로
    cout << "Deep d2 >> num : " << d2.num << ", str : " << d2.str << endl;   // d2만 바뀜

    // 두 객체가 각자의 동적 메모리 공간을 가지고 있기 때문에 double delete[] x, 크래쉬 안남!
}
