//복사 생성자는 
//	객체의 복사 생성 시에 호출되는 특별한 원형의 생성자로서, 
//	하나의 매개 변수만을 가지며, 매개 변수는 클래스에 대한 참조 타입이다.
// 
//  ClassName(const ClassName&);

//복사 생성자가 작성되지 않은 클래스의 경우, 컴파일러가 디폴트 복사 생성자를 자동 삽입하여 
//  디폴트 복사 생성자의 문제점은
//  디폴트 복사 생성자는 얕은 복사를 실행한다는 것이다. ***

/*
// shallow copy - 값을 그대로 복사. '포인터'의 경우는 주소 값이므로 같은 곳을 가르키게 됨.

	{
		int *pA = new int(5);
		int *pB = NULL;

		pB = pA;			//shallow copy
		pB = new int(*pA);	//deep copy

		cout << *pA << endl;
		cout << *pB << endl;

		delete pA;
		delete pB;
	}
*/

#include <iostream>
#include <cstring>
using namespace std;

class CPerson
{
	char* name;
	int		age;
public:
	CPerson(char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len]; strcpy_s(name, len, myname);
		age = myage;
	}
	//CPerson(const CPerson& copy) : name(copy.name), age(copy.age)   //복사 생성자
	//{
	//	name = copy.name);		// Shallow Copy
	//	age = copy.age;
	//}
	~CPerson()
	{
		delete[] name;
		cout << "called destructor!" << endl;
	}
	void ShowInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}
};

int main(void)
{
	char str[] = "Lee min su";

	CPerson man1(str, 29);
	man1.ShowInfo();

	CPerson man2 = man1;		// 디폴트 복사 생성자
	man2.ShowInfo();

	//int in; cin >> in;			//wait

	// 해제할 때 오류 발생.

	return 0;
}
