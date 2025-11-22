//멤버 함수 재정의 //오버라이딩 
//		파생클래스에서 부모와 '같은 함수'를 정의하는 경우를 오버라이딩이라고 한다.

#include <iostream>
using namespace std;

class Human
{
protected:
	char name[24];
	int age;

public:
	Human(const char* name, int age) {
		strcpy_s(this->name, name);
		this->age = age;
	}
	void Show() {
		cout << "이름 : " << this->name << endl;
		cout << "나이 : " << this->age << endl;
	}
};

class Student : public Human
{
protected:
	int stunum;
public:
	Student(const char* name, int age, int stunum) : Human(name, age) {
		this->stunum = stunum;
	}
	void Study() {
	}
	void Show() {			// 오버라이딩(함수 재정의)	// 자식 클래스만의 Show() 함수
		printf("%d 학번 %s 입니다.\n", this->stunum, this->name);
	}
};

int main()
{
	Human hong("홍길동", 30);
	hong.Show();
	Student kim("김길동", 20, 123456);
	kim.Show();
	
	
	//일반 멤버 함수의 오버라이딩은 부모의 함수를 은닉(Hiding) 하는 특징이 있다. ***

	//자식 클래스인데 이름, 나이만 출력하는 부모 클래스의 Show()를 출력하고 싶다면 ?

	kim.Human::Show();			// => 함수의 소속 클래스를 써주면 가능

	//은닉되었을 뿐, 상속된 함수는 존재
}


//오버라이드한 경우
//		업캐스트의 경우, 부모 클래스로 호출			(정적 바인딩) 
//		만약 부모로 자식을 자동 호출하고 싶다면 ?		(동적 바인딩) 
// 
// -> 가상함수를 통한 동적바인딩으로 해결
