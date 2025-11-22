//디폴트 복사 생성자, 디폴트 복사 대입 연산자
//      따로 정의를 하지 않으면 컴파일러가 알아서 생성해 준다. 
//      디폴트 복사 생성자, 디폴트 복사 대입 연산자는 모두 '얕은 복사'를 한다.

//'깊은 복사'가 필요하다면 
//      복사 생성자와 복사 대입 연산자를 구현해야만 한다. ***

#include <iostream>
using namespace std;

class Person {
public:
    int age;
    char* name;

    Person(int _age, const char* _name) {
        age = _age;
        int len = strlen(_name) + 1;
        name = new char[len]; strcpy_s(name, len, _name);
    }
/*
    Person(const Person& p)                 //복사 생성자
    {
        age = p.age;
        int len = strlen(p.name) + 1;
        name = new char[len]; strcpy_s(name, len, p.name);
    }

    Person& operator=(const Person& p)      //복사 대입 연산자
    {
        if (this != &p) {
            delete[] name;
            age = p.age;
            int len = strlen(p.name) + 1;
            name = new char[len]; strcpy_s(name, len, p.name);
        }
        return *this;
    }
*/
    ~Person()
    {
        delete[] name;
    }

    void PrintInfo() {
        cout << "이름: " << name << endl;
        cout << "나이: " << age << endl;
    }
};

void main()
{
    Person A(20, "홍길동");
    Person B = A;

    //B.age = 30;
    //int len = strlen(B.name) + 1;
    //strcpy_s(B.name, len, "이순신");

    A.PrintInfo();
    B.PrintInfo();
}