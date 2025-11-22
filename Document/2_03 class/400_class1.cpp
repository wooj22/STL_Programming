//객체지향
// 
//	같은 종류에 속하는 멤버변수(데이터)와 멤버함수(기능)를 
//  동일한 '클래스'에 포함하여 하나의 '객체'로 선언하고, 
// 
//	서로 다른 객체간의 메시지 교환에 주안점을 두어, 사용자 정보를 원활하게 처리하는 방법
//	즉, 클래스로 객체를 생성하고, 객체를 중심으로 프로그래밍을 하는 것 ***

//절차지향 -> 객체지향
//  
//	대규모 프로그램 - 성능보다 효율적인 처리가 중요해짐 
// 
//	함수				-> 클래스 ( printf -> cout )
//	잘 사용하는 것	-> 객체를 잘 만들고, 쉽게 사용
//  기계 중심 처리   -> 사람의 사고체계 방식으로 

//객체지향의 주요 특징
// 
//	추상화, 캡슐화, 상속성, 다형성 - 객체간의 관계(SOLID) 

//객체지향의 목적과 장점
//	클래스 - 설계(추상,개념)와 구현(실체)의 분리 
//  구조가 명확해지고 유지보수와 확장성이 좋아짐
//  코드의 재사용성이 높아지고, 대규모 소프트웨어 개발에 적합 


//캡슐화, 정보은닉 --------------------------------------------------
//		class 로 데이타와 기능을 캡슐화 ( 관련된 코드 묶음 )
//		기본값은 private ( 정보 은닉 )

#include <iostream>
#include <cstring>
using namespace std;

class MyClass						//클래스 이름 선언
{
private:							//접근 제어자 (Access Modifier)	
	int a;							//데이터 멤버 (Data Members)
public:								//접근 제어자 (Access Modifier)
	void func() { }					//멤버 함수 (Member Functions)
};									//클래스 선언의 마침 ;

int main()
{
	MyClass mc1;					//자동 객체 생성

	MyClass* mc2 = new MyClass;		//동적 객체 생성
	delete mc2
}

// CPlayer 라는 class 로 데이타와 기능을 캡슐화 - 객체를 생성해서 사용. 

class CPlayer	
{
public:					

	int level = 0;		//데이터 멤버 (Data Members)
	int exp;
	int pos_x, pos_y;
	int hp;
	int ap;

	void Init()			//멤버 함수 (Member Functions)
	{
		level = 1;
	}
	void Move() { pos_x++; }
	bool Attack() {	}
};

class CMonster  //CMonster라는 객체로 데이타와 기능을 캡슐화
{
public:
	int posx, posy;
	int hp;
	int ap;
	void Init() { }
	void Move() { }
	bool Attack() { }
};

int main()
{
	CPlayer myhero;			//CPlayer 클래스로 myhero '인스턴스(객체)' 생성

	myhero.Init();					// 맴버 함수 접근
	cout << myhero.level << endl;	// 맴버 변수 접근	

	CMonster mob01;			//객체 생성
	CMonster mob02;			//객체 생성

	return 0;
}
		