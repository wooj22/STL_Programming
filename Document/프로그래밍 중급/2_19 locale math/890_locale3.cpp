//_tmain 함수는 
//   유니코드를 지원 하는 프로그램은 컴파일 시 wmain함수로 바뀌고 (main함수의 와이드 문자 버전)
//   유니코드를 지원 않는 프로그램은 컴파일 시 main 함수로 바뀐다

//#include <tchar.h> 필요하다.

#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <locale.h>

int _tmain()        // _t
{
    DWORD pid = GetCurrentProcessId();
    DWORD sid;

    printf_s("Process '%u', 가 Session '%u'에서 동작중\n", 1, 2);

    setlocale(LC_ALL, "");
    //setlocale(LC_ALL, "korean");

    if (ProcessIdToSessionId(pid, &sid))
    {
        _tprintf_s(_T("Process '%u', 가 Session '%u'에서 동작중\n"), pid, sid);
    }
    else
    {
        _tprintf_s(_T("세션 ID를 얻어올 수 없습니다."));
    }
    return 0;
}