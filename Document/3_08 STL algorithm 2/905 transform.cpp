//원소 수정하기 (transform)
//      컨테이너 전체 혹은 일부를 순회하면서 값들을 수정하는 작업
//      transform ( 시작 반복자, 끝 반복자, 결과를 저장할 컨테이너의 시작 반복자, Pred )
//      Pred 는 요소 하나를 받아 리턴하는 함수

#include <iterator>// ostream_iterator
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int Increment(int n)
{
    return n+1;
}

void main()
{
   vector<int>  v(8) ;  
  
   for (int i = 0; i < v.size(); i++)
       v[i] = i + 1 ;

   ostream_iterator<int>  out_iter( cout, " : " );
   copy(v.begin(), v.end(), out_iter);   cout <<endl;

   //transform ( first, last, dest, Func )
   //first부터 last 전까지 범위의 원소들을 Func를 수행하고, 그 결과를 dest 부터 차례로 저장한다

   transform(v.begin(),v.end(), v.begin(), Increment);  

   //cout << "**********  변 경 후 ********** "<< endl;
   copy(v.begin(), v.end(), out_iter);   cout <<endl;
}


