// 연산자 오버로딩 활용 
//	* 포인터 연산자 오버로딩 // 객체를 포인터 처럼 다루는 것이 가능.

#include <iostream>
using namespace std;

class Position_Pointer
{
private:
	int* ptr;
public:
	Position_Pointer(int* ptr) : ptr(ptr)		//new 할당된 ptr 을 받음
	{
	}
	~Position_Pointer()
	{
		delete ptr;					//알아서 자동으로 소멸 //RAII
	}

	//int& operator*() const		// 연산자 정의 
	//{
	//	return *ptr;
	//}
	//int* operator->() const		// raw 포인터 반환
	//{
	//	return ptr;
	//}

};

int main()
{
	Position_Pointer sptr(new int(1));  //선언할때 생성하면 사라질때 자동 소멸

	cout << *sptr << endl;		//객체를 포인터처럼 사용
	*sptr = 10;
	cout << *sptr << endl;

	return 0;
}


// 스마트 포인터 구현하기 - 알아서 소멸되는 편리한 포인터.

#include <iostream>
using namespace std;

class Pos
{
private:
	int xpos, ypos;
public:
	Pos(int x = 0, int y = 0) : xpos(x), ypos(y) { 	cout << "Pos 객체 생성" << endl;	}	
	~Pos() { cout << "Pos 객체 소멸" << endl;	}
	void SetPos(int x, int y) {	xpos = x; ypos = y;	}
	friend ostream& operator<<(ostream& os, const Pos& pos);
};
ostream& operator<<(ostream& os, const Pos& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}
/*
int main()
{
	//Pos p1(1, 2);	cout << p1;

	Pos* p = new Pos(1, 2);
	cout << p;
	delete p;
}
*/

class SmartPtr
{
private:
	Pos* posptr;
public:
	SmartPtr(Pos* ptr) : posptr(ptr)
	{  
	}
	~SmartPtr()
	{
		delete posptr;			//알아서 자동으로 소멸 //RAII
	}

	Pos& operator*() const		// * 연산자 정의 
	{
		return *posptr;	// 객체 반환
	}
	Pos* operator->() const		// -> 연산자 정의	
	{
		return posptr;	// raw 포인터 반환
	}
};

int main()
{
	//Pos* p = new Pos(1, 2);	cout << p;	delete p;

	SmartPtr sp(new Pos(1, 2));
	//cout << *(sp.posptr);

	sp->SetPos(1, 2);
	cout << *sp;		//??
}
