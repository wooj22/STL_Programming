//잘못된 erase 사용

#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, float> coll;
    map<int, float>::iterator pos;

    coll[0] = 1.0f;
    coll[1] = 1.2f;
    coll[2] = 2.0f;
    coll[3] = 3.0f;

    float value = 2.0;

    for (pos = coll.begin(); pos != coll.end(); pos++) {
        if (pos->second == value) {
            coll.erase(pos);            // 런타임 에러  // pos 문제
        }
    }

    //for (pos = coll.begin(); pos != coll.end();) {
    //    if (pos->second == value) {
    //        coll.erase(pos++);  // erase 호출 전 미리 반복자를 내부적으로 복사하고 증가
    //    }
    //    else {
    //        ++pos;
    //    }
    //}

    for (auto e : coll) {
        cout << e.second << endl;
    }
}
