//이동 생성자(Move constructor) 및 이동 대입 연산자(Move assignment operator)

//이동 생성자		
//		복사 생성할 객체가 R-value (임시객체) 일 때 불린다.  
//		새로 생성할 객체를 사라질 것으로 대체 (이동, copy -> move )
// 
//		ClassName(ClassName&&);    //매개변수로 R-value 참조가 온다.

//이동 대입 연산자	
//		이동 생성자를 만든다면 대입연산도 같이 고려.
// 
//		ClassName& operator=(ClassName&&);
 
//이동생성자가 없으면 '복사생성자'가 실행된다. 
//		즉, 사용자 코드 변화없다. 성능은 좋아진다. - 정성
//		자동으로 하는거 조심. 파악해서 구현하는 것은 어렵지만 성능 향상.

/*
// R-value 참조

		C++에서는 식이 끝난 후 계속 존재하는 값은 좌측값, 식이 끝나면 존재하지 않는 임시값은 우측값이다.

	주소값을 취할 수 있는 값을 Lvalue
	주소값을 취할 수 없는 값을 Rvalue,
	z = a + b + c + 4;				//의 경우
	x = a + b + c; z = x + 4;		//사라질 x 에 대한 r-value 참조 필요.

	int a = 0;			//Lvalue = Rvalue
	int b = a;			//Lvalue = Lvalue

	int& r1 = a;		//Lvalue 참조
	const int& r3 = 1;	//const Lvalue 참조		//C++11 이전
	int&& r2 = 1;		//Rvalue 참조			//C++11 //modern c++
*/

#include <iostream>
#include <cstring>
using namespace std;

class CTest
{
	int nData = 0;
public:
	CTest() { cout << "CTest() " << &(*this) << endl; }		//기본생성자
	~CTest() { cout << "~CTest() " << &(*this) << endl; }

	CTest(const CTest& val)							//복사 생성자
	{
		cout << "CTest(const CTest &)" << endl;
		nData = val.nData;
	}
	CTest& operator=(const CTest& val)				//복사 대입연산자
	{
		nData = val.nData;
		return *this;
	}
	CTest(CTest&& val) noexcept						//이동 생성자 //임시객체 처리 // move construtor 
	{
		cout << "CTest(const CTest &&)" << endl;
		nData = val.nData;
	}
	CTest& operator=(CTest&& val) noexcept			//이동 대입연산자 // move assignment 
	{
		cout << "operator=(CTest&&)" << endl;
		nData = val.nData;
		return *this;
	}

	CTest(int param) : nData(param)					//변환생성자 //매개변수 하나 //explicit 묵시적 변환하지 마라
	{
		cout << "CTest(int)" << endl;
	}
	operator int(void)								//허용되는 변환 //모호성 주의
	{
		return nData;
	}

	CTest operator+ (const CTest& val) const	// + 연산자
	{
		CTest result;
		result.nData = nData + val.nData;
		return result;
		//return CTest(nData + val.nData);
	}
};

CTest CTestAdd(const CTest& l, const CTest& r)
{
	return l + r;
}

void main(void)
{
	CTest a;
	CTest b;
	CTest c(a);						//복사 생성자
	//CTest c = a;					//복사 생성자
	//CTest c; c = a;				//대입 연산자

	//CTest result = a + b;			//이동 생성자  //a + b 의 결과는 Rvalue
	//result = a + b;				//이동 연산자

	CTest result = CTestAdd(a, b);

	//cout << CTest(1) << endl;
	//cout << CTest(1) + CTest(2) << endl;

}


//이동생성자의 호출 조건	***
// 
//	1. 임시객체를 전달할 때.
//	2. std::move()를 사용하여 인자를 rValue참조자 로 변환하여 전달할 때.
//
//	CTest b = std::move(a);		// 이동생성자 호출	
//	b = CTest();				// 이동대입연산자 호출

