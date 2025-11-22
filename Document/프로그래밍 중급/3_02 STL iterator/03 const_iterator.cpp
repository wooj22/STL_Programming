//예시 const_iterator //auto 를 이용해서 간략하게 표현

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVector(const vector<int> & v)             //const
{   
    auto citer = v.begin();

    for(  ; citer != v.end(); citer++)
        cout << *citer <<"     ";
    cout << endl;
}

void main()
{
   vector<int>  v(8) ;   

   for (int i = 0; i < v.size(); i++)
        v[i] = i + 1 ;

   PrintVector( v );
}