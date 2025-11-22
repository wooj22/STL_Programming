//디폴트 대입 연산자(Copy Assignment Operator)
// 
//		복사 생성자를 정의하지 않으면, 멤버 대 멤버의 복사를 진행하는 디폴트 복사 생성자가 삽입된다.
//		대입 연산자를 정의하지 않으면, 멤버 대 멤버의 연산을 진행할때도 디폴트 대입 연산자

//복사생성자(Copy Constructor)와 대입연산자(Copy Assignment Operator)
// 
//		단순 대입 연산자는 복사생성자와 연관지어 생각하자.
//		즉, 필요하다면 둘다 만들어야 한다.
 
//클래스에서 연산자 정의하기. (연산자 오버로드, 연산자 함수) 

#include <iostream>
#include <cstring>
using namespace std;

class CTest
{
	int age;
public:
	CTest(const char* myname, int myage)
	{
		cout << "CTest()" << endl;
		age = myage;
	}
	CTest(const CTest& copy) : age(copy.age)	//복사 생성자 //디폴트 복사 생성자 대체
	{
		cout << "CTest() Copy" << endl;
		age = copy.age;
	}
	CTest& operator= (const CTest& copy)		//단순 대입 연산자 //디폴트 대입 연산자 대체
	{
		cout << "CTest() =" << endl;
		age = copy.age;
		return *this;
	}

	~CTest()
	{
		cout << "~CTest()" << endl;
	}
	void ShowInfo() const
	{
		cout << "나이: " << age << endl;
	}


/*
	CTest(int myage)			//변환 생성자 //모호성 주의 explicit 명시필요
	{
		cout << "CTest(int)" << endl;
		age = myage;
	}

	operator int(void)			//변환 연산자 //허용되는 변환 //모호성 주의
	{
		cout << "CTest() int" << endl;
		return age;
	}
*/
};

void main(void)
{
	const char* name = "Kim";

	CTest class1(name, 10);
	cout << endl;

	CTest class2(class1);		//복사 생성
	cout << endl;

	CTest class3 = class1;		//복사 생성
	cout << endl;

	class3 = class1;			//대입 연산자
	//class3.operator=(class1);

	/*
		CTest class5(12);
		cout << endl;

		class5 = class1;
		cout << endl;

		cout << class5 << endl;
		cout << endl;
	*/
}