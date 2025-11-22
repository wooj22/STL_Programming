// 백터 정렬하기

#include <vector>
#include <algorithm>        // sort()
#include <functional>       // greater<int>()
#include <iostream>
using namespace std;

void main()
{
    vector<int>  v(8);
    vector<int>::iterator start, end, iter;
    for (int i = 0; i < v.size(); i++)    v[i] = i + 1;

    start = v.begin();
    end = v.end();

    sort(start, end);                       //오름차순 정렬

    for (iter = v.begin(); iter != v.end(); iter++)
        cout << "   " << *iter;
    cout << "\n";

    sort(start, end, greater<int>());       //내림차순 정렬

    for (iter = v.begin(); iter != v.end(); iter++)
        cout << "   " << *iter;
    cout << "\n";
}


// 아래 아이템을 목록에 추가하고, 내림차순으로 출력하라.
// "단검", level 1
// "장검", level 2
// "갑옷", level 5
// "반지", level 3

// 아이템 클래스 작성, vector 저장, 정렬 및 출력
