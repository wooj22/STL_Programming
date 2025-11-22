//연습) Monster클래스, Monster를 상속한 Boss 클래스를 만들고, 100개의 배열로 관리하는 예제

//상속 클래스의 생성자 호출
//		파생 호출 -> 기초 호출 -> 기초 실행 -> 파생 실행 ( 즉, 기본클래스가 먼저 생성된다. )
//		생성자는 호출과 실행이 분리된다. 각 생성자에선 객체 자신의 초기화만 해야한다.
// 
//		기초 클래스의 멤버 대상의 동적 할당은 기초 클래스의 생성자를 통해서, 
//		소멸 역시 기초 클래스의 소멸자를 통해서

#include <iostream>
using namespace std;

class Monster
{
protected:
	int index;
	int level = 0;
public:
	Monster(int a) : index(a) { cout << "Monster()" << endl; }
	virtual void SetLevel(int lv) { level = lv; }
	virtual void ShowLevel() { cout << level << endl; }
	virtual void Move() { cout << "Monster() Move" << endl; }
};

class Boss : public Monster
{
public:
	Boss(int a) : Monster(a), index(a) { cout << "Boss()" << endl; }
	virtual void SetLevel(int lv) { level = lv; }
	virtual void ShowLevel() { cout << level << endl; }
	virtual void Move() { cout << "Boss() Move" << endl; }
};

int main(void)
{
	//---------------------------------------------------- //몬스터 관리자
	const int MONSTER_MAX = 100;
	Monster* arrlist[MONSTER_MAX];							//가상화를 위해 포인터 배열 선언

	for (size_t i = 0; i < MONSTER_MAX; i++) { arrlist[i] = nullptr; }

	//---------------------------------------------------- //몬스터 생성
	Monster* m1 = new Monster(1);	arrlist[0] = m1;
	Monster* m2 = new Monster(2);	arrlist[1] = m2;
	Monster* m3 = new Boss(3);		arrlist[2] = m3;

	//---------------------------------------------------- //특정 몬스터 레벨업
	//m2->SetLevel(1);	
	//---------------------------------------------------- //몬스터 정보 출력
	for (size_t i = 0; i < MONSTER_MAX; i++)
	{
		if (arrlist[i] != nullptr)
		{
			arrlist[i]->Move();
		}
	}

	//Boss *boss = (Boss *)m3; delete boss;				//가상 소멸자 필요

	return 0;
};

//메니저 클래스 - 주로 객체를 생성, 삭제, 검색 등의 관리를 하는 객체 
