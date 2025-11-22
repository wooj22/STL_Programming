//객체를 배열처럼 사용하기 //배열 연산자 [] 정의하기 --------------------------------------------------

#include <iostream>
using namespace std;

class CIntArray
{
private:
	int*	m_pData;		//배열 메모리
	int		m_nSize;		//배열 요소의 개수
public:
	CIntArray(int nSize)
	{
		m_pData = new int[nSize];			//전달된 개수만큼 int자료를 담을 수 있는 메모리를 확보한다.
		memset(m_pData, 0, sizeof(int) * nSize);
	}
	~CIntArray() { delete m_pData; }

	int& operator[] (int nIndex)			//일반적인 배열 연산자
	{
		//cout << "operator[]" << endl;
		return m_pData[nIndex];
	}
	int operator[] (int nIndex) const		//상수형 참조인 경우의 배열 언산자
	{
		//cout << "operator[] const" << endl;
		return m_pData[nIndex];
	}
};

//사용자 코드
void TestFunc(const CIntArray& arParam)
{
	//cout << "TestFunc()" << endl;
	cout << arParam[3] << endl;		//상수형 참조이므로 'operator[] (int nIndex) const'를 호출한다.
}

int main()
{
	CIntArray arr(5);
	cout << arr.m_pData[0] << endl;	//

	int n = arr[0]					//1. 객체를 배열처럼 사용한다. //[] 연산자가 필요하다.			
	arr[0] = 10;					//2. 객체 리턴 - int&

	
	for (int i = 0; i < 5; ++i)	arr[i] = i * 10;
	TestFunc(arr);					//3. 함수에 전달

	return 0;
}

