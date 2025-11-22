//클래스 템플릿 - 클래스 맴버의 변수 타입에 대하여 선언
//클래스 템플릿 특수화
//클래스 템플릿 - 클래스 맴버의 변수 타입에 대하여 선언
//클래스 템플릿 특수화

#include <iostream>
using namespace std;

template <typename T>
class CTest
{
public:
	CTest(T param) : ndata(param) { }
	~CTest() { }

	void SetData(T val) { ndata = val; };
	T GetData() { return ndata; };

private:
	T ndata;
};

template <> class CTest<const char*>		//특수화
{
public:
	CTest(const char* param) {
		m_data = new char[strlen(param) + 1];
		strcpy_s(m_data, strlen(param) + 1, param);
		//
	}
	~CTest() { delete[] m_data; }

	char* GetData() const {
		return m_data;
	};

private:
	char* m_data;
};

int main(void)
{
	CTest<const char*> a("hello");

	cout << a.GetData() << endl;

	return 0;
}
