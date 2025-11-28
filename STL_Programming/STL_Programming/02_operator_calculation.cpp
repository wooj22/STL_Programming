/*
	[ 산술 연산자 재정의 ]

	단항 : +, -
	선후행 연산 : ++, ++, --, --
	산술연산 : +, -, +=, -=
	대입 연산 : = (복사대입생성자, 이동대입연산자 => 특수 멤버함수)
	비교 연산 : >, >=, <, <=, ==, !=
	
	>> 선행연산과 후행 연산의 구분은?
	   매개변수에 int를 쓰면 후행 연산으로 인식된다!
	 - 선행++ : Num& operator++(){}
	 - 후행++ : Num operator++(int){}
	   
	   선행 연산은 자기 자신을 return하고, 후행 연산은 변경 이전의 복사본을 return한다.
	   선행 : this 증가 → 증가된 값 반환 (Num&, 참조)
	   후행 : 복사본 저장 → this 증가 → 복사본 반환 (Num, 복사)
*/

#include <iostream>
using namespace std;

class Num
{
	int num = 0;
public:
	int Get() { return num; }
	void Set(int a) { num = a; }

	// + (부호)
	Num operator+()
	{
		Num temp;
		temp.num = abs(num);
		return temp;
	}
	
	// - (부호)
	Num operator-()
	{
		Num temp;
		temp.num = -num;
		return temp;
	}

	// 선행 ++
	Num& operator++()
	{
		this->num++;
		return *this;
	}
	
	// 후행 ++
	Num operator++(int)
	{
		Num temp = *this;
		this->num++;
		return temp;
	}

	// 선행 --
	Num& operator--()
	{
		this->num--;
		return *this;
	}

	// 후행 --
	Num operator--(int)
	{
		Num temp = *this;
		this->num--;
		return temp;
	}

	// +
	Num operator+(const Num& n)
	{
		Num temp;
		temp.num = this->num + n.num;
		return temp;
	}

	// -
	Num operator-(const Num& n)
	{
		Num temp;
		temp.num = this->num - n.num;
		return temp;
	}

	// +=
	void operator+=(const Num& n)
	{
		this->num += n.num;
	}

	// -=
	void operator-=(const Num& n)
	{
		this->num -= n.num;
	}

	// = (복사 대입 생성자)
	// 연쇄 대입을 위해 자신을 반환한다.
	Num& operator=(const Num& n)
	{
		if (this != &n) this->num = n.num;
		return *this;
	}

	// ==
	bool operator==(const Num& n)
	{
		return this->num == n.num;
	}

	// <<
	friend ostream& operator<<(ostream& os, const Num& n2)
	{
		os << n2.num;
		return os;
	}
};
