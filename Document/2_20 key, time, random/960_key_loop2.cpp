#define _CRT_SECURE_NO_WARNNING
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>

void CursorView(bool show) //커서 깜빡임
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

//커서 위치 이동
void gotoxy(int x = 0, int y = 0)	//windows,stdio
{
	COORD coord = { 0, 0 };
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// milliseconds 동안 입력이 없는 경우 -1 리턴, 입력한 경우 입력한 키 리턴
int wsleep(int* milliseconds, int* a)
{
	while (_kbhit() == 0)
	{
		if (*milliseconds <= 0) return -1;
		Sleep(10);
		*milliseconds -= 10;
	}
	*a = _getch();
	return *a;
}

void main()
{
	bool TipPlay = true;
	int x1, y1;
	int WaitTime = 1000;	//화면이 바뀔 시간초
	int Ent = 0;			//키 입력
	char desc[100] = "mode con: cols=100 lines=32";
	char backcolor[100] = "color 5f";
	int backint = 0;

	system(desc);
	system("color 0f");

	while (TipPlay)
	{
		wsleep(&WaitTime, &Ent);			//1초동안 입력을 기다림(WaitTime==1000 이기 때문에 1000=1초)

		if (WaitTime <= 0)					//주기적으로 발생하는 함수 ***
		{
			WaitTime = 1000;				//1초가 지나면 1초로 설정(1초마다 일어나도록 함)

			backint++;						//색 변경
			if (backint == 10) backint = 0;
			sprintf_s(backcolor, sizeof(backcolor), "%s%d%s", "color ", backint, "f");
			system(backcolor);
		}

		gotoxy(0, 0);
		CursorView(false);					//딱히 입력 받는 것이 아니니 커서 깜빡임 제거
		printf("크기를 변경하려면 'T'를 누르세요");

		if (Ent == 'T' || Ent == 't')
		{
			Ent = 0;						//키입력 초기화
			gotoxy(0, 0);
			CursorView(true);				//입력할때는 커서 깜박임 출력
			desc[15] = NULL;				//"mode con: cols=" 까지만 입력
			printf("x 좌표입력 :    \n");
			printf("y 좌표입력 :    \n");
			gotoxy(13, 0);	scanf_s("%d", &x1);
			gotoxy(13, 1);	scanf_s("%d", &y1);
			// 배열 abc 에 여러 문자열 넣기. printf는 콘솔창에 띄워주는 것이지만 sprintf는 앞의 변수에 입력을 해주는 함수.
			sprintf_s(desc, sizeof(desc), "%s%d%s%d", "mode con: cols=", x1, " lines=", y1);
			printf("%s", desc);
			system(desc);

			gotoxy(x1 - 2, y1 - 1);			//구석지에 별 생성
			printf("★");
		}


	}
	return;
}