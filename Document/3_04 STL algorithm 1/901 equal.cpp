// equal
//      bool equal ( first1, last1, first2 );
//      first1, last1 : 비교할 첫 번째 element의 범위를 나타냄 
//      first2, last2 : 비교할 두 번째 element의 범위를 나타냄 
//      last2 는 전달하지 않음 
//      (주의) iterator가 end()를 넘어가면 런타임 에러, 빈 배열에 사용해도 런타임 에러
// 
//      first1, first2 iterator를 계속 ++ 시켜서 해당 element들이 모두 같은지 체크합니다. 
//      중간에 하나라도 다르다면 false를 반환합니다.

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void PrintElement(int n) // 요소의 값을 출력하는 함수 정의 
{
    cout << n << " ";
}

void main()
{
    vector<int> v1 = { 3,2,7,9,4,1,3 };
    vector<int> v2 = { 1,3,7,9,4,2,3 };

    cout << "전체 구간" << endl;
    for_each(v1.begin(), v1.end(), PrintElement); cout << endl;      //출력
    for_each(v2.begin(), v2.end(), PrintElement); cout << endl;
    cout << endl;

    //cout << "요소들이 일치하는지 조사할 구간" << endl;
    //for_each(v1.begin() + 2, v1.begin() + 5, PrintElement); cout << endl;
    //for_each(v2.begin() + 2, v2.begin() + 5, PrintElement); cout << endl;
    //cout << endl;

    //equal ------------------------------------------------

    if ( equal( v1.begin() + 2, v1.begin() + 5, v2.begin() + 2 ) == true)
        cout << "두 벡터의 일부 구간이 일치함" << endl;
    else
        cout << "두 벡터의 일부 구간이 일치하지 않음" << endl;
}
