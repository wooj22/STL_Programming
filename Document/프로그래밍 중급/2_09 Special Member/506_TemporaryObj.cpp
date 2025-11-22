//임시객체 - 이름 없이 생성되는 객체. 사용 후 사라짐.

#include <iostream>
using namespace std;

class Temporary
{
private:
	int num;
public:
	Temporary(int n) : num(n)
	{
		cout << "create obj: " << num << endl;
	}
	~Temporary()
	{
		cout << "destroy obj: " << num << endl;
	}
	void ShowTempInfo()
	{
		cout << "My num is " << num << endl;
	}
};

int main(void)
{
	Temporary(100);							//Temporary ???(100);	//rvalue, 값
	cout << "********** after make!" << endl << endl;

	Temporary(200).ShowTempInfo();			//임시객체의 참조값.ShowTempInfo()
	cout << "********** after make!" << endl << endl;

	const Temporary& ref = Temporary(300);	//참조되는 동안은 존재 ***
	cout << "********** end of main!" << endl << endl;
	return 0;
}
