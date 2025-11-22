// Has a 관계 - 포함관계

#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;    	// 장전된 총알의 수
public:
	Gun(int bnum) : bullet(bnum) { 	}

	void Shut()
	{
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;    // 소유한 수갑의 수
	Gun * pistol;     // 소유하고 있는 권총
public:
	Police(int bnum, int bcuff)	: handcuffs(bcuff)
	{
		if (bnum > 0)	pistol = new Gun(bnum);
		else			pistol = NULL;
	}
	~Police()
	{
		if (pistol != NULL)	delete pistol;
	}
	void PutHandcuff()
	{
		handcuffs--;
	}
	void Shut()
	{
		if (pistol == NULL)	return;
		pistol->Shut();
	}

};

int main(void)
{
	Police pman1(5, 3);
	pman1.Shut();
	pman1.PutHandcuff();

	Police pman2(0, 3);     // 권총 소유하지 않은 경찰
	pman2.Shut();
	pman2.PutHandcuff();
	return 0;
}

// 어떤 경우에 상속을 하면 좋을까? ---------------------------------------------------------
//
// 추상화 : 고양이, 개, 사자 -> 동물
// 추상화 : 장미, 코스모스, 모란, 진달래 -> 꽃
// 추상화 : 무기, 갑옷, 반지, 목걸이 -> 아이템

// is a 관계 
//		상속 : A is a B ( is a 관계 ),  A는 B를 상속하여 구현하기 적당하다.
//		ex) Dog is a Animal 
//
// has a 관계
//		ex) Police has a Gun , 상속관계가 아니다. 
 
// 상속 예제    // Player -> Hero, Npc, Monster, Boss
// 상속 예제    // Item -> Weapon, Armor, Ring, Necklace, Helmet, Boots, Belt, Cape (Cloak)


 
//설계란 객체규정 후 상호 관계를 형성하는 것 ------------------------------------------------
//		UML - 상속, 집합, 연관, 의존 

//UML(Unified Modeling Language) : 시스템을 모델로 표현해주는 대표적인 모델링 언어
//		클래스 다이어그램 : 시스템의 정적인 면을 보여주는 대표적인 UML 구조 다이어그램, 클래스들 사이의 관계를 표현한다.
//		일반화 관계, 실체화 관계, 연관 관계, 집합 관계, 의존 관계 ...

//디자인 패턴 : 
//		객체 지향 프로그래밍 설계를 할 때 자주 발생하는 문제들을 피하기 위해 사용되는 패턴
//		GOF의 디자인 패턴

//Visual Studio - 프로젝트 우클릭 - 보기 - 클래스 다이어그램 보기
// 
//도구 - 도구 및 기능 가져오기 - 개별구성요소 - 클래스디자이너 - 설치

