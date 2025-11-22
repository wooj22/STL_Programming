#include <iostream>
using namespace std;

struct Person {
    char name[30];
    int age;
    char gender;
};

int main()
{
    // 1. 구조체 동적 할당
    Person* ps = new Person;
    strcpy_s(ps->name, "Jake");
    ps->age = 17;
    ps->gender = 'M';

    // 역참조를 하면 도트연산자 사용가능
    cout << "- name  : " << (*ps).name << endl;
    cout << "- age   : " << (*ps).age << endl;
    cout << "- gender: " << (*ps).gender << endl;

    delete ps;

    // 2. 구조체 동적 배열 초기화. Reuse
    ps = new Person[3]{
        {"Mike", 15, 'M'},
        {"Jinn", 16, 'F'},
        {"Waldo", 17, 'M'}
    };

    for (size_t i = 0; i < 3; i++)
    {
        cout << "\n-----------------------";
        cout << " name  : " << (ps + i)->name << endl;
        cout << " age   : " << (ps + i)->age << endl;
        cout << " gender: " << (ps + i)->gender << endl;
    }

    delete[] ps;    // 이번은 배열이니까 []로 배열 메모리 반환

    return 0;
}