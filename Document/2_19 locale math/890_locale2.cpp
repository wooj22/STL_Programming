#include <iostream>
#include <string>
#include <locale>						//locale
using namespace std;

//와이드 문자열 리터럴 --------------------------------------

int main()
{
	wcout.imbue(locale("kor"));			//한국으로 지역 설정
	wcin.imbue(locale("kor"));
		
	wchar_t ch1[20] = L"안녕하세요.";    //접두어 L을 붙여준다
	wcout << ch1 << endl;

	wstring str1 = L"私の名前は홍길동です！.";
	wcout << str1 << endl;				//출력 wcout

	wchar_t ch2[20];				
	wcin.getline(ch2, 20);				//ch2[] 입력 wcin
	wcout << ch2 << endl;			

	wstring str2;
	getline(wcin, str2);				//wstring 입력 wcin
	wcout << str2 << endl;			

	return 0;
}