// 연산자 오버로드 연습 // ++ 전위 증가, 후위 증가, << 출력 연산자 정의하세요.

#include <iostream>
using namespace std;

class Point
{
private:
    double m_x, m_y;
public:
    Point(double x = 0.0, double y = 0.0) 
        : m_x(x), m_y(y) {}
/*
    // 전위 증가
    Point& operator++()
    {
        m_x += 1;
        m_y += 1;    
        return *this;
    }

    // 후위 증가
    Point operator++(int)
    {
        Point temp(m_x, m_y);
        m_x += 1;
        m_y += 1;
        return temp;
    }

    // 출력 연산자 오버로딩
    friend ostream& operator << (ostream& out, const Point& point)
    {
        out << point.m_x << " " << point.m_y;
        return out;
    }
*/
};

int main()
{
    Point p1(1.0, 2.0);

    cout << ++p1 << endl; // 바로 증가
    cout << p1++ << endl; // 다음 행에서 증가    
    cout << p1 << endl;
}
