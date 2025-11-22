//로컬타임, UTC 타임으로 변경하는 함수 만들어 사용

//mktime //_mkgmtime

#include <iostream> 
//#include <stdio.h> 
//#include <time.h> 
using namespace std;

time_t MakeLocalTime_t(int YYYY, int MM, int DD, int hh, int mi, int ss); //현지 시각 tm -> time_t 
time_t MakeUTCTime_t(int YYYY, int MM, int DD, int hh, int mi, int ss); //UTC(GMT) 시각 tm -> time_t 

int main()
{
	//time_t 값으로 변환할 날짜 
	int year = 2022; int mon = 12; int day = 25;
	int hour = 0; int min = 0; int sec = 0;

	time_t localTime = MakeLocalTime_t(year, mon, day, hour, min, sec);
	cout << localTime << endl;

	time_t utcTime = MakeUTCTime_t(year, mon, day, hour, min, sec);
	cout << utcTime << endl;

	//응용 -----------------------

	//현재부터 2022년 크리스마스 까지 남은 초 
	time_t curTime; time(&curTime);
	cout << "time remaining : " << localTime - curTime << endl;

	//크리스마스 이후인지 검사 
	if (curTime >= localTime) { printf("Merry X-mas"); }
}

time_t MakeLocalTime_t(int YYYY, int MM, int DD, int hh, int mi, int ss)
{
	struct tm st_tm;
	st_tm.tm_year = YYYY - 1900;
	st_tm.tm_mon = MM - 1;
	st_tm.tm_mday = DD;
	st_tm.tm_hour = hh;
	st_tm.tm_min = mi;
	st_tm.tm_sec = ss;
	return mktime(&st_tm);
}

time_t MakeUTCTime_t(int YYYY, int MM, int DD, int hh, int mi, int ss)
{
	struct tm st_tm;
	st_tm.tm_year = YYYY - 1900;
	st_tm.tm_mon = MM - 1;
	st_tm.tm_mday = DD;
	st_tm.tm_hour = hh;
	st_tm.tm_min = mi;
	st_tm.tm_sec = ss;
	return _mkgmtime(&st_tm);  //유닉스 기반 시스템에서는 timegm
}
