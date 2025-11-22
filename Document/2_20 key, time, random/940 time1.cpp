//localtime_s  //gmtime_s // asctime_s

#include <iostream>
#include <ctime>				//#include <time.h>
using namespace std;

int main()
{
	// 현재시간 년월일로 출력하기 ------------------------------------------------

	time_t t = time(nullptr);
	tm tm1;						// tm 타입
	localtime_s(&tm1, &t);      // time_t -> tm (로컬 타임)

	std::cout << tm1.tm_year + 1900 << " " << tm1.tm_mon + 1 << " " << tm1.tm_mday << std::endl;


	//현재 시간에 특정 날짜 값 더하기 -----------------------------------

	time_t t3 = time(nullptr);
	tm tm3;
	localtime_s(&tm3, &t3);		// time_t -> tm
	tm3.tm_mon++;
	t3 = mktime(&tm3);			// tm -> time_t

	char str3[80];
	strftime(str3, sizeof(str3), "%Y-%m-%d", &tm3);
	std::cout << str3 << std::endl;


	// 입력받은 값 날짜로 변경하기 ----------------------------------------

	int year;
	int month;
	int day;
	//scanf_s("%d-%d-%d", &year, &month, &day);
	cout << "year month day : "; cin >> year >> month >> day;

	tm tm2;
	tm2.tm_year = year - 1900;
	tm2.tm_mon = month - 1;
	tm2.tm_mday = day;

	char str[80];
	strftime(str, sizeof(str), "%Y-%m-%d", &tm2); //특정 서식으로 문자열 출력
	std::cout << str << std::endl;

	return 0;
}


//UTC 기준 시간(GMT) 정보 time_t 가져오기 ----------------------------------------

#include <iostream>
#include <stdio.h>
#include <time.h>

int main()
{
	time_t curTime;
	time(&curTime);					//현재 시스템의 시간에 해당하는 time_t 값을 가져옴

	
	//현재 시스템의 타임존 기준(local time) 가져오기

	struct tm localTM;
	localtime_s(&localTM, &curTime);				

	char buff[256];
	asctime_s(buff, sizeof(buff), &localTM);		//struct tm 을 문자열로 바꿔줌.
	printf("Local Time: %s\n", buff);				//"Mon Mar 30 12:00:00 2020"

	//UTC 기준 시간(GMT) 정보 time_t 가져오기 ***

	struct tm gmTM;
	gmtime_s(&gmTM, &curTime);						

	asctime_s(buff, sizeof(buff), &gmTM);			//struct tm 을 문자열로 바꿔줌.
	printf("UTC  Time: %s\n", buff);				//"Mon Mar 30 03:00:00 2020"
}

//time_t localtime_s  -----------------------------------------------

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	time_t base_time = 0;                           //1970/01/01 기준

	struct tm timeinfo;                             //struct tm 

	localtime_s(&timeinfo, &base_time);             //초 단위 값으로 지역 시각(DateTime)을 구한다.

	char buf[100];
	asctime_s(buf, sizeof(buf), &timeinfo);         //버퍼에 초 단위 시간의 지역 기준 시각을 출력
	printf("time_t 형식의 지역 기준 시각:%s", buf);   //표준 출력 스트림에 출력

	//printf("GMT 와의 시각 차이: %d시 %d분\n", timeinfo.tm_hour, timeinfo.tm_min);

	cout << "현재 년도 : " << 1900 + timeinfo.tm_year << "\n";
	cout << "현재 월  : " << 1 + timeinfo.tm_mon << "\n";
	cout << "현재 일  : " << timeinfo.tm_mday << "\n";
}
