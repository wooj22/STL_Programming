// InheritInterface.cpp 

//순수 가상 함수(Pure Virtual Function)
//      순수 가상 함수는 즉, 함수의 몸체가 정의되지 않는 함수를 의미한다.
 
//순수가상함수의 기능
//		추후 구현 강제화  //설계 규약  //동시작업  //인터페이스 기능

#include <iostream>

class CMyUSB
{
public:
	virtual int GetUsbVersion() = 0;		//순수가상
	virtual int GetTransferRate() = 0;
};

class CMySerial
{
public:
	virtual int GetSignal() = 0;
	virtual int GetRate() = 0;
};

class CMyDevice : public CMyUSB, public CMySerial
{
public:
	//USB 인터페이스
	virtual int GetUsbVersion() { return 0; }
	virtual int GetTransferRate() { return 0; }
	//시리얼 인터페이스
	virtual int GetSignal() { return 0; }
	virtual int GetRate() { return 0; }
};

void Connect(CMyUSB& usb) {		}
void Connect(CMySerial& serial) {		}

int main()
{
	CMyDevice dev;

	//Connect(dev);

	return 0;
}

