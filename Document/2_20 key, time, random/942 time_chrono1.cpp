#include <iostream>
#include <ctime>    
#include <chrono>                   //시간 표현 라이브러리 //C++
using namespace std;
using namespace std::chrono;

int main()
{
    auto now = std::chrono::system_clock::now();        //std::chrono::time_point
    std::cout << now << "\n";

    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::cout << now_time << "\n";                      //경과시간 //long long

    char buf[256];
    ctime_s(buf, sizeof(buf), &now_time);               //현재시간을 문자열로 변환
    std::cout << buf << "\n";


    //current_zone //C++20
    std::chrono::zoned_time now2{ std::chrono::current_zone(), std::chrono::system_clock::now() }; 
    std::cout << now2 << "\n";

    //--------------------------------------------------------------------------------------------

    auto start = std::chrono::system_clock::now();
    // Some computation here
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;    //duration 시간 간격 // 초
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";

}


// GetTickCount -----------------------------------------------------------------------------

#include <iostream>
#include <windows.h>                //windows.h 헤더 추가
#pragma comment(lib, "Winmm.lib")   //winmm.lib 추가
using namespace std;

void main()
{
    for (;;) {
        unsigned long time = GetTickCount();            //32비트값이므로 최대 49.7일간
        DWORD time2 = GetTickCount();                   //ms단위로 반환

        unsigned __int64 time_64 = GetTickCount64();    //오버플로우 시점이 약 5억8천년
        ULONGLONG time2_64 = GetTickCount64();

        cout << "GetTickCount : " << time << "\t" << "GetTickCount64 : " << time2 << endl;
    }
}
