//클래스 인스턴스 전달, 반환 ------------------------------------------------------	
//Pass by Reference //Call by Reference

#include <iostream>
using namespace std;

class MyClass
{
	int num = 0;
public:
	MyClass(int a) : num(a) { }
	void Add() { ++num; }
	void Show() { cout << num << endl; }
};

MyClass FuncByValue(MyClass obj) { obj.Add();	return obj; }
MyClass* FuncByAddress(MyClass* obj) { obj->Add();	return obj; }
MyClass& FuncByReference(MyClass& obj) { obj.Add();	return obj; }

int main(void)
{
	MyClass x(1); //x.Show();

	//MyClass* pClass = &x;
	//pClass->Show();	//(*pClass).Show();

	MyClass  a = FuncByValue(x); a.Show();
	MyClass* b = FuncByAddress(&x); b->Show();
	MyClass& c = FuncByReference(x); c.Show();

	// 참조 반환의 경우 //둘의 차이점은?
	MyClass  d1 = FuncByReference(x);
	MyClass& d2 = FuncByReference(x);

	return 0;
}

//클래스 인스턴스 전달, 반환 ------------------------------------------------------	
//Pass by Reference //Call by Reference

#include <iostream>
using namespace std;

class MyClass
{
	int num = 0;
public:
	MyClass(int a) : num(a) { }
	void Show() { cout << num << endl; }

	MyClass  GetObject() { return  MyClass(0); }	//객체생성 반환
	MyClass* GetPointer() { return  this; }			//객체주소 반환
	MyClass& GetReference() { return  *this; }		//객체자신 반환

};

int main(void)
{
	MyClass x(1);
	MyClass  a = x.GetObject(); a.Show();		// MyClass(0) copy
	MyClass* b = x.GetPointer(); b->Show();		// &x
	MyClass& c = x.GetReference(); c.Show();    // x
}


//Player 클래스를 만들고, hp 맴버 선언하고 초기값 100 을 설정하세요
// 
//객체를 생성한 후 
//생성된 객체를 전달 받아, (Call by Reference)
//hp를 감소 시키는 Damage 함수를 만들어 보세요.



