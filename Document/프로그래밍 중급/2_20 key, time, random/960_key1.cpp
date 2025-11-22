// 키입력
/*
    #include <stdio.h>
    #include <conio.h>                      //_getch가 포함되어있는 헤더

    int main(void) {
        char c;
        for (;;) {
            c = _getch();                   //입력값 input  //아스키(ASCII) 코드 

            printf("입력 값 : %c\n", c);     //입력값 출력
        }

        return 0;
    }
*/

//getch() 함수는 마지막에 누른 키 하나만을 입력받습니다. 
//그렇기에 두개 이상의 키를 한번에 입력받지 못하여 반응속도가 늦습니다.

//게임을 개발할 목적이라면 
//getch() 함수의 사용보다는 멀티 입력이 가능한 GetAsyncKeyState()함수를 사용 ***

#include<stdio.h>
#include<windows.h>

void gotoxy(int x, int y) {
    COORD Pos = { x - 1, y - 1 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void main() {
    int x = 1;
    int y = 1;
    gotoxy(x, y);
    while (1) {
        if (GetAsyncKeyState(VK_LEFT) & 0x8000) {   //왼쪽 // 가상 키 코드
            x--;
        }
        if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {  //오른쪽
            x++;
        }
        if (GetAsyncKeyState(VK_UP) & 0x8000) {     //위
            y--;
        }
        if (GetAsyncKeyState(VK_DOWN) & 0x8000) {   //아래
            y++;
        }

        system("cls");
        gotoxy(x, y);
        printf("♥");
    }
}

//GetAsyncKeyState와 GetKeyState의 차이점
// 
//GetAsyncKeyState()함수는 비동기로 처리합니다. 
//즉, 호출된 시점에서 키 상태를 조사하여, 메시지 큐를 거치지 않고 바로 리턴해주므로 
//키 입력을 바로 처리해 줄 수 있습니다.

//GetAsyncKeyState의 반환값
//0(0x0000)	이전에 누른 적이 없고 호출 시점에서 안눌린 상태
//  0x8000 	이전에 누른 적이 없고 호출 시점에서 눌린 상태
//  0x8001 	이전에 누른 적이 있고 호출 시점에서 눌린 상태
//1(0x0001)	이전에 누른 적이 있고 호출 시점에서 안눌린 상태

//if (GetAsyncKeyState(VK_LEFT) & 0x8000) ->지금 키가 눌림
//if (GetAsyncKeyState(VK_LEFT) & 0x0001) ->이전과 지금 사이에 키가 눌림
//if (GetAsyncKeyState(VK_LEFT)) ->둘다 가능

//대부분의 게임은 현재 눌린키값이 무엇인지가 중요하고 이전에 눌린 키의 값은 중요하지 않습니다.
//GetKeyState()함수를 사용할 시 메시지 큐에 처리되지 않은 키값이 남아있다면 키가 눌렸다고 인식이 되므로 
//GetAsyncKeyState함수를 사용하는것이 불필요한 오류를 예방할 수 있습니다.