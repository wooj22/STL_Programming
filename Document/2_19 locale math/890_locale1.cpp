#include <iostream>
#include <locale>           //유니코드
using namespace std;

int main()
{
    //아스키코드에서는 한글 문자열을 지원하지 않는다. ----------------------------------

    const char* str1 = "ab가나";
    cout << str1[0] << "\n";
    cout << str1[1] << "\n";
    cout << str1[2] << "\n";
    cout << str1[3] << "\n";
    cout << strlen(str1) << endl;
    cout << endl;

    //유니코드(Wide Byte Character Set) - 2바이트 -----------------------------------
    //문자열의 자료형으로는 wchar_t을 사용하고, 사용법은 문자열 앞에 L을 붙이면 된다.

    setlocale(LC_ALL, "ko-KR");         //Korean

    const wchar_t* str2 = L"ab가나";    //문자열 앞에 L

    wcout << str2[0] << "\n";
    wcout << str2[1] << "\n";
    wcout << str2[2] << "\n";
    wcout << str2[3] << "\n";
    wcout << wcslen(str2) << endl;
}

//한글 문자는 최상위 비트(MSB, 7번 비트)가 1로 구성

// LC_ALL //언어, 국가/지역 코드 및 코드 페이지로 사용 

//Country/Region Strings //국가 지역 문자열

