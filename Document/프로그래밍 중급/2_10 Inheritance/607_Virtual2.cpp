//연습) virtual 예시

#include<iostream> 
using namespace std;

class Player 
{
public:
    virtual void Move() { cout << "Player"<< endl; }   //virtual
};

class Monster : public Player 
{
public:
    void Move() { cout << "Monster" << endl; }
};

class Boss : public Player
{
public:
    void Move() { cout << "Boss" << endl; }
};

void main()     //virtual 일 때와 아닐 때 비교하세요.
{
    Monster m;
    Boss b;

    Player* list[2] = { &m,  &b };  //목록으로 관리

    for (int i = 0; i < 2; i++) {
        list[i]->Move();
    }
}

