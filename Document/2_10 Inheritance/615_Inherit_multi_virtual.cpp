//virtual inheritance(가상 상속)
//
//		다중상속에서 다이아몬드 구조를 띄게 될 경우, 데이터의 중복과 불필요한 생성자 호출을 막기 위해
//		virtual inheritance(가상 상속)을 사용한다.

#include <iostream>

class A {
public:
    A() { printf("A 생성자\n"); }
    ~A() { printf("A 소멸자\n"); }
    int A_num;
};

class B : virtual public A {                //virtual 이 없으면 A 가 각각 생성됨
public:
    B() { printf("B 생성자\n"); }
    ~B() { printf("B 소멸자\n"); }
private:
    int B_num;
};

class C : virtual public A {                //virtual 이 없으면 A 가 각각 생성됨
public:
    C() { printf("C 생성자\n"); }
    ~C() { printf("C 소멸자\n"); }
private:
    int C_num;
};

class D : public B, public C {
public:
    D() { printf("D 생성자\n"); B::A_num = 0; }
    ~D() { printf("D 소멸자\n"); }
private:
    int D_num;
};

int main(void) {

    D d;
    printf("%d\n", sizeof(d));

    return 0;
}

//virtual 키워드 없이 컴파일 했다면 
//      아마 A의 생성자와 소멸자가 각각 한번씩 총 두번 호출됐을 것이다.
//      A의 멤버에 접근하려면 B::A_member, C::A_member 이런식으로 해야한다.

//B,C 가 virtual 키워드로 A를 상속받으면 문제 해결.
//      그러나 메모리의 크기는 증가한다.
//      virtual base pointer가 메모리에 저장되기 때문


//중복되는 X에 대하여 virtual 로 선언해서 해결해 보자. -------------------------

#include <iostream>

struct X
{
    int x;
};
struct A : public X		// X의 멤버 x를 상속
{
    int a;
};
struct B : public X		// X의 멤버 x를 상속
{
    int b;
};
struct C : public A, public B // 다중 상속
{
    int c;
};

int main()
{
    C c;
    c.x = 10; // 에러 X의 멤버인 x를 A, B 클래스가 상속받은 상태로 접근이 모호.	
}


/*
    //https://hwan-shell.tistory.com/224
    1. 다중상속에서 데이터의 중복과 불필요한 생성자 호출을 막기 위해, 가상 상속을 사용한다. 
    2. 가상 상속시 vbptr((virtual base table pointer))이라는 offset을 가르키는 포인터가 생성되며, 
       virtual로 상속된 클래스는 메모리 구조에서 제일 아래로 가게 된다. (vbptr 를 이용해 접근) 
    3. 이러한 다중상속으로 인한 가상 상속은, 기존 데이터 크기보다 더 커질 수 있으며, 성능 저하를 야기할 수 있다.

*/