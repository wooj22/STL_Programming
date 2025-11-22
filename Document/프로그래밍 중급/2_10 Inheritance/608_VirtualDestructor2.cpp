//가상함수의 경우 소멸자 처리
// 
//		동적할당을 문제 없이 소멸시키려면, 소멸자를 가상화 해야 한다. ***

#include <iostream>
using namespace std;

class First
{
private:
	char* one;
public:
	First(const char* str) {
		one = new char[strlen(str) + 1];
	}
	virtual ~First() {				//포인팅한 접근형식이 아니라, 실형식의 동적할당을 문제 없이 소멸시킨다. 	
		cout << "~First()" << endl;
		delete[] one;			
	}
};

class Second : public First
{
private:
	char* two;
public:
	Second(const char* str1, const char* str2) : First(str1) {
		two = new char[strlen(str2) + 1];
	}
	virtual ~Second() {
		cout << "~Second()" << endl;
		delete[] two;
	}
};

int main(void)
{
	First* ptr = new Second("simple", "complex");

	delete ptr;		//virtual 키워드가 없을 경우, 호출 결과 비교해 보기

	return 0;
}

//상속관계가 있는 클래스이면서 소멸자에서 리소스를 해제해야 하는 경우,
//		반드시, 부모 클래스 안의 소멸자를 가상함수로 선언해야 한다.

//그냥 그럼 모든 함수들을 virtual 로 만들어버리면 안되나 ?
// 
//		불필요한의 오버헤드(overhead)가 존재하게 된다.
//		가상 함수 테이블(virtual function table; vtable)	

//언제 가상 소멸자를 선언해야 할까 ?
// 
//		기본 클래스가 다형성을 의도(즉, 가상 함수가 하나라도 있거나, 파생 클래스에서 상속받아 사용할 목적)라면 
//		반드시 가상 소멸자를 선언해야 합니다.

//순수 가상 소멸자
//		추상 클래스를 만들고 싶지만 순수 가상 함수가 마땅치 않을 때, 
//		소멸자를 순수 가상 소멸자로 선언해 추상 클래스를 만들 수도 있습니다