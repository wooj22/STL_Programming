// 연산자 오버로딩  활용 // 함수 호출 연산자인 () 오버로딩 

//---------------------------------------------------------------------
//연습 // IsLargerThan 클래스 만들기

#include <iostream>
using namespace std;

class IsLargerThan
{
public:
	IsLargerThan(int value) : m_value{ value } {}

	bool operator()(int val) const {
		return m_value > val;
	}
private:
	int m_value;
};
int main()
{
	IsLargerThan one(1);

	cout << one(3) << endl;						//false
	//cout << one.operator()(3) << endl;			//같은 표현


	cout << IsLargerThan(5)(3) << endl;			//true

	return 0;
}

//---------------------------------------------------------------------
//다음 함수를 함수객체로 만드세요.
//		print_add_number(3, 5);

#include <iostream>
using namespace std;

void print_add_number(int a, int b)
{
	std::cout << a + b << std::endl;
}

/*
	struct PrintAddNumber {
		void operator()(int a, int b) { std::cout << a + b << std::endl; }
	};

	int main()
	{
		PrintAddNumber print_add_number;
		print_add_number(3, 5);

		//PrintAddNumber()(3, 5);
	}
*/

//inline bool operator<(const Message& lhs, const Message& rhs) { return rhs > lhs; }
//inline bool operator>(const Message& lhs, const Message& rhs) { return rhs < lhs; }// 
//inline bool operator<=(const Message& lhs, const Message& rhs) { return !(rhs < lhs); }
//inline bool operator>=(const Message& lhs, const Message& rhs) { return !(lhs > rhs); }
