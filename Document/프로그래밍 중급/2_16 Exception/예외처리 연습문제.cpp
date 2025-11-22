// Player 의 정보가 잘못된 경우(level 100 초과) 예외처리 해보자.
// 
// MyException 클래스를 생성하세요.
// 예외 발생한 경우 MyException 클래스를 사용해 Player 이름과 레벨 정보를 전달하세요.

#include <iostream>
using namespace std;

class Player {
public:
	string name = "";
	int level = 0;
};

int main(void)
{
	Player p1; p1.name = "player";
	p1.level = 101;

	return 0;
}

//-------------------------------------------------------------------

class Player {
public:
	string name = "";
	int level = 0;
};

class MyExcetion {
	string message = "";
	string name = "";
	int level = 0;
public:
	MyExcetion(string _msg, string _name, int _lv) :message(_msg), name(_name), level(_lv) { }
	virtual ~MyExcetion() { }
	void print() { cout << message << " " << name << " " << level << endl; }
};


int main(void)
{
	try {
		Player p1; p1.name = "player";
		p1.level = 101;
		if (p1.level > 100)
			throw MyExcetion("에러", p1.name, p1.level);

	}
	catch (MyExcetion ex) {
		ex.print();
	}

	return 0;
}