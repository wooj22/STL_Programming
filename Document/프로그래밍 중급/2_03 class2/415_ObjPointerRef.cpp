//객체의 포인터와 참조

#include <iostream>
#include <cstring>
using namespace std;

class Test {
	int n = 0;
public:
	void set(int a) { n = a; }
	int get() { return n; }
};

void main()
{
	Test a;
	cout << a.get() << endl;	
	
	Test& b = a;				//참조		

	Test* p = &b;				//포인터
	cout << p->get() << endl;

	cout << p << endl;
	cout << &a << endl;
	cout << &b << endl;			// 주소값 확인
}
