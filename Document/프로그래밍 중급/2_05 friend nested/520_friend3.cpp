//일반 함수 뿐아니라 
//다른 클래스의 특정 멤버함수를 대상으로도 friend 선언 가능하다.

#include <iostream>
using namespace std;

class Point; //클래스 선언

class PointOP		//좌표 연산 클래스
{
private:
	int opcnt;
public:
	PointOP() : opcnt(0) {
	}
	~PointOP() {
		cout << "Operation times: " << opcnt << endl;
	}

	Point PointAdd(const Point&, const Point&);		//Point 사용
	Point PointSub(const Point&, const Point&);
};

class Point			//좌표 클래스
{
private:
	int x;
	int y;
public:
	Point(const int &xpos, const int &ypos) : x(xpos), y(ypos)
	{  }
	friend Point PointOP::PointAdd(const Point&, const Point&); //클래스의 특정 멤버함수를 대상으로도 friend 선언이 가능
	friend Point PointOP::PointSub(const Point&, const Point&);
	friend void ShowPointPos(const Point&);						//특정 함수를 대상으로도 friend 선언
};

Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2)
{
	opcnt++;			//private 멤버 접근
	return Point(pnt1.x + pnt2.x, pnt1.y + pnt2.y);
}

Point PointOP::PointSub(const Point& pnt1, const Point& pnt2)
{
	opcnt++;
	return Point(pnt1.x - pnt2.x, pnt1.y - pnt2.y);
}

int main(void)
{
	Point pos1(1, 2);
	Point pos2(2, 4);
	PointOP op;

	ShowPointPos(op.PointAdd(pos1, pos2));
	ShowPointPos(op.PointSub(pos2, pos1));
	return 0;
}

void ShowPointPos(const Point& pos)
{
	cout << "x: " << pos.x << ", ";
	cout << "y: " << pos.y << endl;
}