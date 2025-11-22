//set - key만 저장하는 균형 이진 트리
//  1. 크기가 가변적이다.
//  2. 기본적으로 하나의 데이터를 정렬해야 할 때 사용한다. // 셋의 중요한 특징, 중복된 원소들이 없다.
//  3. key가 있는지 없는지 알아야 할 때 
//  4. 많은 자료를 저장하면서 동시에 빠른 검색을 원할 때

#include <set>
#include <string>
#include <iostream>
using namespace std;

void main()
{
    set<int> intSet;              //set 예제
    set<int>::iterator itr;

    intSet.insert(90); //insert
    intSet.insert(95);
    intSet.insert(100);
    intSet.insert(60);
    intSet.insert(60);
    intSet.insert(95);
    intSet.insert(85);

    for (itr = intSet.begin(); itr != intSet.end(); ++itr)  
        cout << *itr << "  ";                             
    cout << endl;                                          // sort 되어 있음 ***  

    cout << "총 개수 : " << intSet.size() << endl;         // 중복 없음  ***


    //70을 삭제 후, 모든 요소 출력하라    // find, erase
    
    set<int>::iterator EraseIter = intSet.find(70);
    if (EraseIter != intSet.end()) {
        intSet.erase(EraseIter);        //erase
    }
    //for (itr = intSet.begin(); itr != intSet.end(); ++itr) { cout << *itr << "  "; }
    //cout << endl;

    
    //95를 검색 하여, 70로 변경한 후 모든 요소 출력하라 ---------------
    
    set<int>::iterator FindIter = intSet.find(95);
    if (FindIter != intSet.end())
    {
        //*FindIter = 70;          //error ***

        intSet.erase(FindIter);
        intSet.insert(70);
    }
    //for (itr = intSet.begin(); itr != intSet.end(); ++itr) { cout << *itr << "  "; }
    //cout << endl;

}