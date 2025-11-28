/*
	[ 인터페이스 (interface) ]

	인터페이스는 모두 순수 가상함수로 이루어진 클래스를 의미한다.
	추상클래스와 마찬가지로 객체 생성이 불가능하며
	인터페이스를 상속받는 클래스는 모든 함수를 오버라이드해야한다.
	멤버변수는 상관 없다.
	대문자 I를 뭍여 구분하는것이 관습이다.

	- 추상클래스 : 순수가상함수 하나 이상
	- 인터페이스 : 특수멤버함수를 제외하고, 전부 순수 가상 함수
*/

#include <iostream>
using namespace std;

// interface
class IState
{
protected:
	string state = "";
public:
	virtual ~IState() = default;
	virtual void OnEnter() = 0;
	virtual void Update() = 0;
	virtual void OnExit() = 0;
};

// interface 상속
class Idle : public IState
{
public:
	Idle() { state = "Idle"; }
	void OnEnter() override { cout << state << " Enter" << endl; }
	void Update() override { cout << state << " Udpate" << endl; }
	void OnExit() override { cout << state <<  "OnExit" << endl; }
};

// interface 상속
class Walk : public IState
{
public:
	Walk() { state = "Walk"; }
	void OnEnter() override { cout << state << " Enter" << endl; }
	void Update() override { cout << state << " Udpate" << endl; }
	void OnExit() override { cout << state << "OnExit" << endl; }
};

// interface 상속
class Die : public IState
{
public:
	Die() { state = "Die"; }
	void OnEnter() override { cout << state << " Enter" << endl; }
	void Update() override { cout << state << " Udpate" << endl; }
	void OnExit() override { cout << state << "OnExit" << endl; }
};

// 인터페이스를 받아서 처리
void DoExit(IState* istate)
{
	istate->OnExit();
}

int main()
{
	IState* idle = new Idle();
	idle->OnEnter();
	for(int i=0;i<10;i++)
		idle->Update();

	IState* walk = new Walk();
	IState* die = new Die();
	DoExit(idle);
	DoExit(walk);
	DoExit(die);
	
	delete idle;
	delete walk;
	delete die;
}