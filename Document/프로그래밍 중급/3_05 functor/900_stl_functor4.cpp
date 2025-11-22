//대소문자 구분 안하고 소트하기

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//사용자가 정의한 방식대로 정렬 //함수객체 만들기
struct compare {
    bool operator()(string a, string b) const {
        return _stricmp(a.c_str(), b.c_str()) < 0;  //_stricmp 대소문자 구분 안하고 비교.
    }
};

void main()
{
    vector<string> vs = { "STL","MFC","C/C++","pascal","Python","basic" };

    //sort(vs.begin(),vs.end());
    sort(vs.begin(), vs.end(), compare());     

    vector<string>::iterator it;
    for (it = vs.begin(); it != vs.end(); it++)
    {
        cout << *it << endl;
    }
}

/*
    //stricmp -------------------------------

    #include <stdio.h>
    #include <string.h>
    int main(void)
    {
        // Compare two strings as lowercase

        if (0 == stricmp("hello", "HELLO"))
            printf("The strings are equivalent.\n");
        else
            printf("The strings are not equivalent.\n");
        return 0;
    }

    strcmpi() — 대소문자를 구분하지 않고 스트링 비교
    strcoll() — 스트링 비교
    strcspn() — 첫 번째 문자 일치의 오프셋 찾기
    strdup() — 스트링 복제
    strncmp() — 스트링 비교
    strcasecmp() — 대소문자를 구분하지 않고 스트링 비교
    strncasecmp() — 대소문자를 구분하지 않고 스트링 비교
    strnicmp() — 대소문자를 구분하지 않고 서브스트링 비교
    wcscmp() — 와이드 문자 스트링 비교
    wcsncmp() — 와이드 문자 스트링 비교

*/