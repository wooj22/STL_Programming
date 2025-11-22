//그 밖의 컨테이너 //list 예제

#include <list>
#include <iostream>
using namespace std;
 
void main()
{
    list<int> li;
    for (int i = 0; i < 8; i++)
        li.push_back(i + 1);

    li[0] = 10;                      //error // 배열처럼 임의접근 가능하지 않음 ***

    list<int>::iterator iter;        //같은 방식의 이터레이터 사용

    for(iter = li.begin(); iter != li.end(); iter++)
        cout << *iter <<"    ";
    cout << endl;

}