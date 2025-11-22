// find_if 
//      일정한 조건애 맞는 데이타 찾기
// 
//      find_if(first, last, pred)
//      값을 찾는다면, 해당 값의 위치를 반환하고, 값을 못찾는다면 last의 위치를 반환한다.
//      pred 가 탐색 조건을 지정 ( bool 리턴 함수 )

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool Greater5(int n)        //predicate
{
    return n > 5;
}

void main()
{
    vector<int>  v = { 1,2,3,4,5,6,7,8 };  
    vector<int>::iterator iter;

    // 5 보다 큰 요소를 찾아라

    iter = find_if(v.begin(), v.end(), Greater5);    //find_if  //함수 전달

    if( iter != v.end() )
        cout << " 5보다 큰 첫번째 값을 찾았습니다 : " << *iter << endl;
    else
        cout << " 찾는 값이 없습니다." << endl;

}