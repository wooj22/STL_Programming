//중첩클래스를 사용하는 이유는 
// 
//      class의 private에 별다른 제약없이 접근할 수 있기 때문
// 
//      클래스간 공유하는 필요한 로직이나 값이 외부에 노출되지 않고 내부에서만 처리하기 때문에 
//      효율적인 정적 데이타 은닉과 기능의 캡슐화가 가능

//연습)
// 
// 정수를 관리하는 클래스 - add, sum ,show 등의 기능
// 
// 정수 '연산', '출력 UI' 를 관리하는 클래스를 만들어 사용하기

#include <iostream>
using namespace std;

class Int
{
    int num = 0;

    struct Int_op {
        void add(Int& a) { a.num++; }           //맴버 사용
        void sub(Int& a) { a.num--; }
    };

    struct Int_ui {
        void show(const Int& a) { cout << a.num << endl; }
    };

public:
    void Add() { Int_op a; a.add(*this); }      //내부에서 사용 *this
    void Show() { Int_ui a; a.show(*this); }
};

int main()
{
    Int a;          //메인에서는 일반 클래스처럼 사용
    a.Add();
    a.Show();
}