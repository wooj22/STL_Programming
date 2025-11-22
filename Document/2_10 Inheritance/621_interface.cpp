//추상클래스 vs 인터페이스
// 
//  추상클래스는 일반 멤버, 함수, 순수가상함수등을 모두 포함한 클래스를 말하며,
//  인터페이스는 모두 순수가상함수로 이루어진 것.

//인터페이스 정의를 통해 같은 방법으로 다양한 형식 개체에서 사용

#include <iostream>
#include <string>
using namespace std;

#define interface struct        // class or struct

interface IPlay                 //인터페이스
{
    virtual void Play() = 0;    //순수가상함수
};

class PlayMan : public IPlay
{
    string name;
public:
    PlayMan(string name) { this->name = name; }
    virtual void Play() { cout << name << " 연주하다." << endl; }
};

void Concert(IPlay* iplay)      //인터페이스를 받아서 실행.
{
    iplay->Play();
}

int main()
{
    PlayMan* man = new PlayMan("홍길동");
    Concert(man);
    delete man;
    return 0;
}

/*

interface IStudy
{
    virtual void Study() = 0;
};

class Student : public IStudy
{
public:
    void Study() { cout << "공부하다." << endl; }
};

int main()
{
    IStudy* istudy = new Student();
    istudy->Study();
    delete istudy;

    return 0;
}
*/


//인터페이스의 구현 방법
//
//모든 멤버 함수가 순수 가상 함수(= 0)로 선언된 클래스를 통해 인터페이스를 만듭니다.
//가상 소멸자도 반드시 선언하여, 파생 클래스의 객체가 올바르게 소멸되도록 해야 합니다.

class IShape {
public:
    virtual void draw() = 0;        // 순수 가상 함수
    virtual double area() = 0;      // 순수 가상 함수
    virtual ~IShape() = default;    // 가상 소멸자
};

/*
class ICamera {
public:
    virtual void take() = 0;
    virtual ~ICamera() = default;
};

class Camera : public ICamera {
public:
    void take() override { std::cout << "take picture" << std::endl; }
};

class HDCamera : public ICamera {
public:
    void take() override { std::cout << "take picture HD" << std::endl; }
};

class People {
public:
    void useCamera(ICamera* p) { p->take(); }
};

이렇게 하면 ICamera를 구현한 어떤 카메라도 People에서 사용할 수 있어, 확장성이 뛰어납니다.

정리
    C++에서 인터페이스는 순수 가상 함수만 가진 추상 클래스로 구현합니다.
    인터페이스는 공통 규약만 정의하고, 실제 구현은 파생 클래스가 담당합니다.
    약한 결합, OCP 준수, 다형성 등 객체지향 설계의 장점을 극대화할 수 있습니다.

C++에서 인터페이스는 "순수 가상 함수만 가진 추상 클래스"로, 
기능의 규약만 정의하고 구현은 파생 클래스가 담당한다는 점이 핵심입니다.

*/