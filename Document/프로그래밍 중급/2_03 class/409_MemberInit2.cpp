//객체 초기화 방식 --------------------------------------------------

#include <iostream> 
using namespace std;

class Player
{
    string nickname = "";                               //1  =
    int level = 0;
public:
    Player() { }
    Player(int l): level(l) { }
    Player(string n, int l) : nickname(n), level(l)     //2  : 
    {
        nickname = n, level = l;                        //3   
    }

    ~Player() { }   // 소멸자

    void Prn() {
        cout << nickname << " " << level;
    }
};

void main()
{
    int num = 5;            //초기화 방식
    int num(5);         
    int num{ 5 };

    Player p;               //객체 초기화 방식
    Player p{};
    Player p(1);
    Player p{ 1 };
    Player p("player",1);
    Player p{ "player",1 };
}

//초기화 리스트를 사용해야하는 경우 ----------------------------------------

//선언과 동시에 초기화해야 하는 변수 
//
//      참조자 멤버 변수(int& a)
//      비 정적 상수 변수(const int a)
//      기본 생성자가 없는 사용자 정의타입의 멤버 변수
// 
//이 땐 class 내에서 기본적으로 초기화 시켜줄 수 없다.
//그러므로 꼭 선언만 하고, 초기화 리스트에서 초기화를 시켜줘야 한다. ***

