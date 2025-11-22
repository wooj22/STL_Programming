// 객체를 정렬하는 방법
//      연산자 오버로드, 함수 객체 사용하기

#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

class CObject
{
public:
    int  x;
    int  y;
    CObject(int a, int b) :x(a), y(b) {}

    virtual bool  operator < (const CObject& rhs) const {
        return (y < rhs.y);
    }
    virtual bool  operator == (const CObject& rhs) const {
        return (y == rhs.y);
    }

    /* Operator overloading(input, output) */
    friend istream& operator >> (istream&, CObject&); 
    friend ostream& operator << (ostream&, const CObject&);
};

istream& operator >> (istream& in, CObject& a) {
    in >> a.x;
    in >> a.y;
    return in;
}
ostream& operator << (ostream& out, const CObject& a) {
    out << a.x << " " << a.y;
    return out;
}

struct ListSort
{
    // operator() 를 사용해서 비교 함수를 재정의 해주시면 됩니다.
    bool operator() (const CObject& pObject1, const CObject& pObject2) const
    {
        return (pObject1.y < pObject2.y);
    }

    //bool operator() (const CObject* pObject1, const CObject* pObject2) const
    //{
    //     return (pObject1->y < pObject2->y);
    //}
};

int main()
{
    CObject obj1(1, 3);
    CObject obj2(2, 2);
    CObject obj3(3, 1);
    list<CObject> stlList = { obj1, obj2, obj3 };
        
    stlList.sort();                         //operator <

    //stlList.sort(ListSort());             //비교 함수전달

    for (auto it = stlList.begin(); it != stlList.end(); it++)
    {
        cout << *it << endl;
    }
}
