// private 생성자 
//		- 생성자가 private이라는 것은 외부에서의 객체 생성을 허용하지 않겠다는 뜻이다.

#include <iostream>
using namespace std;

class ClassA
{
private:
	int num;
	ClassA(int n) : num(n) {}					// private 생성자 
public:
	ClassA() : num(0) {}						// public 생성자
	//ClassA(int n) : num(n) {}					// 
	void ShowNum() const {	cout << num << endl; }

	ClassA& CreateInitObj(int n) const {
		ClassA* ptr = new ClassA(n);			// 동적할당
		return *ptr;
	}

};

int main(void)
{
	ClassA base;								//public

	ClassA base(1);								//private 이므로 error


	ClassA& obj1 = base.CreateInitObj(3);		//함수를 이용해 생성, 객체 참조로 그대로 받음.
	obj1.ShowNum();
	ClassA& obj2 = base.CreateInitObj(12);
	obj2.ShowNum();

	delete &obj1;								// 함수에서 할당된 것은 해제해야 한다. 
	delete &obj2;

	return 0;
}

//싱글톤 패턴 등에서 활용. 싱글톤에 대해 조사해 보세요. ***

/*
	#include <iostream>

	class Singleton {
	private:
		Singleton() { std::cout << "Singleton()" << std::endl; }
		Singleton(const Singleton& ref) {}
		Singleton& operator=(const Singleton& ref) {}
		~Singleton() { std::cout << "~Singleton()" << std::endl; }
	public:
		static Singleton& getInstance() {
			static Singleton s;
			return s;
		}
	};

	int main(void) {
		//Singleton s;
		{
			Singleton& s = Singleton::getInstance();
		}
		{
			Singleton& s = Singleton::getInstance();
		}
		return 0;
	}

*/


