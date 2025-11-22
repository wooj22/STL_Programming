// 이동 대입 연산자 오버로딩 (이동 생성자 참고)

#include <iostream>
using namespace std;

//제작자 코드
class CMyData
{
public:
	explicit CMyData(int nParam)					//explicit 명시적 형변환
	{
		cout << "CMyData(int)" << endl;
		m_pData = new int(nParam);					//m_pData 가 포인터인 경우
	}

	CMyData(const CMyData& rhs)
	{
		cout << "CMyData(const CMyData &)" << endl;
		m_pData = new int(*rhs.m_pData);
	}

	CMyData(CMyData&& rhs) noexcept
	{
		cout << "CMyData(CMyData&& rhs)" << endl;
		m_pData = rhs.m_pData;
		rhs.m_pData = nullptr;
	}

	~CMyData() { delete m_pData; }

	operator int() { return *m_pData; }

	//덧셈 연산자 오버로딩
	CMyData operator + (const CMyData& rhs)
	{		
		return CMyData(*m_pData + *rhs.m_pData); //호출자 함수에서 이름 없는 임시객체가 생성된다.
	}

	//단순 대입 연산자 오버로딩 --------------------------------------
	CMyData& operator = (const CMyData& rhs)
	{
		cout << "operator = " << endl;
		if (this == &rhs) return *this;

		delete m_pData;
		m_pData = new int(*rhs.m_pData);
		return *this;
	}

	//이동 대입 연산자 오버로딩 -------------------------------------
	CMyData& operator = (CMyData&& rhs)
	{
		cout << "operator = (Move)" << endl;
		//얕은 복사를 수행하고, 원본은 NULL로 초기화 한다.
		m_pData = rhs.m_pData;
		rhs.m_pData = nullptr;
		return *this;
	}

private:
	int* m_pData = nullptr;
};

//사용자 코드
int main()
{
	CMyData a(0), b(3), c(4);
	cout << "Before ----------" << endl;	
	a = b + c;								//이동 대입 연산자가 실행된다!
	cout << "After -----------" << endl;
	cout << a << endl;
	a = b;
	cout << a << endl;
	return 0;
}

