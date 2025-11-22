//클래스 맴버에 참조변수 사용 예시

#include <iostream>
using namespace std;

class ClassC
{
private:
	int& ref;		// 참조

public:
	ClassC(int r) : ref(r) { }
	~ClassC() { }
	void Show() { cout << ref << endl; }
};

int main() {
	ClassC b(1);
	b.Show();		// 결과는? 이유는?  //어떻게 사용?
}

/*
class ClassC
{
private:
	const int& ref;

public:
	ClassC(const int& r) : ref(r) { }			//const
	~ClassC() { }
	void Show() { cout << ref << endl; }
};

int main() {
	ClassC b(1);
	b.Show();		// 결과는? 이유는?  //어떻게 사용?
}
*/