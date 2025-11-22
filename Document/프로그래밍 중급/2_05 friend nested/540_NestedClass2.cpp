//중첩 클래스
//      클래스는 다른 클래스의 범위 내에서 선언될 수 있다
//      중첩 클래스는 '바깥쪽 클래스'의 범위 내에 있는 것으로 간주되며, 해당 범위 내에서 사용할 수 있다.

//예시
https://learn.microsoft.com/ko-kr/cpp/cpp/nested-class-declarations?view=msvc-170

#include <iostream>
using namespace std;

class BufferedIO
{
public:
    enum IOError { None, Access, General };

    // Declare nested class BufferedInput.
    class BufferedInput
    {
    public:
        int read() { return(1); }
        int good() { return _inputerror == None; }
    private:
        IOError _inputerror;
    };

    // Declare nested class BufferedOutput.
    class BufferedOutput
    {
    };

    // BufferedIO 범위에서 사용가능
};

int main()
{
}


//중첩 클래스의 멤버 함수 ------------------------------------------------------------
// 
//    중첩 클래스에서 선언된 멤버 함수는 '파일 범위'에서 정의될 수 있습니다.
//    앞의 예제는 다음과 같이 작성될 수도 있습니다.

// member_functions_in_nested_classes.cpp
class BufferedIO
{
public:
    enum IOError { None, Access, General };

    class BufferedInput
    {
    public:
        int read();     // Declare but do not define member
        int good();     // functions read and good.
    private:
        IOError _inputerror;
    };

    class BufferedOutput
    {
        // Member list.
    };
};

// Define member functions read and good in file scope. //파일내에서 정의가능
int BufferedIO::BufferedInput::read() { return(1); }
int BufferedIO::BufferedInput::good() { return _inputerror == None; }

/*
//줄여 쓰기 // typedef

typedef BufferedIO::BufferedInput BIO_INPUT;
int BIO_INPUT::read()

*/
int main()
{
}


//----------------------------------------------------------------------
//중첩 클래스에 선언된 typedef
class C
{
public:
    typedef class U u_t;    // class U visible outside class C scope //선언의 범위에 대한 예외
    typedef class V {} v_t; // class V not visible outside class C
};

int main()
{
    // okay, forward declaration used above so file scope is used //접근됨 //파일 범위 ***
    U* pu;

    // error, type name only exists in class C scope
    u_t* pu2;       // C2065

    // error, class defined above so class C scope
    V* pv;          // C2065

    // okay, fully qualified name               //명시적 접근
    C::V* pv2;
}


//----------------------------------------------------------------------
//중첩 클래스에 선언된 friend 함수는 
//    바깥쪽 클래스가 아닌 중첩 클래스 범위에 있다고 간주됩니다.
//    따라서 내부 클래스 friend 함수는 
//    바깥쪽 클래스의 멤버 또는 멤버 함수에 대해 특별한 액세스 권한이 없습니다.

#include <iostream>
using namespace std;

class outer
{
    int n = 0;
    class inner						//enclose 내부에서 사용하겠다.
    {
        int m = 0;
        void func(outer o)	{ cout << o.n; }
        friend void ffunc(outer o) { cout << o.n; } //error
    };
};

int main() {
}
