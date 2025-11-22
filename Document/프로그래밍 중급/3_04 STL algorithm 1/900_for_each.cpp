//algorithm 
//      다양하게 제공되는 함수들 
//      컨테이너가 제공하는 '맴버함수'와 '전역함수'로 제공되는 알고리즘 함수를 구분하라.

// for_each (_InIt _First, _InIt _Last, _Fn _Func)
//      (시작위치, 끝위치, 전달할 함수 )
//      전달 함수가 맴버 하나를 받아 처리한다.
//      각 요소에 대하여 특정 기능을 수행. (함수,함수객체, 람다)

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void PrintElement(int n)    // 요소의 값을 출력하는 함수 정의 
{
    cout << n << "    ";
}

void main()
{
    vector<int>  v = { 1,2,3,4,5,6,7,8 };

    //일반 for()문을 사용한 요소 접근

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << "  ";
    cout << endl;

    //for_each() 함수 사용한 요소 접근 ------------------

    for_each(v.begin(), v.end(), PrintElement);     //std::for_each
    cout << endl;


    //벡터 v 에서 짝수만 출력하세요.    for_each 


}