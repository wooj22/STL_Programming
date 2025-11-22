//복사 생성호출 확인하기

#include <iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int n) : num(n) { cout << "New      : " << this << endl }
	CTest(const CTest& copy) : num(copy.num) { cout << "New Copy : " << this << endl; }
	~CTest() {	}
};

CTest SimpleFuncObj2(CTest ob)
{
	cout << "Parm address: " << &ob << endl;  //
	return ob;
}

int main(void)
{
	CTest obj(7);

	SimpleFuncObj2(obj);	//출력을 확인해서 어떤 객체가 생성되는지 확인하세요.
	cout << endl;

	//CTest tempRef = SimpleFuncObj2(obj);
	//cout << "Return address: " << &tempRef << endl;  // 주소확인 하세요.

	return 0;
}
