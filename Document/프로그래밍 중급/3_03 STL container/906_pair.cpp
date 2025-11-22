//pair 객체
//  두개의 데이타를 저장하는 객체
// 
//  pair<[type1], [type2]> p;    //사용할 데이터 타입 1, 2를 넣고 그 타입의 pair 클래스인 p 생성
//  p.first  : p의 첫번째 인자를 반환해 줍니다.
//  p.second : p의 두번째 인자를 반환해 줍니다.
//
//  make_pair(변수1, 변수2);     //변수1과 변수2가 들어간 pair를 만들어줍니다.
// 
//  operator로(== , != , <, >, <= , >= )가 정의되어 있어서, 사용이 가능하다.
//  sort 알고리즘에 의해 정렬이 가능하다.

#include<iostream>
#include<utility>
#include<string>
using namespace std;

void same(pair<int, string> a, pair<int, string> b) {
    if (a == b) {   cout << "true" << endl;    }
    else        {   cout << "false" << endl;    }
}
void comp(pair<int, string> a, pair<int, string> b) {
    if (a < b)  {   cout << "true" << endl;    }
    else        {   cout << "false" << endl;    }
}

int main(void) 
{
    pair<int, string> p1 = make_pair(1, "apple");
    pair<int, string> p2 = make_pair(3, "melon");
    pair<int, string> p3 = make_pair(1, "apple");

    cout << "p1.first : " << p1.first << endl;
    cout << "p1.second : " << p1.second << endl;
    cout << endl;

    cout << "p1 == p2 ? ";  same(p1, p2);
    cout << "p1 == p3 ? ";  same(p1, p3);
    cout << endl;

    cout << "p1 < p2 ? ";   comp(p1, p2);
    cout << "p1 < p3 ? ";   comp(p1, p3);

    return 0;
}


// pair 이용하여 vector에 순서쌍 원소 추가하기 ----------------------
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
    vector< pair<int, int> > v2;
    v2.push_back(make_pair(12, 3));

    cout << v2[0].first << ' ' << v2[0].second;
}

/*

#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(void)
{
    vector<pair<int, string> > v;

    v.push_back(pair<int, string>(3, "Dog"));
    v.push_back(pair<int, string>(1, "Tiger"));
    v.push_back(pair<int, string>(4, "black"));
    v.push_back(pair<int, string>(2, "banana"));
    v.push_back(pair<int, string>(2, "apple"));

    // out

    vector<pair<int, string> >::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << "[" << iter->first << "," << iter->second << "]" << endl;
    }
    cout << endl;

    //sort

    sort(v.begin(), v.end());                       

    for (iter = v.begin(); iter != v.end(); iter++) {
        cout << "[" << iter->first << "," << iter->second << "]" << endl;
    }

    return 0;
}
*/

