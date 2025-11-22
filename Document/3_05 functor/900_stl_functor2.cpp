//이미 정의되어 있는 다양한 함수 객체(Function Object)

#include <iostream>
#include <functional>           //#include
using namespace std;

int main() 
{
    // 비교
    cout << less<int>()(10, 20) << endl;
    cout << less<int>()(20, 10) << endl;
    cout << greater<int>()(10, 20) << endl;
    cout << greater<int>()(20, 10) << endl;
    cout << endl;

    // 계산
    cout << plus<int>()(10, 20) << endl;
    cout << plus<int>()(20, 10) << endl;
    cout << minus<int>()(10, 20) << endl;
    cout << minus<int>()(20, 10) << endl;
    cout << endl;

    // 20 % 7 계산 결과를 출력하라.
    cout << modulus<int>()(20, 7) << endl;

    // (-7) 부호를 반대로 출력하라.
    cout << negate<int>()(-7) << endl;

    // 20 == 7 인지 출력하라.
    cout << equal_to<int>()(20, 7) << endl;

    return 0;
}

//함수 객체          연산
//minus             두 인수의 차를 계산한다.
//multiplies        두 인수의 곱을 계산한다.    
//divides           두 인수를 나눈 후 몫을 리턴한다.
//modulus           두 인수를 나눈 후 나머지를 리턴한다.
//negate            인수 하나를 전달받아 부호를 반대로 만든다.
//equal_to          두 인수가 같은지 비교하여 결과를 bool타입으로 리턴한다.
//not_equal_to      두 인수가 다른지 비교한다.
//greater           첫 번째 인수가 두 번째 인수보다 큰지 조사한다.
//less              첫 번째 인수가 두 번째 인수보다 작은지 조사한다.
//greater_equal     첫 번째 인수가 두 번째 인수보다 크거나 같은지 조사한다.
//less_equal        첫 번째 인수가 두 번째 인수보다 작거나 같은지 조사한다.
//logical_and       두 인수의 논리곱(&&) 결과를 리턴한다.
//logical_or        두 인수의 논리합(|| ) 결과를 리턴한다.
//logical_not       인수 하나를 전달받아 논리부정(!)을 리턴한다.
