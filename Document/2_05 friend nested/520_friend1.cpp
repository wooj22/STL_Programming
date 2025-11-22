//다른 클래스의 private 맴버에 접근하는 방법

// 프렌드 함수 선언하기 ***

// 프렌드 함수(friend function)는 
//      C++에서 특정 클래스의 멤버 함수가 아니면서도, 
//      해당 클래스의 private 또는 protected 멤버 변수와 함수에 
//      직접 접근할 수 있도록 허용된 외부 함수를 의미합니다

#include <iostream> 
using namespace std;
class Complex
{
private:
    int real;
    int image;
public:
    Complex(int r = 0, int I = 0);
    void Show() const;

    //friend Complex printAdd(Complex& c1, Complex& c2);
    //friend void printArr(Complex *pCom);
};

Complex::Complex(int r, int i) : real(r), image(i) {
}

void Complex::Show() const {
    cout << "( " << real << " + " << image << "i )" << endl;
}
/*
Complex printAdd(Complex& c1, Complex& c2)
{
    Complex obj (c1.real + c2.real, c1.image + c2.image);   //private 맴버접근
    return obj;
}

void printArr(Complex* pCom)
{
    for (int i = 0; i < 4; i++)
        pCom[i].Show();
}
*/
void main()
{
    Complex x(1, 1);
    Complex y(2, 1);

    Complex z = printAdd(x, y); //프렌드 함수로 정의하세요
    z.Show();


    Complex arr[4] = {
         Complex(2, 4),
         Complex(4, 8),
         Complex(8, 16),
         Complex(16, 32),
    };

    printArr(arr);  //프렌드 함수로 정의하세요
}



//프렌드 함수는 다음과 같은 상황에서 주로 사용됩니다.
// 
//  외부 함수가 클래스의 내부 데이터를 직접 참조해야 할 때
//  두 개 이상의 클래스가 서로의 private 멤버에 접근해야 할 때(예: 연산자 오버로딩, 두 클래스의 데이터 합산 등)
//  클래스의 멤버 함수로 정의하기에는 부적합하지만, 클래스의 내부 데이터에 접근해야 하는 경우

//프렌드 함수의 특징
//
//  클래스의 멤버 함수가 아니므로, 객체 없이 호출할 수 있음
//  클래스의 private, protected 멤버에 접근 가능
//  friend 선언은 클래스 내부 어디서든 가능
//  friend로 지정된 함수만 접근 권한을 가지며, 상호적(friend의 friend)이나 상속되지 않음
//  과도한 사용은 캡슐화(정보 은닉) 원칙을 해칠 수 있으므로 주의 필요