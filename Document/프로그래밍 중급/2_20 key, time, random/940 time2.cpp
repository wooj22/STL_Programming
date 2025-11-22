#include <stdio.h>
#include <time.h>               //시간 표현 라이브러리 //C
#include <windows.h>

//#include <iostream> 
//using namespace std;

// for문 수행 시간구하기.

void main() {

    time_t start, end;                          //time_t

    start = time(NULL);                         //time()

    for (int i = 0; i < 30; i++) {
        printf("%d번째 for문\n", i);
        Sleep(50);
    }

    end = time(NULL);

    double diff_timer = difftime(end, start);    //difftime()

    printf("for문 수행 시간(difftime): %lf초\n", diff_timer);
}

// 입력한 시간부터 현재시간까지 얼마가 지났는지 출력하기

/*
#include <stdio.h>
#include <time.h>               //시간 표현 라이브러리 //C
#include <windows.h>
//#include <iostream>
//using namespace std;

int main(void)
{
    time_t start, end;
    struct tm user_stime;
    int my_year, my_month, my_day;
    double diff;
    int tm_day, tm_hour, tm_min, tm_sec;

    printf("년도 : ");  scanf_s("%d", &my_year);
    printf("월 : ");    scanf_s("%d", &my_month);
    printf("일 : ");    scanf_s("%d", &my_day);

    user_stime.tm_year = my_year - 1900;    //년도가 1900년부터 시작
    user_stime.tm_mon = my_month - 1;       //월이 0부터 시작
    user_stime.tm_mday = my_day;
    user_stime.tm_hour = 0;
    user_stime.tm_min = 0;
    user_stime.tm_sec = 0;
    user_stime.tm_isdst = 0;
    start = mktime(&user_stime);            //입력한 시간

    time(&end);                             //현재 시간

    diff = difftime(end, start);

    tm_day = diff / (60 * 60 * 24);    diff -= (tm_day * 60 * 60 * 24);
    tm_hour = diff / (60 * 60);        diff -= (tm_hour * 60 * 60);
    tm_min = diff / 60;                diff -= (tm_min * 60);
    tm_sec = diff;

    printf("%d년 %d월 %d일부터 현재까지 %d일 %d시 %d분 %d초 지났습니다.\n",
        my_year, my_month, my_day, tm_day, tm_hour, tm_min, tm_sec);

    return 0;
}

*/