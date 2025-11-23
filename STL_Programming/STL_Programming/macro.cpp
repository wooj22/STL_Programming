/*
	[ Macro(매크로) - #define ]
    
    매크로는 전처리기 단계에서 "텍스트 치환"으로 동작하는 기능이다.
    컴파일 전에 코드 조각을 자동으로 치환하여 반복 작업을 줄이거나 코드를 단순화한다.
    함수처럼 보이기도 하지만 실제로는 단순한 문자열 치환이다.
    복잡한 매크로는 디버깅이 어려울 수 있으므로 주의가 필요하다.

    [ #define ]
    매크로를 정의하는 전처리 지시문

    - 단순 치환 매크로
	- 함수형 매크로
	- 문자열화 매크로(#)
    - 토큰 결합 매크로 (##)
*/

#include <iostream>
#include <stdio.h>
using namespace std;

// 단순 치환
#define PI 3.14
#define NAME "Alice"
#define PRINT_SCORE std::cout << score << std::endl;

// 함수형
#define ADD(a, b) ((a) + (b))
#define SQUARE(x) ((x) * (x))

// 문자열화 -> a가 문자열 리터럴 "a"가 된다.
#define STRING(a) #a

// 토큰 결합 -> a, b를 붙여 ab가 된다.
#define JOIN(a, b) a##b

int main()
{
    // 1. 단순 치환 매크로 사용
    cout << "PI: " << PI << endl;          // 3.14
    cout << "NAME: " << NAME << endl;      // "Alice"

    int score = 95;
    cout << "PRINT_SCORE: ";
    PRINT_SCORE;                            // cout << score << endl;


    // 2. 함수형 매크로 사용
    cout << "ADD(2, 3): " << ADD(2, 3) << endl;        // 5
    cout << "SQUARE(4): " << SQUARE(4) << endl;        // 16


    // 3. 문자열화 매크로 사용 (#)
    cout << "STRING(Hello): " << STRING(Hello) << endl;  // "Hello"


    // 4. 토큰 결합 매크로 활용 (##)
    int dataValue = 123;
    cout << "JOIN(data, Value): " << JOIN(data, Value) << endl;
}