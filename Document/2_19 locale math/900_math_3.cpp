// math

#define _USE_MATH_DEFINES

#define DEGREE_TO_RADIAN(degree) ((PI/180)*(degree))
#define RADIAN_TO_DEGREE(radian) ((180/PI)*(radian))

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

constexpr auto PI = M_PI;			//_USE_MATH_DEFINES

int main()
{
	cout << abs(-2) << endl;		//절대값
	cout << round(6.5) << endl;		//반올림

	cout << pow(3, 2) << endl;
	cout << sqrt(2) << endl;
	cout << log(2.718281828) << endl;
	cout << log10(100) << endl;

	//삼각함수
	cout << sin(90 * (PI / 180)) << endl;
	cout << cos(DEGREE_TO_RADIAN(90)) << endl;

	//algorithm
	max(4, 9);

	return 0;
}
/*
// 호도법에 의한 각도의 단위 -----------------------------------

		1 degree = (2π/360) radian
		radian = degree * (π/180)
		degree = radian * (180/π)

 #define DEGREE_TO_RADIAN(degree) ((PI/180)*(degree))
 #define RADIAN_TO_DEGREE(radian) ((180/PI)*(radian))

*/

/*
//수학 수치 정의 -----------------------------------------------

	#define _USE_MATH_DEFINES
	#include <cmath>

	double PI = M_PI;
*/

/*

sin(x)   	사인					라디안을 받아 비율을 리턴한다. sin(rad) = a/h
cos(x) 		코사인				라디안을 받아 비율을 리턴한다. cos(rad) = b/h
tan(x) 		탄젠트				라디안을 받아 비율을 리턴한다. tan(rad) = a/b
asin(x)   	어사인				비율을 받아 라디안을 리턴한다. asin(a/h) = rad
acos(x)		아크코사인
atan(x)		아크탄젠트

exp(x)  	e의 x승 				exp(2.0) = e^2
log(x) 		자연로그: logex 		log(2.0) =  loge^2
log10(x) 	10진 로그: log10x	log10(2.0) = log10^2
sqrt(x) 	루트 x 				sqrt(2.0) = √2
abs(x) 		정수 x의 절대값 		abs(-2) = |-2| = 2
fabs(x)  	실수 x의 절대값 		fabs(-3.2) = |-3.2| = 3.2
pow(x, y) 	x의 y승 				pow(3,2) =3^2

ceil(x) 	소수올림: 2.5 =>3 	ceil(3.2) = [3.2] + 1 = 4
floor(x) 	소수내림: 2.5 =>2	floor(3.2) = [3.2] = 3
round(x)	반올림한 값

max(𝑥, 𝑦)	𝑥와 𝑦중에서 큰 값		//#include <algorithm>
min(𝑥, 𝑦)

*/

//세 점이 주어졌을 때 각도 구하기
//두 직선이 주어졌을 때 그 사이의 각도를 구하는 것 //벡터

/*
struct poly {
   lld x, y;
};

#define M_PI 3.14159

double angle(poly& a, poly& b, poly& c) {
	double aa, bb, cc;
	double ang, temp;

	aa = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
	bb = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
	cc = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));

	temp = (pow(bb, 2) + pow(cc, 2) - pow(aa, 2)) / (2 * bb * cc);
	ang = acos(temp);
	ang = ang * (180 / M_PI);

	return ang;
}
*/