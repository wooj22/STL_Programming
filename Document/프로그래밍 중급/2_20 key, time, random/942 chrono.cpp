// C언어 /C++ 에서 측정된 시간을 
// clock, GetTickCount , timeGetTime함수를 통해 사용
// 
// 이 함수들은 전부 밀리초까지만 측정이 가능하여 그 보다 더 정밀하게는 측정이 불가능하다.
//
// C++ 11부터 chrono 함수가 새롭게 추가 ***

#include <iostream>
#include <chrono>                   //
using namespace std;
using namespace chrono;             //

void main()
{
    long sum = 0;
    system_clock::time_point start = system_clock::now();
    for (int i = 0; i < 1000000; i++) {
        sum += i;
    }
    system_clock::time_point end = system_clock::now();
    nanoseconds nano = end - start;

    cout << "경과시간(나노초 ns) : " << nano.count() << endl;

        
    //Duration ------------------------------------------------------------
    //      Duration은 chrono에서 경과 시간을 나타내는 클래스      

    //system_clock::now()는 nano seconds 단위  //명시적 캐스팅으로 사용. 

    // 시간 단위
    hours hour = duration_cast<hours>(end - start);
    // 분 단위
    minutes min = duration_cast<minutes>(end - start);
    // 초 단위
    duration<double> sec = end - start;     // 초 단위 (소수점으로 표현)

    // 밀리 초 단위 (1/1000)
    milliseconds milliSec = duration_cast<milliseconds>(end - start);
    // 마이크로 초 단위 (1/1000000)
    microseconds microSec = duration_cast<microseconds>(end - start);
    // 나노 초 단위 (1/1000000000)
    nanoseconds nanoSec = end - start;

}

//Duration은 chrono에서 경과 시간을 나타내는 클래스
    typedef duration<int, ratio<3600> > hours;
    typedef duration<int, ratio<60> > minutes;
    typedef duration<long long> seconds;
    typedef duration<long long, milli> milliseconds;
    typedef duration<long long, micro> microseconds;
    typedef duration<long long, nano> nanoseconds;

/*
#include <iostream>
#include <chrono>
using namespace std;

void main()

{
    long sum = 0;
    chrono::system_clock::time_point StartTime = chrono::system_clock::now();

    for (int i = 0; i < 1000000; i++) {
        sum += i;
    }

    chrono::system_clock::time_point EndTime = chrono::system_clock::now();
    chrono::duration<double> DefaultSec = EndTime - StartTime;
    chrono::nanoseconds nano = EndTime - StartTime;
    chrono::microseconds micro = chrono::duration_cast<chrono::microseconds>(EndTime - StartTime);
    chrono::milliseconds mill = chrono::duration_cast<chrono::milliseconds>(EndTime - StartTime);
    chrono::seconds sec = chrono::duration_cast<chrono::seconds>(EndTime - StartTime);
    chrono::minutes min = chrono::duration_cast<chrono::minutes>(EndTime - StartTime);
    chrono::hours hour = chrono::duration_cast<chrono::hours>(EndTime - StartTime);
    cout << "for문 실행 시간(default) : " << DefaultSec.count() << endl;
    cout << "for문 실행 시간(nanoseconds) : " << nano.count() << endl;
    cout << "for문 실행 시간(microseconds) : " << micro.count() << endl;
    cout << "for문 실행 시간(milliseconds) : " << mill.count() << endl;
    cout << "for문 실행 시간(seconds) : " << sec.count() << endl;
    cout << "for문 실행 시간(minutes) : " << min.count() << endl;
    cout << "for문 실행 시간(hour) : " << hour.count() << endl;
}
*/


//steady_clock --------------------------------------------------------
//      시간의 값이 시스템 설정과 무관하게 한결같이 흘러가야 할 때
//      system_clock을 상속

//system_clock은 전통적인 유닉스 타임으로 1970 1월 1일 목요일 0시 0분 0초 이후로 흘러간 시간을 나타냅니다.
//그에 반하여 steady_clock은 마지막 부팅 이후로 흘러간 시간을 나타냅니다.

//시계를 표현하기 위해서는 system_clock을, 
//초시계를 표현하기 위해서는 steady_clock을 사용해야 합니다.
//그 이유는 system_clock과 같은 경우 OS 시간 동기화 등에 의하여 시간 측정 중에 시간 값이 변할 수 있기 때문인데 반하여 
//steady_clock은 그럴 가능성이 없기 때문입니다.

//게임 서버에서 아이템과 같은 경우는 
//      소유한 이후에 서버 부팅이 일어날 수도 있기 때문에 system_clock_test()을 사용하는 것이 좋습니다. 
//이에 반하여 스킬 사용시간 같은 경우는 
//      사용 후 장애가 아니고서는 서버 부팅이 일어날 일이 없으므로 steady_clock_test()을 사용

/*
//steady_clock 시간 측정 예제 코드

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

void system_clock_test()
{
    time_point start = system_clock::now();
    this_thread::sleep_for(milliseconds(1000));
    time_point stop = system_clock::now();
    duration  elapsed = stop - start;
    long long miliseconds = duration_cast<milliseconds>(elapsed).count();
    cout << miliseconds << " ms" << endl;
}

void steady_clock_test()
{
    time_point start = steady_clock::now();
    this_thread::sleep_for(milliseconds(1000));
    time_point stop = steady_clock::now();
    duration  elapsed = stop - start;
    long long miliseconds = duration_cast<milliseconds>(elapsed).count();
    cout << miliseconds << " ms" << endl;
}

int main(int argc, char* argv[])
{
    system_clock_test();

    steady_clock_test();

    return 0;
}

*/