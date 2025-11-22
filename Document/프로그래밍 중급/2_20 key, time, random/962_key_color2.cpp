#include <Windows.h>
#include <stdio.h>

enum ConsoleColor {
    CC_BLACK,
    CC_DARKBLUE,
    CC_DARKGREEN,
    CC_DARKCYAN,
    CC_DARKRED,
    CC_DARKMAGENTA,
    CC_DARKYELLOW,
    CC_GRAY,
    CC_DARKGRAY,
    CC_BLUE,
    CC_GREEN,
    CC_CYAN,
    CC_RED,
    CC_MAGENTA,
    CC_YELLOW,
    CC_WHITE,
    CC_LIGHTGRAY = 7,
    CC_ORIGINAL = 7,
    CC_ORIGINALFONT = 7,
    CC_ORIGINALBG = 0
};

//텍스트, 배경 색상 SET
void setColor(int color, int bgcolor)
{
    color &= 0xf;
    bgcolor &= 0xf;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4) | color);
}

//폰트 색상 SET
void setFontColor(int color)
{
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        (buff.wAttributes & 0xf0) | (color & 0xf));
}

//배경 색상 SET
void setBgColor(int bgcolor) {
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
        ((bgcolor & 0xf) << 4) | (buff.wAttributes & 0xf));
}

//텍스트 색상 GET
int getFontColor() {
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    return buff.wAttributes & 0xf;
}

//배경 색상 GET
int getBgColor() {
    CONSOLE_SCREEN_BUFFER_INFO buff;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buff);
    return (buff.wAttributes & 0xf0) >> 4;
}

//텍스트, 배경색 Default
__inline void initColor() {  setColor(7, 0); }

//텍스트 색상 Default
__inline void initFontColor() { setFontColor(7); }

//배경 색상 Default
__inline void initBgColor() { setBgColor(0); }

void main()
{
    int i, j;
    printf("\r\n");
    printf("   0 1 2 3 4 5 6 7 8 9101112131415\n");

    for (j = 0; j < 16; j++) 
    {
        initColor();
        printf(" %2d", j);
        setBgColor(j);
        for (i = 0; i < 16; i++) {
            setFontColor(i);
            printf("♥");
        }
        printf("\n");
    }
    initColor();
}
