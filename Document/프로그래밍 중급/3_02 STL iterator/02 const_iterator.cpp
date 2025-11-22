//예시 const_iterator

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(const vector<int>& v);

void main()
{
    vector<int>  v(8);

    for (int i = 0; i < v.size(); i++)
        v[i] = i + 1;

    PrintVector(v);         //작성해 보세요.
}


void PrintVector(const vector<int>& v)             //const 로 받은 경우
{
    //vector<int>::iterator iter = v.begin();       //컴파일 에러
    vector<int>::const_iterator citer = v.begin();

    for (; citer != v.end(); citer++)
        cout << *citer << "     ";
    cout << endl;
}