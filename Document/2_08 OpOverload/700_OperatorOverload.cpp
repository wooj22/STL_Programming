//내가 만든 클래스에서 연산자를 사용하는 방법

// 연산자 오버로딩 (Operator Overload)
// 
//		클래스 객체를 다루기 위한 '연산자'를 정의할 수 있다. 
//		operator 키워드 뒤에 연산자를 쓴 '함수'로 표현.
//		피연산자를 매개변수로 전달.

// 오버로드 vs 오버라이딩
//	  오버로딩 - 다른 함수에 대해 같은 이름 사용, 시그니처 변화
//	  오버라이딩 - 상속관계에서 같은 함수 재정의, 시그니처 안 변함

/*
	class MyClass
	{
		int num;
	public:
		MyClass(int x = 0) : num(x) { }
	};

	int main()
	{
		MyClass a(1);
		MyClass b(2);

		MyClass c = a + b;		//error	//연산자를 사용하자.
	}
*/

// 연산자 오버로딩 2가지 방법
//	  맴버함수, 전역함수 두가지 방법으로 구현 가능하다. 


#include<iostream> 
using namespace std;

class Num
{
	int num;
public:
	Num(int x = 0) : num(x) { }
	void Show() { cout << num << endl; }

	//1. 맴버함수 // operator+라는 이름의 함수 //연산자 재정의
	Num operator+(const Num& ref)
	{
		Num pos(num + ref.num);
		return pos;
	}

	friend Num operator+(const Num& obj1, const Num& obj2);
};

//2. 전역함수 // private 맴버를 사용한다면 friend 선언 필요
Num operator+(const Num& obj1, const Num& obj2)
{
	Num pos(obj1.num + obj2.num);
	return pos;
}

int main()
{
	Num a(1); a.Show();
	Num b(2); b.Show();

	Num c = a + b; c.Show();			// MyClass 객체에 대하여 + 연산하기

	//MyClass c = a.operator+(b);			//1. 맴버함수  //인스턴스가 첫번째 피연산자

	//MyClass c = operator+(a, b);			//2. 전역함수  //매개변수가 피연산자


	//아래 코드는?
	Num d = a + 5; d.Show();			// 5 -> MyClass(5) , 암시적 형변환
	//MyClass d = a.operator+(5);
}


//연산자 오버로드를 하는 이유
//		연산자 만들어 주면 사용자 편리. 
//		직관적. 유지보수비용 절감 ***
