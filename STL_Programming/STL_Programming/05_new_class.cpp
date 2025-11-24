#include <iostream>
#include <cstring>
using namespace std;

class Person {
private:
    char name[30];
    int age;
    char gender;

public:
    Person(const char* name, int age, char gender)
        : age(age), gender(gender)
    {
        strcpy(this->name, name);
    }

    void Print() const
    {
        cout << "name  : " << name << endl;
        cout << "age   : " << age << endl;
        cout << "gender: " << gender << endl;
    }
};

int main()
{
    // class new
    {
        Person* p = new Person("양우정", 24, 'F');
        p->Print();
        delete p;
    }

    // class array new
    {
        Person* parray = new Person[3]
        {
            Person("양우정", 24, 'F'),
            Person("양우징", 25, 'M'),
            Person("양우장", 26, 'M')
        };

        for (size_t i = 0; i < 3; i++)
        {
            parray[i].Print();
        }

        delete[] parray;
    }
}
