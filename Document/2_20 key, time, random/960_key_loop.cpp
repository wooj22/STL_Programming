#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

//커서 위치 이동 // 입력된 x, y 값으로 화면에 커서를 이동시켜주는 함수
void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKey(void)
{
	int ch = _getch();
	if (ch == 0 || ch == 224)	// 방향키의 경우 0 또는 224의 값이 먼저 입력됨
		ch = _getch();		// 그 다음에 해당 방향키에 따라 72(Up),80(Down), 75(Left), 77(Right) 값이 입력됨
	return ch;
}

void main()
{
	int key;
	int x = 5, y = 5;

	while (true)
	{
		key = GetKey();

		if (key == 75) { if (x > 0) x = x - 1; }	// 좌 방향키
		else if (key == 77) { if (x < 20) x = x + 1; }	// 우 방향키
		else if (key == 72) { if (y > 0) y = y - 1; }	// 상 방향키
		else if (key == 80) { if (y < 10) y = y + 1; }	// 하 방향키

		//if (key == 27)			//esc
		//{
		//	cout << "STOP"; break;
		//}

		//system("cls");			//화면 클리어
		gotoxy(x, y); cout << "A";
	}
	return;
}

/*
void CursorView(bool show)//커서 깜빡임
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}
*/