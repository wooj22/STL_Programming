//코드 해석 // const 함수

// const 함수
//		const형 오브젝트에서 이런 함수들을 부를 수 있게 됩니다!

//1. const 처리된 멤버 함수 안에서 역시 자신의 멤버 함수를 부르는 데 제한이 생깁니다.
//	 const 처리된 멤버 함수 안에서는 역시 const 처리된 멤버 함수만 부를 수 있습니다.

//2. 설령 내용 중에 멤버 변수값을 바꾸는 것이 없더라도, 
//	 const 처리하지 않으면, const형 오브젝트에서 부를 수 없습니다.

#include <iostream>
using namespace std;

class Coord {
private:
	int x, y;
public:
	Coord();
	Coord(int, int);
	void setX(int);
	void setY(int);
	int getX() const;
	int getY() const;
	void print() const;
};

Coord::Coord() :x(0), y(0) {}
Coord::Coord(int x1, int y1) :x(x1), y(y1) {}
void Coord::setX(int x1) { x = x1; }
void Coord::setY(int y1) { y = y1; }
int Coord::getX() const { return x; }
int Coord::getY() const { return y; }
void Coord::print() const { cout << "(" << x << ", " << y << ")" << endl; }

// 좌표를 더해 새로운 좌료를 리턴하는 함수
const Coord add(const Coord, const Coord);	 
// 함수 앞에 붙은 const는 함수의 리턴값을 상수화 시키겠다는 의미

int main() 
{
	Coord A(2, 3);
	Coord B(-1, 0);
	A.print();
	B.print();

	(add(A, B)).print();			//const Coord 객체이므로, const 함수 호출

	return 0;
}

const Coord add(const Coord P, const Coord Q) {
	int x1 = P.getX() + Q.getX();
	int y1 = P.getY() + Q.getY();
	Coord temp(x1, y1);
	return temp;
}
