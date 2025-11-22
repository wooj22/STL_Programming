// 템플릿이 아닌 함수나 클래스에 대한 프렌드

#include <iostream>
using namespace std;

template <typename T>
class Point
{
private:
	T xpos, ypos;
public:
	Point(T x = 0, T y = 0) : xpos(x), ypos(y)
	{  }
	void ShowPosition() const
	{
		cout << xpos << ", " << ypos << endl;
	}

	friend Point<int> operator+(const Point<int>&, const Point<int>&);
	friend ostream& operator<<(ostream& os, const Point<int>& pos);
};

Point<int> operator+(const Point<int>& pos1, const Point<int>& pos2)
{
	return Point<int>(pos1.xpos + pos2.xpos, pos1.ypos + pos2.ypos);
}

ostream& operator<<(ostream& os, const Point<int>& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

int main(void)
{
	Point<int> pos1(2, 4);
	Point<int> pos2(4, 8);
	Point<int> pos3 = pos1 + pos2;
	cout << pos1 << pos2 << pos3;

	//다른 자료형은???
	//Point<double> pos5(2.5, 4.5);
	//cout << pos5;

	return 0;
}

//클래스 템플릿안에 friend 함수를 선언하는 방법

//friend 함수를 일반 함수로 구현하고 구현부를 클래스 템플릿 내부에 포함
//friend 관계: 1 : 1

#include <iostream>
using namespace std;

template<typename T>
class Point
{
    T x, y;
public:
    Point(T a = { 0 }, T b = { 0 }) : x(a), y(b) {}

    friend ostream& operator<<(ostream& os, const Point<T>& p)
    {
        return os << p.x << ", " << p.y;
    }
};

int main()
{
    Point<int> p(1, 2);
    cout << p << endl;

    Point<double> p2(1.2, 2.3);
    cout << p2 << endl;
}

//friend 함수 선언시에 함수 자체를 템플릿 모양으로 선언
//friend 관계: N:N

#include <iostream>
using namespace std;

template<typename T>
class Point
{
    T x, y;
public:
    Point(T a = { 0 }, T b = { 0 }) : x(a), y(b) {}

    template<typename U>
    friend ostream& operator<<(ostream& os, const Point<U>& p);
};

template<typename T>
ostream& operator<<(ostream& os, const Point<T>& p)
{
    return os << p.x << ", " << p.y;
}


int main()
{
    Point<int> p(1, 2);
    cout << p << endl;

    Point<double> p2(1.2, 2.3);
    cout << p2 << endl;
}
