//상속 클래스의 형식 변환
//
//  부모 클래스와 자식 클래스 간의 관계, 형변환

#include <iostream>

class Parent
{
public:
    Parent() {}
    Parent(int x, int y) { this->width = x;        this->height = y; }
protected:
    int width;
    int height;
};

// 다음과 같은 형태로 상속 받는다.
class Child :public Parent
{
public:
    Child();
    int getArea() { return this->width * this->height; }
    int area;
};

// 다음과 같은 형태로 부모클래스의 생성자를 호출할 수 있다.
Child::Child() :Parent(100, 20)
{
    this->area = this->width * this->height;
}

int main()
{
    // 상속한 객체 사용
    Child    obj;    std::cout << obj.area;

    // 1. 형변환
    Parent   parent1;
    Child    child1 = parent1;      // Error 자식클래스에 부모객체는 담지 못한다.
    Child    child2;
    Parent   parent2 = child2;      // OK 부모클래스에 자식객체는 담을 수 있다.

    // 2. 포인터간 형변환
    Parent   parent3;
    Child* child3 = &parent3;       // ERROR 자식클래스의 포인터에 부모객체의 주소는 담지 못한다.
    Child    child4;
    Parent* parent4 = &child4;      // OK 부모클래스의 포인터에 자식객체의 주소는 담을 수 있다.

    // 3. 레퍼런스간 형변환
    Parent   parent5;
    Child& child5 = parent5;        // ERROR 자식클래스의 참조값에 부모객체의 주소는 담지 못한다.
    Child    child6;
    Parent& parent6 = child6;       // OK 부모클래스의 참조값에 자식객체의 주소는 담을 수 있다.

    return 0;
}


//상속 클래스의 형식 변환한 경우의 맴버 접근 -------------------------------------------------

//C++ 컴파일러는 포인터를 이용한 연산의 가능성 여부를 판단할 때, 
//  선언된 포인터의 자료형을 기준으로 판단하지, 
//  실제 가리키는 객체의 자료형을 기준으로 판단하지 않는다.
//  따라서 포인터 형에 해당하는 클래스의 멤버에만 접근이 가능하다. 

#include <iostream>
#include <cstring>
using namespace std;

class CPlayer
{
private:
    int m_data = 0;
public:
    CPlayer() { }
    ~CPlayer() { }
    void CPlayerFunc() { cout << "CPlayerFunc()" << endl; }
};

class Monster : public CPlayer
{
public:
    Monster() { }
    ~Monster() { }
    void MonsterFunc() { cout << "MonsterFunc()" << endl; }
};

void main()
{
    CPlayer player;
    Monster a;

    CPlayer* p = new Monster();		//업 캐스팅 // ok // 추상성이 높은 것으로 대표한다.
    
    Monster* pa = new CPlayer();	//다운 캐스팅 // error //접근범위가 넓으면 위험


    //업 캐스팅 -------------------------------------------------------------------------------
    //  자식객체를 부모 클래스로 캐스팅하는 것이 가능하다.
    //  부모클래스로 선언한 객체로 자식클래스를 가리킬 수 있다. 

    // 문제는 형식이 다른 경우 
    p->CPlayerFunc();               // 호출되는 함수는 CPlayer ? Monster ?


    // 포인터 형에 해당하는 클래스의 멤버에만 접근이 가능 ***    
}

