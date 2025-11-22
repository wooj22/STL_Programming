//업캐스트	(부모로 형변환) 
//다운캐스트 (자식으로 형변환) 

#include <iostream>
#include <cstring>
using namespace std;

class CBase
{
private:
	int baseNum = 0;
public:
	CBase() { }
	void Base() { cout << baseNum << endl; }
};

class CDerived : public CBase
{
private:
	int derivNum = 0;
public:
	CDerived() { }
	void Derived() { cout << derivNum << endl; }
};

int main(void)
{
	CBase base;
	CDerived drived;

	CBase* pBase = &drived;					//업캐스트 (허용) ***
	pBase->Base();
	pBase->Derived();						//error //부모 범위내에서 사용 


	CDerived* pDrived = &base;				//다운캐스트 (불가) *** //error

	CDerived* pDrived = (CDerived*)&base;	//강제 형변환은 허용 //단, 오류 조심 


	//강제 다운캐스트시 주의 --------------------------------------------

	CDerived* pDrived = (CDerived*) new CBase();
	pDrived->Base();
	pDrived->Derived();						//실행시 error !!!

	//실객체가 유효할때 다운캐스트해야 안전하다.

	return 0;
}