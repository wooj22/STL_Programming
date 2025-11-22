// accumulate
//      지정한 구간에 속한 값들을 모든 더한 값을 계산한다. 
//      기본적으로 더하기 연산만 하지만 조건자를 사용하면 더하기 이외의 연산도 할 수 있다.

#include <iostream>
#include <vector>
#include <numeric>  
#include <string>
#include <functional>
using namespace std;

int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // 합을 구하라. // 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10 --------------------
    int sum = std::accumulate(v.begin(), v.end(), 0);
    cout << sum << endl;

    //long long sum = accumulate(v.begin(), v.end(), 0LL);
    //long long 타입을 쓸 생각이라면 initial value에 0 대신 0LL을 넣어줘야 합니다.


    // 곱을 구하라  // 1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10 --------------------
    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
    cout << product << endl;


    // 1-2-3-4-5-6-7-8-9-10  처럼 구현하기 ---------------------------------------
    auto dash_fold = [](std::string a, int b) {
        return std::move(a) + '-' + std::to_string(b);
    };    
    std::string s = std::accumulate(std::next(v.begin()), v.end(),
        std::to_string(v[0]), // start with first element
        dash_fold);

    // 10-9-8-7-6-5-4-3-2-1  // Right fold using reverse iterators --------------
    std::string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
        std::to_string(v.back()), // start with last element
        dash_fold);

    std::cout  
        << "dash-separated string: " << s << '\n'
        << "dash-separated string (right-folded): " << rs << '\n';
}