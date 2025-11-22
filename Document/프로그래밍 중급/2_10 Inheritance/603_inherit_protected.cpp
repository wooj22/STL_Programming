//protected 상속 ***
// 
//		protected보다 접근의 범위가 넓은 멤버는 protected로 상속한다.
//		단, private은 접근불가로 상속한다! 

#include <iostream>
using namespace std;

class Base
{
private:
	int num1;
protected:
	int num2;
public:
	int num3;

	Base() : num1(1), num2(2), num3(3)	{  }
};

class Derived : protected Base    //protected 상속
{
}; 

int main(void)
{
	Derived drv;				//num2, num3 는 protected
	cout << drv.num3 << endl;   //error
	return 0;
}

// private 상속 --------------------------------------------------------------

#include <iostream>
using namespace std;

class A {
private:
	int a;
protected:
	int b;
public:
	int c;
};

class B : private A {		//b,c 맴버 변수는 private 맴버로 접근 범위 축소
};

int main() {
	B obj;		//a = private, b = private, c = private
	obj.a;
	obj.b;
	obj.c;
}


//상속을 위한 기본 조건 :: IS-A

//C++에서는 has-a 관계를 구현하는 또 다른 방법으로 private 상속을 제공하고 있다.
//	기초클래스로부터 파생클래스로 private 상속이 될 경우 
//	기초클래스의 public과 protected 멤버는 파생클래스의 private 멤버로 변환되어 상속된다.
//	즉, 기초클래스의 public 멤버들이 파생클래스의 public 인터페이스가 되지 않고 private 멤버가 된다는 이야기다.

//일반적으로 public 상속에서는 
//	기초클래스의 public 멤버, 
//	즉, 기초클래스의 인터페이스를 파생클래스의 인터페이스로 넘겨줌으로서 is-a 관계를 구현한다.
// 
//반면에 private 상속은 
//	기초클래스의 인터페이스를 private 형태로 상속하므로 인터페이스를 넘겨주지 않는다.
//	파생클래스가 기초클래스를 소유하고 있을 뿐이다. 이건 has-a 관계를 의미한다.


//protected 생성자 -----------------------------------------------------------
// 
//		자기 자신은 객체를 만들 수 없지만 (추상적인 존재)
//		파생 클래스의 객체는 만들 수 있게 하는 의미
/*

	#include <iostream>

	class Animal
	{
	protected:
		Animal() {}
	};

	class Cat : public Animal
	{
	public:
		Cat() {}			// Cat() : Animal() {}
	};

	int main()
	{
		// Animal animal;	// error
		Cat cat;
	}
*/