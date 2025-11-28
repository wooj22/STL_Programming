/*
    템플릿 클래스의 프렌드를 3가지로 분류할 수 있다.

    1. 템플릿이 아닌 프렌드
    2. 바운드 템플릿 프렌드
    3. 언바운드 템플릿 프렌드 

    이거 다시 보기
*/

#include <iostream>
using namespace std;

/*---------------------------------------------------------
  1. 비템플릿 프렌드 (Non-template friend)
    - 특정 "하나의 함수"만 friend가 됨
    - 템플릿 X, 타입에 따라 달라지지 않음
---------------------------------------------------------*/

void ShowNonTemplate(class NonTemplateFriend); // 미리 선언 필요

class NonTemplateFriend {
private:
    int age = 10;
public:
    friend void ShowNonTemplate(NonTemplateFriend);  // 고정된 하나의 함수만 friend
};

void ShowNonTemplate(NonTemplateFriend a) {
    cout << "[Non-template friend] age = " << a.age << endl;
}


/*---------------------------------------------------------
  2. 바운드 템플릿 프렌드 (Bound Template Friend)
    - 클래스 외부에 함수 템플릿을 선언해야 함
    - friend void ShowBound<>(ClassTemplate<TT>&);
    - 클래스의 T가 결정될 때, 해당 T에 맞는 ShowBound<T>()가 friend가 됨
---------------------------------------------------------*/

// 2-1. 먼저 함수 템플릿 선언 필요!
template <class T> void ShowBound(T&);

template <typename TT>
class BoundTemplateFriend {
private:
    TT age = 0;
public:
    BoundTemplateFriend(const TT& a) : age(a) {}

    // 여기서 <> 를 붙이는 것이 Bound의 핵심
    friend void ShowBound<>(BoundTemplateFriend<TT>&);
};

// 2-2. friend로 지정된 함수 템플릿 정의
template <class T>
void ShowBound(BoundTemplateFriend<T>& a) {
    cout << "[Bound template friend] age = " << a.age << endl;
}


/*---------------------------------------------------------
  3. 언바운드 템플릿 프렌드 (Unbound Template Friend)
    - 클래스 안에서 friend 템플릿을 선언
    - 모든 타입의 ShowUnbound<C>()가 모든 클래스 특수화의 friend가 됨
---------------------------------------------------------*/

template <typename TT>
class UnboundTemplateFriend {
private:
    TT age = 0;
public:
    UnboundTemplateFriend(const TT& a) : age(a) {}

    template<typename C>
    friend void ShowUnbound(C&);
};

// 3-2. friend 함수 템플릿 정의
template<class C>
void ShowUnbound(C& a) {
    cout << "[Unbound template friend] age = " << a.age << endl;
}



int main() {
    cout << "1. Non-template Friend \n";
    NonTemplateFriend nt;
    ShowNonTemplate(nt);

    cout << "\n2. Bound Template Friend\n";
    BoundTemplateFriend<int> b1(100);
    ShowBound(b1);           // OK (int 버전의 ShowBound만 friend)

    // BoundTemplateFriend<double> b2(3.14);
    // ShowBound(b2);        // error. double 버전은 friend 아님

    cout << "\n3. Unbound Template Friend\n";
    UnboundTemplateFriend<int> u1(777);
    UnboundTemplateFriend<double> u2(3.14);

    ShowUnbound(u1);         // OK — 모든 타입 가능
    ShowUnbound(u2);         // OK — double도 friend
}
