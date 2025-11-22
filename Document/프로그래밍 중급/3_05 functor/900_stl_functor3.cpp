//문자열 집합을 정렬하기
//sort 함수에서 함수객체 사용하기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void main()
{
    vector<string> vs = { "STL","MFC","C/C++","pascal","Python","basic" };

    //sort의 기본 버전은 요소간의 비교를 위해 < 연산자, 즉 less 비교 함수 객체를 사용
    sort( vs.begin(), vs.end() );                        
    
    //비교가 필요할 때마다 함수 객체를 호출
    sort(vs.begin(), vs.end(), greater<string>());  

    for (auto e : vs) {
        cout << e << endl;
    }
}