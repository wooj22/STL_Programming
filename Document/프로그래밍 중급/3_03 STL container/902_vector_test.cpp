//백터의 평균을 구하기

#include <iostream>
#include <string>
#include <vector>
using namespace std;

double solution(vector<int> arr) //백터 전달
{
    double answer = 0;
    for (int i = 0; i < arr.size(); i++)
        answer += arr[i];
    answer /= arr.size();
    return answer;
}

int main() 
{
    //백터의 평균을 구하는 함수를 작성하라

    vector<int> v = { 1,2,5,7,3 };

    cout << solution(v) << " ";
}


/*
// 백터 배열 ---------------------------------------------------------
//		vector로 5개 공간을 확보하고, 10으로 초기화하세요.

    vector<int> v;							//백터 범위를 5로 지정하고 정수 10으로 초기화
    v.assign(5, 10);                        //output : 10 10 10 10 10

// { 1, 2}, {3, 4} 배열을 vector로 선언하여 초기화하세요.

    vector<int> v[] = { { 1, 2}, {3, 4} };  //int형 백터의 배열 생성 (행은 가변이지만 열은 고정)

    vector<vector<int>> v;                  //2차원 백터 생성 (행과 열 모두 가변)

*/
