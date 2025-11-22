// 색 설정

#include <stdio.h>
#include <Windows.h>

void scolor(unsigned short text = 15, unsigned short back = 0)	//글자와 바탕색 설정
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text | (back << 4));
}

void main()
{
	//배경색을 5로 바꿈 배경색만 바꾸고 싶다면 이 명령어만 쓰면된다.(숫자만 바꾸면 글자색과 동일)
	system("color f");		// 0xFF	
	printf("글자색(0~15 까지 총 16가지의 색깔이 있다.)\n");

	// 글자색, 배경색 바꾸기
	int a = 0;
	for (int i = 0; i <= 15; i++)
	{
		scolor(0, a);
		printf("글자색값 : %02d - 배경색값 : %02d ", 0, a);
		scolor(a, 0);
		printf("글자색값 : %02d - 배경색값 : %02d \n", a, 0);
		a++;
	}

	scolor(); //아무것도 입력 안할시 원래 글자색으로 만듬. 초기화값 scolor(15,0)을 입력해도 동일
	printf("원래 글자색(0~15 까지 총 16가지의 색깔이 있다.)\n");
}

/*
enum ConsoleColor
{
	black = 0,
	dark_blue = 1,
	dark_green = 2,
	dark_aqua, dark_cyan = 3,
	dark_red = 4,
	dark_purple = 5, dark_pink = 5, dark_magenta = 5,
	dark_yellow = 6,
	dark_white = 7,
	gray = 8,
	blue = 9,
	green = 10,
	aqua = 11, cyan = 11,
	red = 12,
	purple = 13, pink = 13, magenta = 13,
	yellow = 14,
	white = 15
};
*/