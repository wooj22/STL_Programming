//#include <ctime>
// 
//clock()
// 
//      프로그램이 실행된 순간부터 이 함수가 호출된 순간까지 경과된 시간을 리턴한다.
//      리턴 값은 Second 단위가 아니다.           // 1/1000 초
//      리턴하는 데이터형이 시스템에 따라 다르다. (long형, unsigned long형 등)
//
//      초 단위 시간 = clock() / CLOCKS_PER_SEC          

#include <windows.h>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    while (1) {

        clock_t clk = clock(); cout << clk << endl;
        Sleep(1000);
    }
}


//입력받은 시간만큼 지연 시키기 --------------------------------------------

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    cout << "지연할 시간 : ";
    float secs;
    cin >> secs;

    clock_t delay = secs * CLOCKS_PER_SEC;  // 변수 delay에는 희망 지연시간이 초 단위로 저장된다.

    cout << "카운트를 시작합니다.\a\n";

    clock_t start = clock();                //현재 시간.

    while (clock() - start < delay);        // clock()-start 는 루프를 돌면서 경과한 시간을 지연한다.

    cout << "종료" << endl;

    return 0;
}


/*
// 특정 코드의 실행시간을 출력하기 --------------------------------------------------------

//clock() ---------------------------------------------------

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    clock_t start, finish;

    start = clock();

    //실행 시간을 측정하고 싶은 코드 추가

    finish = clock();

    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    cout << duration << "초" << endl;

    return 0;
}

//time(NULL) -----------------------------------------------

#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t start, finish;
    double duration;

    start = time(NULL);

    //실행 시간을 측정하고 싶은 코드

    finish = time(NULL);

    duration = (double)(finish - start);
    cout << duration << "초" << endl;

    return 0;
}

*/