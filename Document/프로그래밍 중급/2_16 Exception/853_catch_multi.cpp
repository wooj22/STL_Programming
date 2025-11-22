//다중 catch
//		catch 문 은 여러개 가능
try {
}
catch (int a) {
}
catch (string s) {
}

//catch (...)
//      다음과 같이 catch 블럭을 선언하면, 
//      try 블록 내에서 전달되는 모드 예외가 자료형에 상관없이 걸려든다.
//      따라서 마지막 catch 블록에 많이 덧붙여지지만, 발생한 예외에 관련해서 정보를 얻을 수 없다.

try
{
}
catch (...)
{
}


//여러 종류의 throw 된 객체를 모두 받을 수 있도록 처리해보세요

#include <iostream>
#include <string>

int func(int c) {
    if (c == 1) {
        throw 10;
    }
    else if (c == 2) { throw std::string("hi!"); }
    else if (c == 3) { throw 'a'; }
    else if (c == 4) { throw "hello!"; }
    return 0;
}

int main() {
    int c;
    std::cin >> c;
    func(c);
}

/*
int main() {
    int c;
    std::cin >> c;

    try {
        func(c);
    }
    catch (char x) {
        std::cout << "Char : " << x << std::endl;
    }
    catch (int x) {
        std::cout << "Int : " << x << std::endl;
    }
    catch (std::string& s) {
        std::cout << "String : " << s << std::endl;
    }
    catch (const char* s) {
        std::cout << "String Literal : " << s << std::endl;
    }
}
*/

// 모든 예외 받기 -----------------------------------------------------

#include <iostream>
#include <stdexcept>

int func(int c) {
    if (c == 1) { throw 1; }
    else if (c == 2) { throw "hi"; }
    else if (c == 3) { throw std::runtime_error("error"); }
    return 0;
}

int main() {
    int c;
    std::cin >> c;

    try {
        func(c);
    }
    catch (int e) {
        std::cout << "Catch int : " << e << std::endl;
    }
    catch (...) {
        std::cout << "Default Catch!" << std::endl;
    }
}


