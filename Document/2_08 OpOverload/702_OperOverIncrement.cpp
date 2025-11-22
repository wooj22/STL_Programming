// 연산자 오버로드		//전위 증가 연산자 //후위 증가 연산자

#include <iostream>
using namespace std;

class CMyData
{
private:
	int m_Data = 0;
public:
	CMyData(int nParam) : m_Data(nParam) {}

	operator int() { return m_Data; }		//형식변환 //int 로 변환가능

	//int& operator++()				//전위 증가 연산자
	//{
	//	cout << "operator++()" << endl;
	//	return ++m_Data;
	//}

	//int operator++(int)			//후위 증가 연산자
	//{
	//	cout << "operator++(int)" << endl;
	//	int nData = m_Data;
	//	m_Data++;
	//	return nData;
	//}

};

int main()
{
	CMyData a(10);

	cout << ++a << endl; //전위 증가 연산자를 호출한다.	
	cout << a++ << endl; //후위 증가 연산자를 호출한다.
	cout << a << endl;

	return 0;
}


/*
//연속 증감이 가능한지 테스트 하세요. ***
int main()
{
	int n = 0;
	++(++n);
	(n++)++;
}
*/

//int& operator++()				//전위 증가 연산자  int& 
//{
//	return ++m_Data;
//}

//int operator++(int)			//후위 증가 연산자  
//{
//	return m_Data++;
//}