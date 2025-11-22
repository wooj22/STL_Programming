// 연산자 오버로딩  활용 // * 포인터 연산자 오버로딩 // 객체를 포인터 처럼 다루는 것이 가능.

// 스마트 포인터 구현하기 - 알아서 소멸되는 편리한 포인터.

#include <iostream>
using namespace std;

class Pos
{
private:
	int xpos, ypos;
public:
	Pos(int x = 0, int y = 0) : xpos(x), ypos(y) { cout << "Pos 객체 생성" << endl; }
	~Pos() { cout << "Pos 객체 소멸" << endl; }
	void SetPos(int x, int y) { xpos = x; ypos = y; }
	friend ostream& operator<<(ostream& os, const Pos& pos);
};
ostream& operator<<(ostream& os, const Pos& pos) {
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

class SmartPtr
{
private:
	Pos* ptr;
public:
	SmartPtr(Pos* p) : ptr(p) { }		//동적 할당된 포인터 
	~SmartPtr() { delete ptr; }				//알아서 자동으로 소멸 //RAII

	Pos& operator*() const		// 연산자 정의 
	{
		return *ptr;
	}
	Pos* operator->() const		// raw 포인터 반환
	{
		return ptr;
	}
	
	
};

int main()
{
	SmartPtr sptr1(new Pos(1, 2));  //선언할때 생성하면 사라질때 자동 소멸
	SmartPtr sptr2(new Pos(2, 3));
	cout << *sptr1;
	cout << *sptr2;

	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	cout << *sptr1;
	cout << *sptr2;

	return 0;
}


//템플릿 참고
// http://tcpschool.com/cpp/cpp_template_smartPointer

//스마트 포인터 기능은 c++11이후 부터  추가되었다. memory 헤더파일을 include해야 사용 가능하다.
//	unique_ptr
//	shared_ptr 
//	weak_ptr
//	auto_ptr은 C++11 표준부터 삭제

