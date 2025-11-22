// =	// 대입연산자 정의하기  // 복사 대입 연산자 (복사 생성자를 참고하세요)

#include <iostream>
using namespace std;

class CMyData
{
private:
	int data = 0;
public:
	//변환 생성자
	CMyData(int nParam) : data(nParam) {
		cout << "CMyData(int)" << endl;
	}
/*
	//복사 생성자
	CMyData(const CMyData& rhs) : m_nData(rhs.m_nData) {
		cout << "CMyData(const CMyData &)" << endl;
	}
	//이동 생성자
	CMyData(CMyData&& rhs) noexcept : m_nData(rhs.m_nData) {
		cout << "CMyData(CMyData &&)" << endl;
	}

	//형식변환  
	operator int() { return m_nData; }		//변환 함수
*/

	// +	// CMyData 리턴
	CMyData operator+(const CMyData& rhs)
	{
		//cout << "operator+" << endl;
		CMyData result(0);
		result.data = this->data + rhs.data;
		return result;
	}

	// =	// 대입연산자 정의하기	// CMyData& 리턴
	CMyData& operator=(const CMyData& rhs)
	{
		//cout << "operator=" << endl;
		data = rhs.data;
		return *this;
	}
};

int main()
{
	CMyData a(0), b(3), c(4);

	a = b + c;	// 연산을 수행하면 이름 없는 임시 객체가 만들어지며 a에 대입하는 것은 이 임시객체다.
	
	//a.operator=(b.operator+(c));

	cout << a << endl;


	a = b;		// = 연산자 정의 없이도 실행됨 이유는?   //자동으로 생성되는 '특수 맴버함수'

	return 0;
}
