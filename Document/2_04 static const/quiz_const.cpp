
//const 객체 : const MyClass obj; 와 같이 선언하면 해당 객체는 멤버 함수를 const 함수만 호출 가능
//const 멤버 함수 : void func() const; → 해당 함수 내부에서 멤버 변수 변경 불가
//mutable 키워드 : mutable int x; → const 함수에서도 해당 변수는 변경 가능
//const와 참조/포인터 : 객체를 const로 참조하면, 해당 참조자는 그 객체의 const 멤버만 접근 가능

//-----------------------------------------------------------------
//문제. 다음 코드에서 컴파일 오류가 나는 부분은 ?

class A {
    int x;                               //1
public:
    A(int val) : x(val) {}               //2
    int get() const { return x; }        //3
    void set(int val) const { x = val; } //4
};

//정답) 4 멤버 변수를 바꾸려면 const 함수면 안됨


//-----------------------------------------------------------------
//문제. 다음 중 모두 const에 대한 설명으로 옳은 것은 ?

1. const int* p는 포인터가 가리키는 값을 바꿀 수 없다.
2. int* const p는 포인터의 주소를 바꿀 수 없다.
3. const 멤버 함수는 멤버 변수를 수정할 수 있다.
4. const는 참조자에도 사용할 수 있다.

//정답 : 1, 2, 4
//3번은 틀림(const 함수는 멤버 변수 변경 불가)

//-----------------------------------------------------------------
//이 코드가 출력하는 결과는 ? 그리고 왜 가능한가 ?

#include <iostream>
using namespace std;

class Logger {
    mutable int count;
public:
    Logger() : count(0) {}
    void log() const {
        ++count;
        cout << "Logging " << count << " times" << endl;
    }
};

int main() {
    const Logger logger;
    logger.log(); // (1)
    logger.log(); // (2)
    return 0;
}

//호출이 가능,mutable이므로 const 함수 내부에서 변경 가능.

//-----------------------------------------------------------------
//(1) 줄에서 어떤 함수가 호출되는가 ? 출력은 ?

#include <iostream>
using namespace std;

class A {
public:
    void print() { cout << "non-const print\n"; }
    void print() const { cout << "const print\n"; }
};

void call(const A& a) {
    a.print(); // (1)
}

int main() {
    A obj;
    call(obj);
    return 0;
}

//a는 상수 참조 → const 멤버 함수만 호출 가능. 따라서 print() const 함수가 호출됨.
 
//-----------------------------------------------------------------
// 아래 코드를 보고 답하세요.

int main()
{
    int x = 5;
    int y = 10;

    const int* a = &x;      
    int* const b = &x;      
    const int* const c = &x;

    //아래 설명 중 옳은 것을 모두 고르세요.
    *a = 20;    //1
    a = &y;     //2
    *b = 20;    //3
    b = &y;     //4
    *c = 30;    //5
    c = &y;     //6
}

//정답: 2, 3

//-----------------------------------------------------------------
// 문제 // 아래코드에서 에러가 발생하는 이유는?

#include <iostream>
using namespace std;

class Foo
{
    int bar;
public:
    int& Get() const { return bar; }	//error 이유는?
};

int main(void)
{
    return 0;
}

//레퍼런스를 리턴하면 
//   클래스의 내부 상태(bar 멤버 변수)를 바꾸지 않는다는 것(const)을 보장할 수 없기 때문이다. 
//	 따라서 const를 빼던가, 리턴 타입에 const를 추가해야 한다