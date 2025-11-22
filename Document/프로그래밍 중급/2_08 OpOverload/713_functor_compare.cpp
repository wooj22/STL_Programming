// 연산자 오버로드 연습  // 비교연산자 // 함수객체

// 비교연산자 == != < > <= >= 를 정의하세요.

#include <iostream>

class Cents
{
	int num;

public:
	Cents(int cents = 0) { num = cents; }

	bool operator == (Cents& c) { return (num == c.num); }		//

	bool operator != (Cents& c) { return (num != c.num); }		//

	friend std::ostream& operator << (std::ostream& out, const Cents& cents)
	{
		out << cents.num;
		return (out);
	}
};

int main()
{
	using namespace std;

	Cents    c1{ 6 };
	Cents    c2{ 6 };
	Cents    c3{ 0 };

	cout << std::boolalpha;
	cout << (c1 == c2) << endl;
	cout << (c1 != c2) << endl;
	cout << (c1 == c3) << endl;
	cout << (c1 != c3) << endl;
}

//inline bool operator<(const Cents& lhs, const Cents& rhs) { return rhs > lhs; }
//inline bool operator>(const Cents& lhs, const Cents& rhs) { return rhs < lhs; } 
//inline bool operator<=(const Cents& lhs, const Cents& rhs) { return !(rhs < lhs); }
//inline bool operator>=(const Cents& lhs, const Cents& rhs) { return !(lhs > rhs); }


// Cents 객체를 비교연산을 하는 함수객체를 만들어 보세요. ----------------------

#include <iostream>
using namespace std;

class Cents
{
	int    num;
public:
	Cents(int cents = 0) { num = cents; }
	bool operator < (Cents& c) { return (num < c.num); }
};

/*
class Less
{
private:
	Cents cents;
public:
	Less(Cents value) : cents{ value } {}

	bool operator()(Cents val) {
		return (cents < val) ;
	}
};
*/

int main()
{
	Cents c1(1);
	Cents c2(2);
	cout << (c1 < c2) << endl;						// < 연산자 필요

	cout << Less(Cents(1))(Cents(2)) << endl;		//출력은?  		true

	return 0;
}

