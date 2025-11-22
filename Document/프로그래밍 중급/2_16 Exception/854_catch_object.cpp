//사용자 정의 예외클래스 만들기

#include <iostream>
using namespace std;
class UserError
{
public:
    void func();
};

void UserError::func() { cout << "사용자 정의 예외" << endl; }

void main()
{
    try {
        throw UserError();
    }
    catch (UserError& ex) {
        cout << "사용자 정의 예외 발생에 대한 처리" << endl;
        ex.func();
    }
}

// 사용자 정의 예외 객체를 사용하여, 메세지를 담아 전달해보세요
/*
    class UserError
    {
        string msg;
    public:
        UserError(string m) { msg = m; }
        void func();
    };
    void UserError::func() { cout << msg << endl; }

    void main()
    {
        try {
            throw UserError("예외 발생");
        }
        catch (UserError& ex) {
            ex.func();
        }
    }
*/