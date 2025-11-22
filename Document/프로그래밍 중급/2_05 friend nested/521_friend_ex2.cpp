//연습) friend 이용한 ++ 연산자 기능 구현하기		//연산자 오버로드 참고 
//	1. 맴버함수로 구현하세요.
//	2. 프렌즈 함수로 구현하세요.

#include <iostream>
using namespace std;

class MyClass
{
	int num = 0;
public:
	MyClass() {}
	MyClass(int a) :num(a) { }
	void Show() { cout << num << endl; }

	MyClass AddOnePrefix()
	{
		++this->num;
		return *this;
	}
	MyClass AddOnePostfix()
	{
		MyClass temp;
		temp = *this;
		++this->num;
		return temp;
	}

	// friend 함수로 구현해 보세요.

	//friend MyClass& AddOnePrefix(MyClass& obj);
	//friend MyClass AddOnePostfix(MyClass& obj);
};

//MyClass& AddOnePrefix(MyClass& obj)
//{
//    ++obj.num;
//    return obj;
//}
//
//MyClass AddOnePostfix(MyClass& obj)
//{
//    MyClass temp;
//    temp = obj;
//    ++obj.num;
//    return temp;
//}

void main()
{
    MyClass x(10), y(10);

    MyClass z;

    cout << "---- 선행처리 ----\n";
    z = AddOnePrefix(x);			
    z.Show();	//11
    x.Show();	//11

    cout << "---- 후행처리 ----\n";
    z = AddOnePostfix(y);		
    z.Show();	//10
    y.Show();	//11
}