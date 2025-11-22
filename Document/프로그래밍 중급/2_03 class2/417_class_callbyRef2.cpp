//값 복사와 참조를 구분하라

#include <iostream> 
using namespace std;

class Complex
{
private:
    int real;
    int image;
public:
    Complex(int r = 0, int i = 0) { real = r; image = i; }
    void Show() const;
    void Set(int r = 0, int i = 0);
};

void Complex::Show() const {
    cout << "( " << real << " + " << image << "i )" << endl;
}
void Complex::Set(int r, int i) {
    real = r; image = i;
}

Complex CopyComplex1(Complex des, Complex src) {
    des = src;
    return des;
}
Complex& CopyComplex2(Complex& des, const Complex& src) {
    des = src;
    return des;
}

void main()
{
    Complex x(10, 20);
    Complex y(30, 40);
    Complex z;

    z = x;              //클래스 객체 복사, 맴버 대 맴버 값 복사를 하는 것.
    z.Show();

    //값 복사와 참조를 구분하라 ------------------------------------------
    z = CopyComplex1(y, x);                 //값 복사
    //z = CopyComplex2(y, x);               //참조
    cout << " x => ";   x.Show();
    cout << " y => ";   y.Show();
    cout << " z => ";   z.Show();           //출력은???
}

