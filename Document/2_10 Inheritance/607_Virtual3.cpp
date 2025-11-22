//연습) 상속 다형성 활용하기 //목록 관리
// 
//Hero, Enemy, Boss 등을 관리하는 배열을 만들기.
// 
//		공통 관리를 위한 부모 클래스 선언, 
//		부모 클래스의 공통 함수를 virtual 로 가상화, 부모클래스로 배열 선언.

#include <iostream>
using namespace std;

class Player
{
public:
	char	name[25];
	int		movespeed = 0;
	virtual void Move() { cout << "Player Move" << endl; }  //가상함수
};

class Hero : public Player
{
public:
	void Move() { cout << "Hero Move" << endl; }
};

class Enemy : public Player
{
public:
	 void Move() { cout << "Enemy Move" << endl; }
};

int main()
{
	Player* player[2] = { new Hero(), new Enemy() };   // 부모클래스로 모두 관리 가능 ***

	for (int i = 0; i < 2; i++) {
		player[i]->Move();
	}

	delete player[0]; delete player[1];
}