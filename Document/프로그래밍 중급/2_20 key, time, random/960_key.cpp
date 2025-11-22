// key : 키보드 키 값 얻어오기

#include <iostream>
#include <conio.h>

int main()
{
	int nKey = 0;
	while (true)
	{
		if (_kbhit())			//키보드입력 체크
		{
			nKey = _getch();	//키보드 키 값 얻어오기

			printf("%c", nKey);
		}
	}
	return 0;
}

int GetKey(void)
{
	int ch = _getch();
	if (ch == 0 || ch == 224)	// 방향키의 경우 0 또는 224의 값이 먼저 입력됨
		ch = _getch();			// 그 다음에 해당 방향키에 따라 72(Up),80(Down),75(Left),77(Right) 값이 입력됨
	return ch;
}


/*
 
kbhit() 또는 _kbhit() 는 키-버퍼에 값이 들어 있나 확인하고
						있으면 1 (숫자 일), 없으면 0 (숫자 영)을 리턴합니다.

getch() 또는 _getch() 는 키-버퍼에서 값을 1개 빼내 그 값을 아스키코드값으로 리턴해줍니다.
						값이 없을 경우, 키를 누를 때까지 기다립니다.
						예외적으로 이 함수를 두번 써야 하는 경우가 있습니다.
						한글이나 한자 그리고 표의 예외키들은 키-버퍼에 값을 2개 보냅니다.

//키보드 키    getch() 반환값 1st    	getch() 반환값 2nd
F1		0	59
F2		0	60
F3		0	61
F4		0	62
F5		0	63
F6		0	64
F7		0	65
F8		0	66
F9		0	67
F10		0	68
F11		224	133
F12		224	134
INSERT	224	82
DELETE	224	83
HOME	224	71
END		224	79
PGUP	224	73
PGDN	224	81
↑		224	72
←		224	75
→		224	77
↓		224	80
*/


/*
//가상 키 코드
//https://docs.microsoft.com/ko-kr/windows/win32/inputdev/virtual-key-codes

#include <Windows.h>

int main()
{
	if (GetKeyState(VK_SHIFT) & 0x8000)
	{
		// Shift down
	}

	SHORT keyState = GetKeyState(VK_CAPITAL);  //caps lock
	bool isToggled = keyState & 1;
	bool isDown = keyState & 0x8000;
}

*/