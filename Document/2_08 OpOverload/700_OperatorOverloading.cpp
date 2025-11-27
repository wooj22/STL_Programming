//연습) 연산자 오버로드 연습 //클래스간의 연산자 + 를 정의해보자. ----------------------------

#include <iostream>
using namespace std;

class Pos
{
private:
	int x, y;
public:
	Pos(int x = 0, int y = 0) : x(x), y(y) {  }
	void ShowPosition()	{
		cout << '[' << x << ", " << y << ']' << endl;
	}

	//Pos operator+(const Pos& ref)    //operator+라는 이름의 함수 //연산자 정의
	//{
	//	Pos pos(x + ref.x, y + ref.y);
	//	return pos;
	//}

	//friend Pos operator+(const Pos& a, const Pos& b);
};

//Pos operator+(const Pos& a, const Pos& b)    //operator+ 함수 
//{
//	Pos pos(a.x + b.x, a.y + b.y);
//	return pos;
//}

int main(void)
{
	Pos pos1(3, 4);
	Pos pos2(1, 2);
	pos1.ShowPosition();
	pos2.ShowPosition();

	Pos pos3 = pos1 + pos2;  //클래스간의 연산자 + 를 정의해보자. 
	//pos3.ShowPosition();

	return 0;
}


//연산자 오버로딩 << 만들어 보자 ------------------------------------------------------------
// 
// 클래스 객체를 cout 으로 출력하자.
// 
// cout << x; 사용했을 때,  num 값이 출력하도록 연산자 정의하기. 
// 참고) cout 정의 : ostream cout;

#include <iostream>
using namespace std;

class Num
{
	int num = 0;					
public:
	int Get(int a) { return num; }
	void Set(int a) { num = a; }

	//1. 연산자 오버로딩 <<   
	ostream& operator<<(ostream& os);				// 맴버 함수로 구성할 수가 없다. x << cout 이 되므로. ***

	friend ostream& operator<<(ostream& os, const Num& obj);	//friend 함수로 구현
};

//2. 연산자 오버로딩 <<  
ostream& operator<<(ostream& os, const Num& obj)  // 연속적으로 출력하려면 반환값이 ostream&
{
	os << obj.num;
	return os;
}

int main(void) 
{
	Num x; Num y; x.Set(1);

	cout << x;			// operator<<(cout, x);

	cout << x << " " << y << endl;

	return 0;
}