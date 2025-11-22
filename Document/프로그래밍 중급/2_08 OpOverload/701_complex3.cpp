// 연산자 정의하기     // +(더하기) -(빼기) -(음수) 

#include <iostream> 
using namespace std;

class Complex
{
private:
    int real;
    int image;
public:
    Complex(int r = 0, int i = 0);
    void ShowComplex();

    Complex operator+(Complex rightHand);           //연산자 정의
    Complex operator-(const Complex& rightHand) const;
    Complex operator-() const;
};

void Complex::ShowComplex()
{
    if (image > 0)      cout << "(" << real << "+" << image << "i)" << endl;
    else if (image < 0) cout << "(" << real << image << "i)" << endl;
    else                cout << real << endl;
}

Complex::Complex(int r, int i)
{
    real = r;
    image = i;
}

Complex Complex::operator+(Complex rightHand)
{
    Complex res;
    res.real = this->real + rightHand.real;
    res.image = this->image + rightHand.image;
    return res;
}

Complex Complex::operator-(const Complex& rightHand) const
{
    Complex res;
    res.real = this->real - rightHand.real;
    res.image = this->image - rightHand.image;
    return res;
}

Complex Complex::operator-() const
{
    Complex res;
    res.real = -real;
    res.image = -image;
    return res;
}

void main()
{
    Complex x(10, 20), y(20, 40), z;

    cout << "-- 두 Complex 객체에 대한 덧셈 --\n";
    z = x + y;
    x.ShowComplex();
    y.ShowComplex();
    z.ShowComplex();

    cout << "\n-- 두 Complex 객체에 대한 뺄셈 --\n";
    z = x - y;
    x.ShowComplex();
    y.ShowComplex();
    z.ShowComplex();

    cout << "\n-- Complex 객체의 부호 변경 --\n";
    z = -x;
    x.ShowComplex();
    z.ShowComplex();
}