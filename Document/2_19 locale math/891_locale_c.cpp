// C 로 한글 입력받기, 출력하기 --------------------------------------

#include <stdio.h>       
#define MAX_LENGTH    32        

int GetStringLength(const char* ap_string)          
{    
    int count = 0;          // 문자의 개수를 저장할 변수!
        
    while (*ap_string) {    // 문자열의 끝에 있는 'NULL 문자'가 나올때까지 반복한다.
        if (*ap_string >> 7) ap_string++;  // 현재 문자가 한글이면 1바이트 더 증가시켜야 함! //한글 문자는 최상위 비트(MSB, 7번 비트)가 1로 구성
        ap_string++;
        count++;            // 문자의 개수를 계산한다.
    }    
    return count;           // 계산된 문자의 개수를 반환한다.
}

void PrintString(const char* ap_string)
{
    while (*ap_string) {        // 문자열의 끝에 있는 'NULL 문자'가 나올때까지 반복한다.
        if (*ap_string >> 7) {  // 한글은 2바이트씩 사용, 한글인 경우에는 문자 2개를 한번에 출력!
            printf("%c%c\n", *ap_string, *(ap_string + 1));
            ap_string += 2;
        }
        else printf("%c\n", *ap_string++); // 영문은 그대로 출력!
    }
}

int main()
{
    char str[MAX_LENGTH];
    int len;

    printf("Input : ");         // 사용자에게 공백 문자를 포함한 문자열을 입력받는다!        
    scanf_s("%[^\n]s", str, MAX_LENGTH);

    len = GetStringLength(str);
    printf("length : %d\n", len);

    PrintString(str);

    return 0;
}