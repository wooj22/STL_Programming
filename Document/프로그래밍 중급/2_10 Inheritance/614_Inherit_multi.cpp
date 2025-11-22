//다중상속 
//		C++ 은 다중상속을 지원한다.
//		가급적 주의, 인터페이스 다중상속 등 특별한 경우 사용

//가상 상속
//		다중상속의 경우 인스턴스가 여러개 생성됨, 모호성 문제.
//		virtual 로 상속을 하면 하나의 인스턴스만 만들도록 가상화 함.

#include <iostream>
using namespace std;

class CMyObject
{
public:
	CMyObject() { cout << "CMyObject()" << endl; }
	virtual ~CMyObject() {}
};

class CMyImage : public CMyObject	//상속받을 때 virtual을 명시하면 컴파일러는 single instance 만을 만든다.
{
public:
	CMyImage(int nHeight, int nWidth) : m_nHeight(nHeight), m_nWidth(nWidth)
	{
		cout << "CMyImage(int, int)" << endl;
	}
	int GetHeight() const { return m_nHeight; }
	int GetWidth() const { return m_nWidth; }
	int GetSize() const { return 0; }

protected:
	int m_nHeight;
	int m_nWidth;
};

class CMyShape : public CMyObject //single 로 생성할 대상을 virtual 로 상속한다.
{
public:
	CMyShape(int nType) : m_nType(nType)
	{
		cout << "CMyShape(int)" << endl;
	}
	int GetType() const { return m_nType; }
	int GetSize() const { return 0; }

protected:
	int m_nType;
};

class CMyPicture : public CMyImage, public CMyShape		//두 클래스를 모두 상속 받는다.
{
public:
	CMyPicture() : CMyImage(200, 120), CMyShape(1)
	{
		cout << "CMyPicture()" << endl;
	}
};

int main(int argc, const char* argv[])
{
	CMyPicture a;
	cout << "Width: " << a.GetWidth() << endl;
	cout << "Height: " << a.GetHeight() << endl;
	cout << "Type: " << a.GetType() << endl;

	//두 부모 클래스에 모두 존재하면 모호성 문제가 된다. ***
	//a.GetSize();			//error

	//지정해서 사용해야 한다.
	//a.CMyImage::GetSize();
	//a.CMyShape::GetSize();

	return 0;
}

