//reverse() : 객체 거꾸로 만들기

#include <iterator> // ostream_iterator
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void main()
{
   vector<int> v(8); 

    for (int i= 0; i < v.size(); i++)
        v[i] = i + 1 ;

   ostream_iterator<int>  out_iter( cout, "  :  " );
   copy(v.begin(), v.end(), out_iter);   cout <<endl;

   reverse( v.begin(), v.end() );                            //reverse

   copy(v.begin(), v.end(), out_iter);   cout <<endl;

    //--------------------------------------------------

   std::vector<int> v{ 1, 2, 3 };
   std::reverse(std::begin(v), std::end(v));
   for (auto e : v) std::cout << e;
   std::cout << '\n';

   int a[] = { 4, 5, 6, 7 };                                //배열 뒤집기
   std::reverse(std::begin(a), std::end(a));
   for (auto e : a) std::cout << e;

}

/*
    template <class BidirIt>
    void reverse(BidirIt first, BidirIt last) {
      while ((first != last) && (first != --last)) {
        std::iter_swap(first++, last);
      }
    }
*/
