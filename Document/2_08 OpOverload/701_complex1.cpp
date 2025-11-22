// Complex 를 이용한 예제 
//		++ -- 연산자 기능 구현

//선행연산, 후행연산 // 맴버함수로 구현하기 -----------------------------------------------

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

	Complex AddOnePrefix();		// 맴버함수로 선언
	Complex AddOnePostfix();
};

Complex::Complex(int r, int i) { real = r;	image = i; }

void Complex::ShowComplex() {
	cout << "( " << real << " + " << image << "i )" << endl;
}

Complex Complex::AddOnePrefix()
{
	++this->real;
	++this->image;
	return *this;	//증가하고 리턴
}

Complex Complex::AddOnePostfix()
{
	Complex temp = *this; 
	++this->real;
	++this->image;
	return temp;	//증가하기 전 객체 리턴
}

void main()
{
	Complex x(10, 20), y(20, 40);
	Complex z;

	cout << "---- 선행처리 ----\n";
	z = x.AddOnePrefix();
	x.ShowComplex();
	z.ShowComplex();

	cout << "---- 후행처리 ----\n";
	z = y.AddOnePostfix();
	y.ShowComplex();
	z.ShowComplex();
}


//선행연산, 후행연산 //friend 함수로 구현 -----------------------------------------------

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
	friend Complex& AddOnePrefix(Complex& Operand); // friend함수로 선언
	friend Complex AddOnePostfix(Complex& Operand);
};

Complex::Complex(int r, int i) { real = r;	image = i; }

void Complex::ShowComplex() {
	cout << "( " << real << " + " << image << "i )" << endl;
}

Complex& AddOnePrefix(Complex& Operand)
{
	++Operand.real;
	++Operand.image;
	return Operand;
}

Complex AddOnePostfix(Complex& Operand)
{
	Complex temp;
	temp = Operand;
	++Operand.real;
	++Operand.image;
	return temp;
}

void main()
{
	Complex x(10, 20), y(20, 40);
	Complex z;

	cout << "---- 선행처리 ----\n";
	z = AddOnePrefix(x);
	x.ShowComplex();
	z.ShowComplex();

	cout << "---- 후행처리 ----\n";
	z = AddOnePostfix(y);
	y.ShowComplex();
	z.ShowComplex();
}