//배열을 객체로 사용하기

#include <iostream>
using namespace std;

//제작자 코드
class CIntArray
{
private:
	int* m_pnData;		//배열 메모리
	int m_nSize;		//배열 요소의 개수
public:
	CIntArray(int nSize)
	{
		m_pnData = new int[nSize];			//전달 된 개수만큼 int자료를 담을 수 있는 메모리를 확보한다.
		memset(m_pnData, 0, sizeof(int) * nSize);
	}
	~CIntArray() { delete m_pnData; }

	void Set(int index, int n) { m_pnData[index] = n; }
	int Get(int index) { return m_pnData[index]; }
};

//사용자 코드
void TestFunc(CIntArray& arParam)
{
	cout << arParam.Get(1) << endl;
}

int main()
{
	CIntArray arr(3);
	arr.Set(0, 10);
	arr.Set(1, 20);
	arr.Set(2, 30);

	TestFunc(arr);		//배열객체를 출력하는 함수구현하기. size()

	return 0;
}

