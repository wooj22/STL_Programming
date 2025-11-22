//순수 가상 함수의 가장 두드러진 특징이라면
// 
//	1. 어떤 순수 가상 함수를 물려받은 구체 클래스가 해당 순수 가상 함수를 다시 선언해야 한다.
//	2. 순수 가상 함수는 전형적으로 추상 클래스 안에서 정의를 갖지 않는다.
//
//따라서 순수 가상 함수를 선언하는 목적은
//		파생 클래스에서 함수의 인터페이스만을 물려주는 것이다.

//하지만, 순수 가상 함수에도 정의를 제공할 수 있다.

#include <iostream>
using namespace std;

class Shape {
public:
	virtual void draw() const = 0 { cout << "Shape" << endl; };
	virtual void error(const string& msg) {}
	int objectId() const {}
};

class Rect : public Shape {
public:
	virtual void draw() const { cout << "Rect" << endl;  }
	//virtual void error(const string& msg) {}
};

int main(void)
{
	Shape* ps = new Rect;
	ps->draw();
	ps->Shape::draw();

	return 0;
}