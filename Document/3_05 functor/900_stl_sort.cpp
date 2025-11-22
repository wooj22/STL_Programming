// 연습

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(int a)
{
    printf("%d\n", a);
}

void main()
{   
    int ar[] = { 2,8,5,1,9 };   

    //배열을 벡터 선언하여 소트 해보세요 ---------------
    
    vector<int> vi( &ar[0], ar + sizeof(ar)/sizeof(ar[0]) );

    // sort
    sort(vi.begin(), vi.end());
   
    // 출력 하기
    for (auto const& element : vi) std::cout << element << ' ';


    // for_each 사용하여 출력하여 보세요. --------------

    // 기능 수행
    for_each(vi.begin(), vi.end(), print);      //함수포인터


    //함수객체로 바꿔보세요.


    // 배열의 맴버에 대하여 제곱을 출력하세요 -----------

}