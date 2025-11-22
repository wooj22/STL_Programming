//클래스에 포인터 변수 멤버가 있는 경우, 
//		디폴트 복사 생성자와 같이 얕은 복사 생성자를 사용하면 
//		포인터가 가진 메모리를 원본과 사본 객체가 공유하는 문제가 있다.
//		깊은 복사(deep copy)로 해결해야 한다. ***

#include <iostream>
#include <cstring>
using namespace std;

class CPerson
{
	char* name;
	int age;
public:
	CPerson(char* myname, int myage)
	{
		int len = strlen(myname) + 1;
		name = new char[len]; strcpy_s(name, len, myname);
		age = myage;
	}
	CPerson(const CPerson& copy) : name(copy.name), age(copy.age)   //복사 생성자
	{
		cout << "Test() Copy" << endl;
		int len = strlen(copy.name) + 1;
		name = new char[len]; strcpy_s(name, len, copy.name);	//Deep Copy
		age = copy.age;
	}
	~CPerson()
	{
		delete[]name;
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
	char str[] = "Lee dong woo";

	CPerson man1(str, 29);
	CPerson man2 = man1;		

	man1.ShowInfo();
	man2.ShowInfo();

	return 0;
}


/*
//클래스에 참조 변수 멤버가 있는 경우

#include <iostream>
using namespace std;

struct Player {
	int& r;
	Player(int& n) : r(n) { }
};

int main(void)
{
	int n = 0;

	Player p1(n);
	Player p2(p1);

	p1.r = 1;
	//n = 2;

	cout << p1.r << endl;
	cout << p2.r << endl;

	return 0;
}

*/