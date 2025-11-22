// 키보드 이용 움직이기

#include <stdio.h>
#include <conio.h>
#include <windows.h>	

void gotoxy(int x, int y) // 입력된 x, y 값으로 화면에 커서를 이동시켜주는 함수
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKey(void)
{
	int ch = _getch();
	if (ch == 0 || ch == 224)	// 방향키의 경우 0 또는 224의 값이 먼저 입력됨
		ch = _getch();	// 그 다음에 해당 방향키에 따라 72(Up),80(Down), 75(Left), 77(Right) 값이 입력됨
	return ch;
}

int main(void)
{
	int x, y, bk, key, track;
	x = 10;	y = 5;	track = 0;

	while (1) // while(1)은 무한 반복 실행을 위해 사용하는 문법으로, break 문을 만나기 전까지 무한 루프
	{
		key = GetKey();

		if (key == 'q' || key == 'Q' || key == 55) { x = x - 1; y = y - 1; } //좌상측 대각선
		else if (key == 'e' || key == 'E' || key == 57) { x = x + 1; y = y - 1; } //우상
		else if (key == 'z' || key == 'Z' || key == 49) { x = x - 1; y = y + 1; } //좌하
		else if (key == 'c' || key == 'C' || key == 51) { x = x + 1; y = y + 1; } //우하
		else if (key == 'a' || key == 'A' || key == 52) { x = x - 1; } // 52,54,56,50 : 4,6,8,2 숫자키패드
		else if (key == 'd' || key == 'D' || key == 54) { x = x + 1; }
		else if (key == 'w' || key == 'W' || key == 56) { y = y - 1; }
		else if (key == 's' || key == 'S' || key == 50) { y = y + 1; }
		else if (key == 75) { x = x - 1; }	// 좌 방향키
		else if (key == 77) { x = x + 1; }	// 우 방향키
		else if (key == 72) { y = y - 1; }	// 상 방향키
		else if (key == 80) { y = y + 1; }	// 하 방향키

		if (x < 0) x = 0;		//범위 제한
		if (x > 50) x = 50;
		if (y < 0) y = 0;
		if (y > 25) y = 25;

		if (key == 32)		// space bar
		{
		}
		if (key == 13)		//enter //VK_RETURN
		{
			system("cls");
		}
		if (key == 27)		//esc  //VK_ESCAPE
		{
			gotoxy(x, y); printf("STOP\n");	break;
		}

		//display -----------------------------------
		system("cls");
		gotoxy(0, 0);					// 현재 커서의 포지션을 0,0으로 초기화함
		printf("x:%3d y:%3d", x, y);	// 현재 커서의 좌표를 화면에 x, y값으로 출력함
		gotoxy(x, y);					// gotoxy함수로 현재 x,y 좌표를 이동시킴
		printf("♥");					// 커서의 위치에 하트 그림을 출력함
	}
	return 0;
}


/*
void CursorView(bool show)			//커서 깜빡임
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
*/