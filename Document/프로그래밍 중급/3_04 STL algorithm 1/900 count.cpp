//algorithm 
//      다양하게 제공되는 함수들 
//      컨테이너가 제공하는 맴버함수와 전역으로 제공되는 알고리즘 함수를 구분하라.
//      이터레이터를 이용해 대상 전달.

 
// count        갯수                  (시작위치, 끝위치 )
// count_if     특정 조건에 맞는 갯수  (시작위치, 끝위치, bool 리턴 함수 )

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool is_odd(int num)    //맴버 하나를 받아 true 리턴하는 것을 처리한다.
{
    return num % 2 == 1;
}

void main()
{
    vector<int>  v(8) = { 3,2,7,9,4,1,3 }

    int total;

    //3의 개수를 구하라

    total = count(v.begin(), v.end(), 3);               // std::count
    cout << " 3의 개수는 " << total << endl;


    // vector v 에서 홀수의 개수는 ???

    total = count_if(v.begin(), v.end(), is_odd);       // std::count_if  //함수 전달
    cout << " 홀수의 개수는 " << total << endl;
}


//C++ 표준 라이브러리의 알고리즘(algorithm) 라이브러리 -------------------------------------

//알고리즘에 정의되어 있는 여러가지 함수들
// 
//두 개의 형태를 취한다.
// 
//  template <typename Iter>
//  void Func(Iter begin, Iter end);                //범위 시작, 범위 끝
// 
//  template <typename Iter, typename Pred>
//  void Func(Iter begin, Iter end, Pred pred)      //범위 시작, 범위 끝, 서술자
//
//  이러한 '특정한 조건'을 서술자(Predicate) 이라고 부르며 
//  Pred 에는 보통 bool 을 리턴하는 함수객체(Functor) 를 전달하게 된다.    //함수객체
//  함수 객체를 매우 편리하게 만들어주는 람다 함수를 사용할 수도 있다.       //람다

