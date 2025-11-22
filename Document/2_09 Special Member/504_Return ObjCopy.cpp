//복사 생성호출 확인하기 //반환에 의한 복사 생성자 호출

#include <iostream>
using namespace std;

class CTest
{
private:
	int num;
public:
	CTest(int n) : num(n)
	{ }
	CTest(const CTest& copy) : num(copy.num)
	{
		cout << "CTest(const CTest& copy)" << endl;
	}
	CTest& AddNum(int n)
	{
		num += n;
		return *this;
	}
	void ShowData()
	{
		cout << "num: " << num << endl;
	}
};

CTest SimpleFuncObj1(CTest ob)			//전달에 의한 복사 생성자 호출
{
	cout << "SimpleFuncObj1" << endl;
	return ob;							//반환에 의한 복사 생성자 호출
}

/*
CTest& SimpleFuncObj2(CTest& ob)		//참조 전달의 경우
{
	cout << "SimpleFuncObj2" << endl;
	return ob;							//
}
*/
int main(void)
{
	CTest obj(7);

	SimpleFuncObj1(obj).AddNum(30).ShowData();

	//SimpleFuncObj2(obj).AddNum(30).ShowData();

	obj.ShowData();
	return 0;
}
