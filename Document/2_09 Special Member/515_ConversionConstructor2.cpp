// 예시 //복사 생성자 //변환 생성자 //허용되는 변환(변환 함수)

#include <iostream>
#include <cstring>
using namespace std;

class Test
{
	char* name;
	int age;
public:
	Test(const char* myname, int myage)
	{
		cout << "Test()" << endl;
		name = new char[strlen(myname) + 1]; strcpy(name, myname);
		age = myage;
	}
	Test(const Test& copy) : age(copy.age)   //복사 생성자
	{
		cout << "Test() Copy" << endl;
		name = new char[strlen(copy.name) + 1]; strcpy(name, copy.name);	//Deep Copy
	}
	Test& operator= (const Test& copy)		//단순 대입 연산자
	{
		name = new char[strlen(copy.name) + 1];	strcpy(name, copy.name);
		return *this;
	}

	Test(const char* myname)			//변환 생성자  //모호성 주의 explicit 명시필요
	{
		cout << "Test() char*" << endl;
		name = new char[strlen(myname) + 1]; strcpy(name, myname);
		age = 0;
	}
	Test(const int myage)				//변환 생성자  //모호성 주의 explicit 명시필요 //허용되는 변환과 비교
	{
		cout << "Test() int" << endl;
		name = new char[1];	name[0] = '\0';	//name = nullptr;
		age = myage;
	}

	~Test()
	{
		delete[] name;
		cout << "~Test()" << endl;
	}
	void ShowInfo() const
	{
		cout << "이름: " << name << endl;
		cout << "나이: " << age << endl;
	}

	operator int(void)			//형변환 //허용되는 변환(변환 함수) //모호성 주의
	{
		return age;
	}
};

void FuncPrint(const Test& a)
{
	a.ShowInfo();
}

void main(void)
{
	const char* name = "Kim";

	Test class1(name, 10);
	Test class2(class1);

	Test class3 = class1;
	//Test class3.operator=(class1);

	Test class4("Lee");

	cout << endl;
	Test class5(7);
	Test(7);

	cout << endl;
	FuncPrint(5);				//이름없는 임시객체가 생긴다.

	cout << endl;
	cout << class5 << endl;		//변환 함수 (허용된 변환)
}


/*

// Ex. 변환 함수 정의 예시

CTest::operator int () const {     // CTest는 사용자 정의 클래스이다.
	return int (a + 1);       // a 는 CTest 클래스의 데이터 멤버이다.
}


// Ex. 암시적 데이터형 변환을 불허하는 변환 함수 원형의 일반형
explicit operator dataType() const;


// Ex. 변환 함수의 명시적/암시적 사용 예시

// 명시적 호출 방법
dataType variables = dataType(objectName);
dataType variables = (dataType)objectName;

// 암시적 호출 방법
dataType variables = objectName;
*/