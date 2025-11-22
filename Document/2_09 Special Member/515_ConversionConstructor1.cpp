//분수를 나타내는 클래스, 변환 생성자 호출 예시 //명시적으로 호출되도록 수정하세요.

#include <iostream>
#include <cassert>
using namespace std;

class Fraction			//분수
{
private:
	int m_numerator;	//분자
	int m_denominator;	//분모

public:
	Fraction(int num = 0, int den = 1) : m_numerator(num), m_denominator(den)
	{
		assert(den != 0);
	}
	Fraction(const Fraction& fraction)
		:m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy constructor called" << endl;
	}
	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		out << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};
void doSomething(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	doSomething(7);			//

	return 0;
}