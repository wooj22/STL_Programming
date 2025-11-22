//복사 생성자는 
// 복사 생성자가 명시적으로 선언되어 있지 않은 클래스에 대해서만 자동 작성
// 이동 연산이 하나라도 선언되어 있으면 삭제

#include <iostream>
using namespace std;

class Test {
public:
    Test() {}
    Test(Test&&) {}     // 이동 선언의 경우
    //~Test() {}        // 소멸자 선언의 경우
};

int main()
{
    Test t1;
    Test t2(t1);        //복사 생성 error
    t2 = t1;            //복사 연산error
}
