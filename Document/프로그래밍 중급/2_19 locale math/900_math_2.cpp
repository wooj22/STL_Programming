// math 삼각함수 라디안

#define DEGREE_TO_RADIAN(degree) ((PI/180)*(degree))
#define RADIAN_TO_DEGREE(radian) ((180/PI)*(radian))

#include <iostream>
#include <cmath>
using namespace std;

const double pi = 3.14159265358979;	

//변하지 않는 표현식?(const expression) 
//		컴파일 중에 값 평가를 하여 실제 런타임 상에서 계산을 수행하지 않는 것이 가능
constexpr auto PI = 3.14159265358979;

int main()
{
	//삼각함수 ---------------------------------------------

	cout << sin( 90 * (PI / 180) ) << endl;		//높이 y
	cout << cos( 0 * (PI / 180) ) << endl;		//거리 x
	cout << tan( 45 * (PI / 180) ) << endl;		//기울기  y/x

	// 호도법에 의한 각도의 단위 ----------------------------
	 
	// 1 degree = (2π/360) radian
	// radian = degree * (π/180)
	// degree = radian * (180/π)

	double rad = atan(1);
	cout << RADIAN_TO_DEGREE(rad) << endl;

	return 0;
}

/*
sin(x)   	사인			라디안을 받아 비율을 리턴한다. sin(rad) = a/h
cos(x) 		코사인		라디안을 받아 비율을 리턴한다. cos(rad) = b/h
tan(x) 		탄젠트		라디안을 받아 비율을 리턴한다. tan(rad) = a/b

asin(x)   	어사인		비율을 받아 라디안을 리턴한다. asin(a/h) = rad
acos(x)		아크코사인
atan(x)		아크탄젠트
*/
