#include <iostream>
#include <cmath>

using namespace std;

int main() {

	cout << min(3, 4) << "\n";		// 3	
    cout << round(3.4) << "\n";		// 3 (반올림)
	cout << abs(-2) << "\n";		// x의 절대값 반환.
    cout << pow(3, 2) << endl;		// 3의 2승
    cout << sqrt(16) << "\n";		// 루트 4 (제곱근)
	cout << log(2) << "\n";			// 0.693147 (자연로그)

    {
        double x = 2.6;
        double y = -5.3;
        
        cout << "min(x, y) = " << min(x, y) << endl;        // -5.3        
        cout << "max(x, y) = " << max(x, y) << endl;        // 2.6        
        cout << "abs(x) = " << abs(x) << ", abs(y) = " << abs(y) << endl; // 2.6, 5.3        
        cout << "fabs(x) = " << fabs(x) << ", fabs(y) = " << fabs(y) << endl; // 2.6, 5.3        
        cout << "ceil(x) = " << ceil(x) << ", ceil(y) = " << ceil(y) << endl; // ceil 올림 // 3, -5        
        cout << "floor(x) = " << floor(x) << ", floor(y) = " << floor(y) << endl; // floor 내림 // 2, -6
    }
    {
        double x = 4;
        double y = 2;        
        cout << "pow(x, y) = " << pow(x, y) << endl;    // 16        
        cout << "exp(x) = " << exp(x) << endl;          // 54.5982        
        cout << "sqrt(x) = " << sqrt(x) << endl;        // 2
    }
    {
        double x = 10;        
        cout << "log(x) = " << log(x) << endl;          // 2.30259        
        cout << "log10(x) = " << log10(x) << endl;      // 1

        printf("log(2.71828)=%f\n", log(2.718281828));  // 밑이 e <- 자연로그
        printf("log10(10.0)=%f\n", log10(10.0));        // 밑이 10 <- 상용로그
        printf("log2(4.0)=%f\n", log2(4.0));            // 밑이 2 <- 로그
    }
	return 0;
}

/*

//수학 수치 정의

#define _USE_MATH_DEFINES
#include <cmath>

    double PI = M_PI;


#include <algorithm>

    max(𝑥, 𝑦);			//𝑥와 𝑦중에서 큰 값
    min(𝑥, 𝑦);

*/

/*
//수학관련 주요 함수를 알아봅시다.

ceil(x)			x의 가장 가까운 천장 정수 반환.
round(x)		x를 반올림한 숫자 반환.

pow(x, y)		x의 y승 반환.
sqrt(x)			x의 제곱근 반환.
cbrt(x)			x의 세제곱근 반환.

cos(x)			x의 코사인 반환.
cosh(x)			x의 쌍곡코사인 반환.
sin(x)			x의 사인 반환. (x는 라디안).
sinh(x)			double 값의 쌍곡사인 반환.
tan(x)			각도의 탄젠트 반환.
tanh(x)			double 값의 쌍곡탄젠트 반환.

acos(x)			x의 아크코사인 반환.
asin(x)			x의 아크사인 반환.
atan(x)			x의 아크탄젠트 반환.

exp(x)			E의 x승 반환.
expm1(x)		e의 x승 - 1 반환.
log(x)			x의 자연로그 반환.

fabs(x)			부동소수 x의 절대값 반환.
fdim(x, y)		x와 y의 양의 차이를 반환.
floor(x)		x의 가장 가까운 바닥 정수 반환.
hypot(x, y)		중간 오버플로 또는 언더플로 없이 sqrt(x2 + y2) 반환.
fma(x, y, z)	정밀도 손실없이 x* y + z 반환
fmax(x, y)		부동 x, y 중 최대값 반환.
fmin(x, y)		부동 x, y 중 최소값 반환.
fmod(x, y)		x / y의 부동 소수점 나머지 반환.

*/


//정수 절대값 구하는 함수
int m_abs(int n)
{
    if (n > 0)
        return n;
    else
        return n * (-1);
}

//실수 절대값 구하는 함수
double m_fabs(double n)
{
    if (n > 0)
        return n;
    else
        return n * (-1);
}

//거듭 제곱 함수
double m_pow(double n, double m)
{
    int nn = n;
    for (int i = 0; i < (m - 1); i++)
        n *= nn;
    return n;
}

//제곱근 함수
double m_sqrt(double n)
{
    double s = 0;
    double t = 0;

    s = n / 2;
    for (; s != t;)
    {
        t = s;
        s = ((n / t) + t) / 2;
    }
    return s;
}
