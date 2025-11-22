//-----------------------------------------------------------------
//문제 1. 출력 결과를 고르세요.

#include <iostream>
using namespace std;

void func() {
    static int count = 0;
    count++;
    cout << count << " ";
}
int main() {
    for (int i = 0; i < 3; ++i) { func(); }
    return 0;
}

A. 1 1 1
B. 1 2 3
C. 0 1 2
D.컴파일 오류

정답 : B. 1 2 3

//-----------------------------------------------------------------
//문제 2. 출력 결과를 고르세요.

#include <iostream>
using namespace std;

class MyClass {
    static int x;
public:
    void setX(int val) { x = val; }
    void printX() { cout << x << endl; }
};

int MyClass::x = 0;

int main() {
    MyClass a, b;
    a.setX(5);
    b.printX();
    return 0;
}

보기:
A. 0
B. 5
C.컴파일 오류
D.정의되지 않음

정답 : B. 5


//-----------------------------------------------------------------
문제 3. 다음 중 static의 특징이 아닌 것은 ?
A.클래스의 모든 객체가 공유함
B.객체가 삭제되면 소멸함
C.객체 없이 접근할 수 있음
D.전역 변수처럼 한 번만 초기화됨

정답 : B.객체가 삭제되면 소멸함
프로그램 종료 시까지 유지됩니다.

//-----------------------------------------------------------------
//문제 1. 다음 코드의 출력 결과는 ?

#include <iostream>
using namespace std;

class Test {
public:
    static int count;
    Test() { count++; }
};

int Test::count = 0;

int main() {
    Test a, b, c;
    cout << Test::count << endl;
    return 0;
}
보기:

A. 0
B. 1
C. 3
D.컴파일 오류

정답 : C. 3

//-----------------------------------------------------------------
//문제 2. 다음 중 올바른 static 멤버 사용 방법은 ?

class A {
    static int x;
public:
    static void setX(int val);
    void printX();
};

A.x는 객체를 통해서만 접근 가능하다.
B. static 함수는 일반 멤버 변수에 접근할 수 있다.
C.setX()는 객체 없이 호출할 수 있다.
D.printX()는 정적 멤버 변수에 접근할 수 없다.

정답: C.setX()는 객체 없이 호출할 수 있다.

//-----------------------------------------------------------------
//문제 3. 다음 코드의 출력 결과는 ?

#include <iostream>
using namespace std;

class MyClass {
    static int x;
public:
    MyClass() { x += 10; }
    void show() const { cout << x << endl; }
};

int MyClass::x = 0;

int main() {
    MyClass obj1;
    MyClass obj2;
    obj1.show();
    obj2.show();
    return 0;
}

A. 10 10
B. 10 20
C. 20 20
D.컴파일 오류

정답 : C. 20 20

//-----------------------------------------------------------------

문제 4. 다음 중 정적 멤버 변수에 대한 설명으로 옳지 않은 것은 ?
A.클래스 외부에서 정의해야 한다.
B.클래스 내부에서 초기화할 수 없다(C++17 이전 기준).
C.모든 객체가 동일한 변수 하나를 공유한다.
D.객체마다 별도로 생성된다.

정답 : D.객체마다 별도로 생성된다.

해설 :
    정적 멤버 변수는 클래스 단위로 한 번만 생성되며, 모든 인스턴스가 공유합니다.

    
//-----------------------------------------------------------------
//문제 1. 다음 코드의 출력 결과는 ?

#include <iostream>
    using namespace std;

class Counter {
    static int count;
public:
    Counter() { ++count; }
    ~Counter() { --count; }
    static void showCount() { cout << count << endl; }
};

int Counter::count = 0;

void createObjects() {
    Counter a, b;
    Counter::showCount();
}

int main() {
    Counter::showCount();
    createObjects();
    Counter::showCount();
    return 0;
}
보기:

A. 0 2 2
B. 0 2 0
C. 0 0 0
D.컴파일 오류

정답 : B. 0 2 0

//-----------------------------------------------------------------
//문제 2. 다음 코드에서 오류가 발생하는 위치는 (C++14) ?

#include <iostream>
using namespace std;

class Example {
    static int value = 10;
public:
    static void print() { cout << value << endl; }
};

int main() {
    Example::print();
    return 0;
}

A. static int value = 10;
B.print() 함수
C.main() 함수
D.오류 없음

정답 : A. static int value = 10;
    해결책은 클래스 외부에서 다음과 같이 초기화하는 것입니다 
    inline static 변수는 헤더 파일에서 선언과 정의를 동시에 할 수 있도록 만들어졌습니다.
    C++17부터 가능해졌으며, 외부 정의 없이 사용할 수 있습니다.

//-----------------------------------------------------------------
//문제 4. 다음 중 C++17 이후에 가능한 문법은 ?

A.클래스 내부에서 정적 멤버 변수를 inline static으로 초기화
B.정적 멤버 함수를 오버라이딩
C.정적 멤버 변수에 this 포인터 접근
D.정적 멤버 함수를 virtual로 선언


정답 : A.클래스 내부에서 정적 멤버 변수를 inline static으로 초기화
해설 :
    B는 정적 함수는 virtual이 될 수 없으므로 오버라이딩 불가
    C는 this는 객체 인스턴스를 나타내므로 static에서 접근 불가
    D는 static과 virtual은 동시에 사용 불가