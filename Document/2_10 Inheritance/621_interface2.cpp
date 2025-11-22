//인터페이스 ​__interface
//      virtual 키워드와 = 0 (또는 abstract)이 안붙더라도 순수 가상함수.
//      public 상속만 지원. (공용 순수 가상 메서드만 포함)
//      멤버 변수를 가질 수 없다.
//      생성자, 소멸자 또는 연산자를 포함할 수 없다.
//      정적 메서드를 포함할 수 없다.

// 무조건 재정의해서 사용하도록 의도한다.

#include <iostream>
using namespace std;

__interface A
{
    void test();        // 순수 가상함수 취급됨
};

class B : public A {
};
class C : public A {
    void test();
};
class D : public A {
    void test() {}

};

void main() {
    A a;  //에러 추상클래스를 생성할 수 없음
    B b;  //에러 추상클래스를 생성할 수 없음 (인터페이스가 구현되지 않음)
    C c;  //에러 추상클래스를 생성할 수 없음 (함수 선언만 하고 구현이 안됨)
    D d;  //정상
}

//interface 키워드
//		컴파일러 옵션을 / clr 로 바꾸어 주어야 사용

// ​__interface 사용 예제 ----------------------------

__interface IAnimal
{
	void move();
};

class CAnimal abstract : public IAnimal		//추상클래스
{
private:
	int m_nHp;
public:
	CAnimal();
	virtual ~CAnimal();						//가상소멸자 선언해야 한다. ***
	//void setHp(int nHp);
	//int getHp();
};

class CCat : public CAnimal
{
private:

public:
	CCat();
	virtual ~CCat();
	virtual void move();
};

int main(void) {
	CAnimal* pAnimal = nullptr;
	pAnimal = new CCat();

	delete pAnimal;
	pAnimal = nullptr;
	return 0;
}

