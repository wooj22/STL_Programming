//스트림 반복자(stream iterator) ---------------------------- 

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void main( )
{

    vector<int> vc = { 1, 2, 3, 4, 5 };

    copy(vc.begin(), vc.end(), ostream_iterator<int>(cout));            //copy 함수
    cout << endl;

    copy(vc.begin(), vc.end(), ostream_iterator<int>(cout, " "));       //공백 출력 ***
    cout << endl;
}

/*
    //list

    list<int> ls = { 10, 20, 30 };
    list<int>::iterator iter;

    // 상수 반복자 ------------------------------------------------

    list<int>::const_iterator citer;

    iter = ls.begin();
    *iter = 100;
    citer = ls.end();
    // *citer = 300;                        // 상수 반복자이므로 값의 변경은 불가능함.
    for (citer = ls.begin(); citer != ls.end(); citer++) {
        cout << *citer << " ";
    }

    // 역방향 반복자(reverse iterator) --------------------------
    list<int> ls = {10, 20, 30};
    copy(ls.rbegin(), ls.rend(), ostream_iterator<int>(cout, " ")); //ostream_iterator


    // 삽입 반복자(insert iterator) -----------------------------
    list<int> ls = {10};
    ls.push_back(20);           // back_insert_iterator를 사용함.
    ls.push_front(30);          // front_insert_iterator를 사용함.
    copy(ls.begin(), ls.end(), ostream_iterator<int>(cout, " "));   //ostream_iterator

*/

//1. 입력 반복자(input iterator)
//2. 출력 반복자(output iterator)
//3. 순방향 반복자(forward iterator)
//4. 양방향 반복자(bidirectional iterator)
//5. 임의 접근 반복자(random access iterator)
//
//반복자의 기능                 입력  출력  순방향 양방향 임의접근
//접근(->)                      o     X     o     o     o
//읽기(*)                       o     X     o     o     o
//쓰기(*)                       X     o     o     o     o
//증가 연산자(++)                o     o     o     o     o
//감소 연산자(--)                X     X     X     o     o
//첨자 연산자([])                X     X     X     X     o
//산술 연산자(+, -)              X     X     X     X     o
//관계 연산자(<, <= , >, >= )    X     X     X     X     o
//대입 연산자(+=, -=)            X     X     X     X     o
