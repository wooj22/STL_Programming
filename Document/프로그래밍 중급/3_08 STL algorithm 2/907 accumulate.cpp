// accumulate
// 
//      특정 구간에 있는 원소들을 특정 방식에 맞게 쌓아서 리턴해주는 함수.     
//      지정한 구간에 속한 값들을 모든 더한 값을 계산할때 활용.
//      기본적으로 더하기 연산만 하지만, 조건자를 사용하면 더하기 이외의 연산도 할 수 있다.
// 
//      accumulate( start, last , 초기값 )
//      accumulate( start, last , 초기값, OP )

#include <numeric>          //
#include <vector>
#include <iostream>
using namespace std;

void main()
{
    vector<int>  v(10);

    for (int i = 0; i < v.size(); i++)
        v[i] = i + 1;

    cout << accumulate(v.begin(), v.end(), 0) << endl;

    cout << accumulate(v.begin(), v.end(), 100) << endl;    //100은 초기값


    // 합을 구하라. // 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10
    std::vector<int> v2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        
    int sum = std::accumulate(v2.begin(), v2.end(), 0);


    //주의해야 할 점은 
    //  범위를 초과하는 값을 더할 때 초기값을 잘 설정해줘야 한다
    //  오버플로우가 발생
    //  accumulate의 반환값이 initial value의 타입을 따라가기 때문

    {
        vector<int> v = { 1'000'000'000, 2'000'000'000 };
        long long sum = accumulate(v.begin(), v.end(), 0);          //int
        cout << sum << '\n';	//출력: -1294967296
    }

    {
        vector<int> v = { 1'000'000'000, 2'000'000'000 };
        long long sum = accumulate(v.begin(), v.end(), 0LL);        //0LL
        cout << sum << '\n';	//출력: 3'000'000'000
    }
}


