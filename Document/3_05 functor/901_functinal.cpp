// std::function 
// 
//		Callable 들을 '객체의 형태'로 보관할 수 있는 클래스
//		함수(Callable)를 매개변수로 전달 받거나 리턴할 때, 보관할 때 편리
// 
//		#include <functional> 사용

// std::function 선언하기
/*
    function<함수형식> 객체명 = 함수;

    // 함수형식 --->  반환형(입력형식)

    예) bool foo1(int a) { return true; }		// 함수형식은 bool(int)
    예) void foo2(int a, int b) { }				// 함수형식은 void(int,int)
    예) string foo3(float a, double b) { }		// 함수형식은 string(float,double)
*/

#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>
using namespace std;

bool foo1(int a) { return a % 2 == 0; }

void foo2(int a, int b) { cout << a + b << endl; }

string foo3(float a, double b) { return to_string(a + b); }

int main()
{
    function< bool(int) > f1 = foo1;
    f1(1);
    f1(2);

    //위 함수 foo2, foo3 를 function 으로 선언해 보세요


    //auto
    auto f2 = foo1;     //형식은?
}
