//인터페이스 클래스
//      모든 함수가 순수 가상 함수인 클래스.본인만의 멤버 변수는 가지지 않는다.
//      설계도 같은 역할, 인터페이스는 순수 가상 함수만 가지고 있다.
//      대문자 I를 붙여주는게 관습이다.
//      인터페이스를 상속 받는 클래스들은 반드시 인터페이스 안에 있는 모든 함수들을 전부 오버라이딩 해야 한다.

#include <iostream>
using namespace std;

class IClass abstract  //인터페이스 클래스
{
public:
    virtual ~IClass() {};
    virtual void draw() abstract;
};

class CClass : IClass
{
public:
    ~CClass() { cout << "~CClass()" << endl; }
    void draw() { }
};

int main()
{
    CClass c;

    return 0;
}


/*
//인터페이스 클래스 ----------------------------

#include <iostream>
using namespace std;

class IErrorLog
{
public:
    virtual bool reportError(const char* error) = 0;
    virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        cout << "Writing error to a file" << endl;
        return true;
    }
};

class ConsoleErrorLog : public IErrorLog
{
public:
    bool reportError(const char* errorMessage) override
    {
        cout << "Printing error to a console" << endl;
        return true;
    }
};

void doSomething(IErrorLog& log)
{
    log.reportError("Runtime error!!");
}

int main()
{
    FileErrorLog file_log;
    ConsoleErrorLog console_log;

    doSomething(file_log);   // ⭐다형성
    doSomething(console_log); // ⭐다형성
}

*/