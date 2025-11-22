//정리) 함수와 const --------------------------------------------------------------------

#include<iostream>
using namespace std;


//함수 앞에 붙은 const
//		함수 앞에 붙은 const는 함수의 리턴값을 상수화 시키겠다는 의미
//		반환된 값을 변경하지 못하도록 하기 위해서 사용된다.

      int  F1(const int& n) { return n; } //값으로 반환, rvalue
      int& F2(const int& n) { return n; } //변수 그대로 반환, lvalue
const int& F3(const int& n) { return n; } //변수를 const 로 반환, const lvalue


//함수의 매개변수 const
//		매개변수의 const는 상수나 변수를 받아서 변경하지 않고 쓰겠다는 의미
//		매개변수의 값을 변경하지 않고 사용할 때 사용된다.

int F4(      int& n) { return n; }	//상수를 받을수 없다.
int F5(const int& n) { return n; }	//상수,변수 모두 전달 가능.	


//함수 뒤에 붙은 const
//		const 맴버 함수,	맴버 데이타를 변경하지 않겠다는 의미
//		상수 객체는 non-const 맴버 함수를 호출할 수 없다.

class  A {
    int n = 0;
public:
          A& Add1(int n) { n++;  return *this; }
    const A& Add2(int n) const { n++; return *this; }
};

int main(void) 
{
    A a;
    a.Add1(1);
    a.Add2(1);

    a.Add1(1).Add2(1);
    a.Add2(1).Add1(1);      //error

    const A b;
    b.Add1(1);      //error
    b.Add2(1);

    return 0;
}
​