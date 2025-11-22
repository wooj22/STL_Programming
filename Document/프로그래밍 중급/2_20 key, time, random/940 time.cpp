//time(), time_t

#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	// time_t ----------------------------------- //초단위시간 //__int64
	time_t t = time(nullptr);	// 현재시간 얻기

	cout << t << endl;

	// tm 구조체 --------------------------------- //년월일시분초 형태	
	tm tm1;

	int year = 2020;
	int mon = 12;
	int day = 25;
	int hour = 0;
	int min = 0;
	int sec = 0;

	tm1.tm_year = year - 1900;
	tm1.tm_mon = mon - 1;
	tm1.tm_mday = day;
	tm1.tm_hour = hour;
	tm1.tm_min = min;
	tm1.tm_sec = sec;

	//특정 서식으로 문자열 출력 하기 -----------------------------
	//strftime

	char str[80];
	strftime(str, sizeof(str), "%Y-%m-%d", &tm1);
	cout << str << endl;


	// time_t -> tm 타입 (로컬 타임) ----------------------------
	//localtime_s() 

	tm tm2;
	localtime_s(&tm2, &t);						

	// tm 타입을 time_t로 변환 ----------------------------------
	//mktime()

	time_t t3;
	tm tm3;
	t3 = mktime(&tm3);							
}

/*

// time_t -----------------------------------------------

C++ 에서는 
UTC 1970년 1월 1일 00:00:00 로 부터 시간을 초(second)단위로 카운트하여
time_t 라는 타입으로 제공한다. 
(time_t 타입은 int64 를 typedef 으로 정의하고 있다.)

time_t 형식을 
년월일시분초 형태로 분할한 일시(struct tm 형식)로 변환하는
gmtime(gmtime_s)과 localtime(localtime_s) 함수가 있다.


// struct tm ---------------------------------------------

struct tm {
	int tm_sec;
	int tm_min;
	int tm_hour;
	int tm_mday;
	int tm_mon;
	int tm_year;
	int tm_wday;
	int tm_yday;
	int tm_isdst;
};

//멤버	 의미						값의 범위

tm_sec	 현재 시각이 몇 초 인지		0 - 61 *
tm_min	 현재 시각이 몇 분 인지		0 - 59
tm_hour	 현재 시각이 몇 시 인지		0 - 23
tm_mday	 지금이 몇 일 인지	        1 - 31
tm_mon	 지금이 몇 월 인지	        0 - 11
tm_year	 지금이 몇 년 인지(1900 이후)
tm_wday	 지금이 무슨 요일 인지	    0 - 6 
tm_yday	 1 월 1 일 부터 몇 일이 지났는지	0 - 365		
tm_isdst 서머 타임제를 실시하고 있는지 아닌지



//tm_sec
//		'윤초' 를 도입하여 시간을 보정하는 경우가 있어 
//		tm_sec 의 값이 60 혹은 61 이 될 수 있다
//tm_wday
//		일=0, 월=1, 화=2, 수=3, 목=4, 금=5, 토=6
//tm_isdst 가 
//		0 보다 크면 '서머 타임제'를 실시, 
//		0 이면 실시하지 않다, 
//		0 보다 작으면 알 수 없다는 의미

*/

/*
// time() 함수를 사용하여 현재 년월일시 출력하기.

#define _CRT_SECURE_NO_WARNINGS		// 혹은 localtime_s를 사용

#include <stdio.h>
#include <time.h>

int main()
{
	time_t timer;
	timer = time(NULL);		// 1970년 1월 1일 0시 0분 0초부터 시작하여 현재까지의 초

	struct tm* t;
	t = localtime(&timer);	// 포맷팅을 위해 구조체에 넣기

	printf("시스템 타임: %lld 초\n\n", timer);
	printf("현재 년: %d\n", t->tm_year + 1900);
	printf("현재 월: %d\n", t->tm_mon + 1);
	printf("현재 일: %d\n", t->tm_mday);
	printf("현재 시: %d\n", t->tm_hour);
	printf("현재 분: %d\n", t->tm_min);
	printf("현재 초: %d\n", t->tm_sec);
	printf("현재 요일: %d\n", t->tm_wday);			// 일=0, 월=1, 화=2, 수=3, 목=4, 금=5, 토=6
	printf("올해 몇 번째 날: %d\n", t->tm_yday);		// 1월 1일은 0, 1월 2일은 1
	printf("서머타임 적용 여부: %d\n", t->tm_isdst);	// 실시 중이면 양수, 미실시면 0, 실시 정보가 없으면 음수

	return 0;
}
*/