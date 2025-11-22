//복사 생성자
//		객체를 생성할 때, 원본 객체를 복사하여 생성하는 것을 말한다
//		객체를 생성해야 한다. 단, 생성과 동시에 동일한 자료형의 객체로 초기화해야 하는 경우

//		ClassName(const ClassName&);

//디폴트 복사 생성자
//		작성 안하면 기본 생성된다. 
//		기본 복사 생성자는 얕은 복사(shallow copy) 방식으로 복사 한다. (자동으로 되는 것 조심)
//		즉, 맴버데이타를 값을 새로 생성되는 객체에 일대일 그대로 복사.

#include <iostream>
using namespace std;

class CTest
{
private:
	int num1;
	int num2;
public:
	CTest(int n1, int n2) : num1(n1), num2(n2)
	{
		// empty
	}

	//복사 생성자를 정의하지 않으면, 멤버 대 멤버의 복사를 진행하는 '디폴트 복사 생성자'가 삽입된다
	CTest(const CTest& copy) : num1(copy.num1), num2(copy.num2)
	{
		cout << "CTest(CTest &copy)" << endl;
	}

	void ShowSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}
};

int main(void)
{
	CTest obj1(15, 30);		// obj1
	cout << "----------------- 1" << endl;

	CTest obj2 = obj1;		// obj1 과 같은 data 값을 같는 객체를 생성한다. *** 
	cout << "----------------- 2" << endl;

	obj2.ShowSimpleData();
	return 0;
}

//복사 생성자를 선언해 보자. ----------------------------- ***
/*
class Player {
public:
	string name = "";
	int level = 0;
};
*/



/*
복사 생성자의 호출시점은 크게 세가지로 구분

	1) 기존에 생성된 객체를 이용해 새로운 객체를 초기화 하는 경우	    
		Object  a = b;
		Object  a(b);
		Object* a = new Object(b);

	2) Call_by_value 방식의 함수호출 과정에서 객체를 인자로 전달하는 경우

		func(Object a)

	3) 객체를 반환하되, 참조형으로 반환하지 않은 경우

		Object a = func()

*/


//아래 코드에서 복사 생성자는 몇번 호출되는가?

#include <iostream>
using namespace std;

class MyClass {
	int n = 0;
public:
	MyClass(int n) : n(n) { }
	MyClass(const MyClass& o) {
		n = o.n;
		cout << "MyClass(const MyClass& )" << endl;
	}
};

MyClass& Func(MyClass& o) {
	return o;
}

int main()
{
	MyClass m1(10);
	MyClass m2(m1);				//복사 생성자
	MyClass m3 = Func(m2);		//복사 생성자 //복사 생성자
}