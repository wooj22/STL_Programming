//다른 클래스를 클래스의 맴버로 사용하는 방법

//중첩 클래스 (Nested Class) 또는 내부 클래스 (Inner Class)
// 
//		클래스 내부에 또 다른 클래스를 만들 수 있다
//		데이터의 캡슐화(Encapsulation)와 정보 은닉(Information Hiding)을 위해서 사용

//------------------------------------------------------------------------------
#include <iostream>
using namespace std;

struct enclose 
{
	struct inner						//enclose 내부에서 사용하겠다.
	{
		static int ivalue;
		void func(int value) { }
	};
};

//------------------------------- 
struct enclose 
{
	struct inner {
		static int ivalue;
		void func(int value);
	};
};
// 필히 정규화된 이름을 사용해야 한다.
int enclose::inner::ivalue = 1;				// 내부 클래스의 멤버를 초기화.
void enclose::inner::func(int value) { }	// 내부 클래스의 함수를 정의.

//------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Outter
{
private:
	int n = 0;
public:
	class Nested								//맴버 클래스
	{
	public:
		void Func() { cout << n << endl; }		//private 맴버 사용 ***  
	};
};

//------------------------------------------------------------------------------

#include <iostream>
using namespace std;

class Outter {
private:
public:
	class Nested {
	private:
		string name;
	public:
		Nested(string nameValue) : name(nameValue) { }
		void Display() const {
			cout << name.c_str() << endl;
		}
	};
};

int main(void)
{
	Outter out;					// Outter 객체 생성

	Outter::Nested n("abc");	// Nested 객체 생성
	n.Display();

	return 0;
}

//--------------------------------------------------------------------

#include <iostream>
#include <string>

class Outter 
{
private:					
	class Nested		//private 이라면
	{
	private:
		std::string name;
	public:
		Nested(std::string nameValue) : name(nameValue) {
		}
		void Display() const {
			std::cout << "내부 클래스의 " << name.c_str() << std::endl;
		}
	};

public:
	// 정적 함수로 내부 클래스를 객체로 생성하여 반환합니다.
	static Nested func(std::string name) {
		return Nested{ name };
	}
};

// 위 클래스에서 Display() 함수를 호출해 봅시다 ----------------

int main() 
{
	// Display() 함수 호출하려면 객체 생성 필요. 그런데 private

	// func 반환 객체를 인스턴스로 지정해보자.		

	Outter::Nested anotherClass = Outter::func("객체 생성");		// ERROR 
	// Nested 클래스는 Outter 클래스 내 private로 선언되어 있습니다. 
	// 직접 타입을 선언하는 것은 허용되지 않습니다.


	//해결책 1
	// func() 함수는 public으로 선언되어 있어 접근이 가능합니다.
	// 따라서 반환 받은 객체로부터 Display() 함수를 호출할 수 있습니다. // 하지만 제어의 원칙에 벗어나므로 조심.
	Outter::func("호출 방법").Display();
		
	//해결책 2
	// 클래스는 원칙적으로 private로 선언되어 있어 외부로부터 접근이 불가능합니다.	 
	// 그러나 타입을 auto를 사용한다면, 
	// 내부 클래스가 아닌 또 다른 클래스로 인식되기 때문에 사용이 가능합니다.
	auto anotherClass = Outter::func("선언 방법");
	anotherClass.Display();

}