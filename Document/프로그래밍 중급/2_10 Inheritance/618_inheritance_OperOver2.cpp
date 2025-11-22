//상속 구조에서의 대입 연산자

//- 자식 클래스에서 대입 연산자를 오버로딩 하는 경우, 
//  부모 클래스의 대입 연산자를 명시해 주지 않으면 부모 클래스의 대입 연산자는 호출이 되지 않는다.
//- 따라서, 디폴트 대입 연산자의 경우, 
//  부모 클래스의 대입 연산자까지 호출해 주어야 복사가 제대로 이루어질 수 있으므로 주의 ***

#include <iostream>
using namespace std;

class Parent
{
private:
    int n1, n2;

public:
    Parent(int n1 = 0, int n2 = 0) : n1(n1), n2(n2) { }
    void ShowData()
    {
        cout << n1 << " / " << n2 << endl;
    }
    Parent& operator=(const Parent& ref)
    {
        cout << "Parent operator=()" << endl;
        this->n1 = ref.n1;
        this->n2 = ref.n2;
        return *this;
    }
};

class Child : public Parent
{
private:
    int n1, n2;

public:
    Child(int n1, int n2, int n3, int n4) : Parent(n1, n2), n1(n3), n2(n4) { }
    void ShowData()
    {
        Parent::ShowData();
        cout << n1 << " / " << n2 << endl;
    }
    Child& operator=(const Child& ref)
    {
        cout << "Child operator=()" << endl;
        
        Parent::operator=(ref);         //부모 클래스 대입 연산자 호출해야 한다. ***

        this->n1 = ref.n1;
        this->n2 = ref.n2;
        return *this;
    }
};

void main()
{
    Child c1(1, 2, 3, 4);
    Child c2(0, 0, 0, 0);
    c2 = c1;
    c2.ShowData();

    //결과
    //Child operator=()
    //Parent operator=()
    //1 / 2
    //3 / 4
}