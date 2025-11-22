#include <iostream>
#include <cmath>
#include <chrono>           //시간 표현 라이브러리 //C++
using namespace std;
using namespace std::chrono;

//Test() 함수 수행 시간 을 구하세요 --------------------

void Test()
{
    for (long i = 0; i < 10000000; ++i)
        std::sqrt(123.456L);
}

int main()
{
    system_clock::time_point StartTime = system_clock::now();   //나노 초 (default)
    Test();     //doing
    system_clock::time_point EndTime = system_clock::now();

    duration<double> DefaultSec = EndTime - StartTime;          //경과시간  //초

    nanoseconds nano    = EndTime - StartTime;                  //경과시간  //나노 초
    seconds sec         = duration_cast<seconds>(EndTime - StartTime);
    minutes min         = duration_cast<minutes>(EndTime - StartTime);
    hours hour          = duration_cast<hours>(EndTime - StartTime);
    milliseconds mill   = duration_cast<milliseconds>(EndTime - StartTime);
    microseconds micro  = duration_cast<microseconds>(EndTime - StartTime);

    cout << "Test() 함수 수행 시간 : " << DefaultSec.count() << " default" << endl;
    cout << "Test() 함수 수행 시간 : " << nano.count() << " nanoseconds" << endl;
    cout << "Test() 함수 수행 시간 : " << sec.count() << " seconds" << endl;
    cout << "Test() 함수 수행 시간 : " << min.count() << " minutes" << endl;
    cout << "Test() 함수 수행 시간 : " << hour.count() << " hour" << endl;
    cout << "Test() 함수 수행 시간 : " << mill.count() << " milliseconds" << endl;
    cout << "Test() 함수 수행 시간 : " << micro.count() << " microseconds" << endl;

    return 0;
}
