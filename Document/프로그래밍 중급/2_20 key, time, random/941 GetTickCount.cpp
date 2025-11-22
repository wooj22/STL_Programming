//Windows API - 
//		Windows에서 동작하는 App을 만들 때, Windows가 프로그래머들을 위해서 제공해주는 소스코드들
//		Microsoft Windows에서 사용하는 C언어 기반의 API

//1.timeGetTime() 함수 
//		윈도우(운영체제)가 시작되어서 지금까지 흐른 시간을 
//		1/1000 초(milliseconds) 단위로 DWORD형을 리턴하는 함수다.
//		#pragma comment(lib, "winmm.lib")

//GetTickCount()란?
//		DWORD GetTickCount(VOID);
//		OS부팅할 때부터 지나간 시간을 msec 단위로 돌려주는 함수
//		카운트는 32비트값이므로 최대 49.7일간의 카운트를 유지할 수 있다.

#include <windows.h>						//
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	float m_fStartTime = (float)timeGetTime() * 0.001f;   //초단위로 바꿔줌

	//루프 

	float NowTime = (float)timeGetTime() * 0.001f;
	if (NowTime - m_fStartTime >= 0.1f)		// 여기서 0.1 은 0.1초마다 실행을 의미
	{
		//함수실행	
		m_fStartTime = NowTime;
	}


	//위의 방법을 이용해서 얻은 시간데이터를 시, 분, 초 단위로 변경할 수 있다.
	int nowTime = NowTime;
	DWORD Hour = (nowTime / 60 / 60) % 60;
	DWORD Minute = (nowTime / 60) % 60;
	DWORD Second = nowTime % 60;

	return 0;
}


void main()
{
	unsigned long startT = GetTickCount64();  // 64비트로 확장, 5억년이 넘는다.
	DWORD startTD = GetTickCount64();
	
	cout << startT << endl;
	cout << startTD << endl;

	//프로그래밍 루프들~( 시간 소요 )

	unsigned long endT = GetTickCount64();
	cout << endT << endl;
	puts("\n");

	int DletaT = endT - startT;
	cout << DletaT << endl;

	long dSec = (DletaT / 1000);
	int dMin = (dSec % 3600) / 60;
	int dHour = dSec / 3600;;
	char str[50];
	sprintf_s(str, "Access Time:  %d시간  %d분  %d초", dHour, dMin, dSec % 60);
	cout << str << endl;

}


#include <stdio.h>
#include <windows.h>

void main()
{
	while (1)
	{
		int StartTime;
		StartTime = GetTickCount();

		while (GetTickCount() - StartTime >= 1000);
		{
			printf("1초마다 한번씩 실행됩니다\n");
		}
		else
		{
			//딜레이를 주는 부분
		}
	}
}