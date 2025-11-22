//STL 컨테이너 (STL Container) 사용하기
//STL 반복자 (STL iterator) 사용하기
//STL 알고리즘 (STL algorithm) 사용하기

//대표적인 컨테이너 //vector<T>
//      컨테이너, 데이타를 담아서 처리하는 방법 vector, list, map, set

#include <vector>
#include <iostream>
using namespace std;

void main()
{
    vector<int> v0;         //int형 백터 생성    //int 동적배열 - 추가,삭제

    v0.push_back(1);        //추가
    v0.push_back(2);        //추가
    v0.pop_back();          //삭제

    //벡터의 크기 
    cout << "벡터의 크기 : " << v0.size() << endl;

    //배열처럼 접근 가능
    cout << v0[0] << endl;


    //다양한 초기화 ---------------------------------------------

    vector<int> v1(3);              //int형 백터 생성 후 크기를 3로 할당 (모든 백터요소 0으로 초기화) 
    vector<int> v2(5, 2);           //int형 백터, size 5,  2로 초기화
    vector<int> v3 = { 1, 2, 3 };   //int형 백터 생성 후 1, 2, 3 으로 초기화
       
    //벡터 출력하기
    for (int i = 0; i < v3.size(); i++)
        cout << "  " << v3[i];              
    cout << endl;


    //대문자 A B C D  를 vector 컨테이너로 담아 보세요.----------


    //아래 벡터의 크기와 요소들을 출력해보세요. -----------------------

    vector<int> v = { 1, 2, 3, 4, 5  };

    cout << "벡터의 크기 : " << v.size() << endl;

    for (int i = 0; i < v.size(); i++)
        cout  << v[i] << " ";
    cout << endl;
}