/*
임시객체 -------------------------------------------------------------

	객체를 반환하게 되면, '임시객체'라는 것이 생성되고,
	이 객체의 복사생성자가 호출되면서 return문에 명시된 객체가 인자로 전달된다.
	즉, 최종적으로 반환되는 객체는 새롭게 생성되는 임시객체이다.
	따라서 함수호출이 완료되면, 지역적으로 선언된 객체는 소멸되고 obj 객체와 임시객체만 남는다.

	* 임시객체의 소멸시점
	- 임시객체는 다음 행으로 넘어가면 바로 소멸
	- 참조자에 참조되는 임시객체는 바로 소멸되지 않는다.

연산자(=)를 기준으로 왼쪽에 있는 것을 L-value, 오른쪽에 있는 것을 R-value라고 하는데,
	L-value 는 주소를 가질 수 있다.
	L-value 에는 값이 올 수 없다.   3 = a 불가.

std::move ------------------------------------------------------------

	R-value 참조 로 반환해주는 함수.
*/



/*
//특수 맴버함수를 정의해 봅시다. ---------------------------------------------------

#include <iostream>
##include <vector>
using namespace std;

class Person {
	char* name;
	int age;
public:
	Person();
	Person(const char _name[], int _age);
	~Person();
	Person(const Person& p);				// 복사 생성자 선언
	Person& operator=(const Person& p);		// 복사 대입 연산자 선언
	Person(Person&& p) noexcept;			// 이동 생성자 선언
	Person& operator=(Person&& p) noexcept; // 이동 대입 연산자 선언
}

Person::Person() {
	name = NULL;
	age = 0;
}

Person::Person(const char _name[], int _age) {
	name = new char[strlen(_name) + 1]; // NULL문자를 고려
	strcpy_s(name, strlen(_name) + 1, _name);
	age = _age;
}

Person::~Person() {
	delete[]name;	// DeAllocate the heap
}

Person::Person(const Person& p) : age(p.age) {
	name = new char[strlen(p.name) + 1];
	strcpy_s(name, strlen(p.name) + 1, p.name); // 깊은 복사
}

Person& Person::operator=(const Person& p) {
	if (this != &p) {
		delete[] name;
		name = new char[strlen(p.name) + 1];
		strcpy_s(name, strlen(p.name) + 1, p.name); // 깊은 복사
		age = p.age;
	}
	return *this;
}

Person::Person(Person&& other) noexcept {
	name = other.name;						// 얕은 복사
	age = other.age;
	other.name = nullptr;					// 임시 객체 소멸 시에 메모리를 해제하지 못하게 한다.
	other.age = 0;
}

Person& Person::operator=(Person&& other) noexcept {
	if (this != &other) {
		delete[]name;
		name = other.name;					// 얕은 복사
		age = other.age;
		other.name = nullptr;				// 이전 객체에서 pointer는 삭제
		other.age = 0;
	}
	return *this;
}

*/

/*
 noexcept : 예외를 던지지 않는다.  // 상수값은 사라지므로 에외처리 안하도록 선언.

	//예외를 던지지 않는다.
	void func1() noexcept;
	//또는
	vpod func1() noexcept(true);

	//예외를 던질 가능성이 있다.
	void func2() noexcept(false);


컴파일러에게 이 함수는 throw 를 하지 않는 다는 것을 보장하여 두 가지 이점을 취할 수 있게 됩니다.

1. 예외를 던지지 않는다는 보장이 있으므로 컴파일러는 예외 던지기에 따른 스택 반전을 위해 스택을 확보할 필요가 없어진다
2. 예외를 절대 던지지 않는 강한 예외 안전성을 보증한다(No - throw guarantee)
*/


//자동 생성 조건 ***
// 
//복사 생성자는
//복사 생성자가 명시적으로 선언되어 있지 않은 클래스에 대해서만 자동 작성되며,
//만일 이동 연산이 하나라도 선언되어 있으면 삭제된다. 복사할당연산의 경우도 마찬가지.
// 
//이동 연산들은
//이동 연산들이나 복사 연산들, 소멸자가 명시적으로 선언되어 있지 않은 클래스에 대해서만 자동으로 작성된다.