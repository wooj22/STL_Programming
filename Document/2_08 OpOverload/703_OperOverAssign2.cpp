// 대입 연산자 오버로딩  //맴버가 포인터인 경우

#include <iostream>
using namespace std;

//제작자 코드
class CMyData
{
private:
	int* m_pData = nullptr;

public:
	CMyData(int nParam) { m_pData = new int(nParam);	}

	~CMyData() { delete m_pData; }

	operator int() { return *m_pData; }

	//단순 대입 연산자 오버로딩
	CMyData& operator = (const CMyData& rhs)
	{		
		if (this == &rhs) return *this;			//r-value가 자신이면 대입을 수행하지 않는다.

		delete m_pData;						//기존 값 삭제
		m_pData = new int(*rhs.m_pData);
		return *this;
	}

	//+= 대입 연산자 오버로딩
	CMyData& operator += (const CMyData& rhs)
	{		
		int* pNewData = new int(*m_pData);	//현재 값 처리
		*pNewData += *rhs.m_pData;			//누적할 값 처리

		//기존 데이터를 삭제하고 새 메모리로 대체
		delete m_pData;
		m_pData = pNewData;
		return *this;
	}

};

//사용자 코드
int main()
{
	CMyData a(0), b(5), c(10);
	a += b;
	a += c;
	cout << a << endl;
	return 0;
}

