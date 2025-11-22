//연습) 두 객체의 num 더해진 객체를 리턴하는 함수 구현
// 1. 맴버함수로 구현하세요.
// 2. 프렌즈 함수로 구현하세요.

#include <iostream>
using namespace std;

class MyClass
{
	int num = 0;
public:
	int Get() { return num; }
	void Set(int a) { num = a; }

	MyClass Sum(MyClass obj);		//1.
	//friend MyClass Sum2(MyClass obj1, MyClass obj2);  //2
};

int main(void)
{
	MyClass x; x.Set(1);
	MyClass y;

	MyClass z = x.Sum(y);			//1. 두 객체의 num 더해진 객체 리턴

	//MyClass z = Sum2(x, y);		//2. 프렌즈 함수로 구현하세요.

	cout << z.Get() << " " << z.Get();

	return 0;
}


MyClass MyClass::Sum(MyClass obj)  //객체 맴버로 구현
{
	MyClass res;
	res.num = this->num + obj.num;
	return res;
}

MyClass Sum2(MyClass obj1, MyClass obj2) 
{
	MyClass res;
	res.num = obj1.num + obj2.num;
	return res;
}