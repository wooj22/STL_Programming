// Complex 를 이용한 예제

//선행연산, 후행연산 // 맴버함수로 operator 구현하기

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

	Complex& operator++()		// Prefix
	{
		++this->real;
		++this->image;
		return *this;
	}
	Complex operator++(int)		// Postfix
	{
		Complex temp = *this;
		++this->real;
		++this->image;
		return temp;
	}

};

Complex::Complex(int r, int i) { real = r;	image = i; }

void Complex::ShowComplex() { cout << "( " << real << " + " << image << "i )" << endl; }

void main()
{
	Complex x(10, 20);
	Complex z;

	cout << "---- 선행처리 ----\n";
	z = ++x;
	x.ShowComplex();
	z.ShowComplex();

	cout << "---- 후행처리 ----\n";
	z = x++;
	x.ShowComplex();
	z.ShowComplex();
}

//선행연산, 후행연산 // 전역함수로 operator 구현하기

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

	friend Complex& operator++(Complex& obj);
	friend Complex operator++(Complex& obj, int);
};

Complex::Complex(int r, int i) { real = r;	image = i; }

void Complex::ShowComplex() { cout << "( " << real << " + " << image << "i )" << endl; }

Complex& operator++(Complex& obj)		// Prefix
{
	++obj.real;
	++obj.image;
	return obj;
}
Complex operator++(Complex& obj, int)	// Postfix
{
	Complex temp;
	temp = obj;
	++obj.real;
	++obj.image;
	return temp;
}

void main()
{
	Complex x(10, 20);
	Complex z;

	cout << "---- 선행처리 ----\n";
	z = ++x;
	x.ShowComplex();
	z.ShowComplex();

	cout << "---- 후행처리 ----\n";
	z = x++;
	x.ShowComplex();
	z.ShowComplex();
}
