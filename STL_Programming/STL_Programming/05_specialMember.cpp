/*
	[ 특수 멤버 함수 ]

    C++에는 컴파일러가 자동으로 생성해주는 총 6개의 멤버 함수가 있다. 
    객체 생성, 복사, 이동, 소멸과 관련된 기본적인 동작을 담당하며 
    이를 특수 멤버 함수(Special Member Functions)이라고 한다.

    >> 자동 생성 조건
    1. 생성자
      - 생성자를 명시적으로 선언하지 않은 경우 자동으로 생성된다
    2. 소멸자
      -  소멸자를 명시적으로 선언하지 않은 경우 자동으로 생성된다
    3. 복사 생성자, 복사대입연산자
      -  복사 생성자, 복사 대입 연산자가 명시적으로 선언되어 있지 않은 클래스에 대해서만 자동으로 생성된다.
         만일 이동 생성자나 이동 대입 연산자가 하나라도 선언되어 있으면 자동 생성되지 않는다.
    4. 이동 생성자, 이동 대입 연산자
      -  생성자를 제외한 특수 멤버함수를 정의했다면 자동으로 작성되지 않는다


    [ 3의 법칙 (Rule Of Three) - C++11 이전] 
     '만일 복사 생성자와 복사 대입 연산, 소멸자 중 하나라도 선언했다면 
     나머지도 전부 선언하는 것이 좋다'
    
    [ 5의 법칙(Rule Of Five) - C++11 이후 ]
     '복사 생성자, 복사 대입 연산자, 이동 생성자, 이동 대입 연산자, 소멸자 중 하나라도 선언했다면 
     나머지도 전부 선언하는 것이 좋다'

    [ 0의 법칙(Rule Of Five) - 모던 C++ ]
     현대 C++ 스타일(모던)에서는 직접 특수 멤버 함수를 구현하지 말고  
     RAII(스마트 포인터, 컨테이너 등)을 이용해 자원을 관리하는 것을 권장한다.
*/

#include <iostream>
#include <cstring>

class Person {
private:
    int* age;
    char* name;

public:
    /* 특수 멤버 함수의 선언 */
    Person() = default;
    Person(int n, const char* s);     // 생성자
    ~Person();    // 소멸자

    Person(const Person& p);                // 복사 생성자
    Person& operator=(const Person& p);     // 복사 대입 연산자

    Person(Person&& p) noexcept;            // 이동 생성자     
    Person& operator=(Person&& p) noexcept; // 이동 대입 연산자  
};

// 생성자
Person::Person(int n, const char* s)
{
    age = new int(n);
    name = new char[strlen(s) + 1];
    strcpy_s(name, strlen(s) + 1, s);
}

// 소멸자
Person::~Person()
{
    delete age;
    delete[] name;
}

// 복사 생성자 (deep copy)
Person::Person(const Person& p)
{
    std::cout << "복사 생성자 호출" << std::endl;

    age = new int(*p.age);
    name = new char[strlen(p.name) + 1];
    strcpy_s(name, strlen(p.name) + 1, p.name);
}

// 복사 대입 연산자 (deep copy)
Person& Person::operator=(const Person& p)
{
    std::cout << "복사 대입 연산자 호출" << std::endl;

    if (this == &p) return *this;

    delete age;
    delete[] name;

    age = new int(*p.age);
    name = new char[strlen(p.name) + 1];
    strcpy_s(name, strlen(p.name) + 1, p.name);

    return *this;
}

// 이동 생성자 (deep copy)
Person::Person(Person&& p) noexcept
{
    std::cout << "이동 생성자 호출" << std::endl;

    age = p.age;
    name = p.name;

    p.age = nullptr;
    p.name = nullptr;
}

// 이동 대입 연산자 (deep copy)
Person& Person::operator=(Person&& p) noexcept
{
    std::cout << "이동 대입 연산자 호출" << std::endl;

    if (this == &p) return *this;

    delete age;
    delete[] name;

    age = p.age;
    name = p.name;

    p.age = nullptr;
    p.name = nullptr;

    return *this;
}


int main()
{
    Person p1(24, "양우정");
    Person p2 = p1;     // 복사생성자
    Person p3;
    p3 = p2;            // 복사 대입 연산자

    Person p4(42, "정우양");
    Person p5 = std::move(p4);  // 이동 생성자
    Person p6;
    p6 = std::move(p5);         // 이동 대입 연산자
}