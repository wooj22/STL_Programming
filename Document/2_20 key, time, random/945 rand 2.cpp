//예시 //일정 범위 난수 생성

#include <iostream>
#include <cstdlib>
#include <ctime>

int randomRange(int a, int b) {
    return rand() % (b - a + 1) + a;
}

double randomDouble(void) {
    return (double)rand() / RAND_MAX;
}

int main(void) {

    // 난수 발생기 초기화
    srand((unsigned int)time(NULL));

    // 0 ~ 32767 까지의 정수 난수 생성
    printf("%d\n", rand());

    //일정 범위 난수 생성 --------------------------------------------
    for (int i = 1; i <= 10; i++)
        printf("%d\n", randomRange(1, 4));

    // 범위의 실수 난수 생성 // 0.000 ~ 1.000 ------------------------
    for (int i = 1; i <= 10; i++)
        printf("%.3f\n", randomDouble());

    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>     // RAND_MAX
#include <time.h>
#include <Windows.h>    // GetTickCount()

*/