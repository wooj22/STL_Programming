// 연산자 오버로딩 (Operator Overload)
// 
//		클래스 객체에 대한 연산자를 정의할 수 있다. 
//		operator 키워드 뒤에 연산자를 쓴 함수로 표현.

// 오버로드 vs 오버라이딩
//	  오버로딩 - 다른 함수에 대해 같은 이름 사용, 시그니처 변화
//	  오버라이딩 - 상속관계에서 같은 함수 재정의, 시그니처 안 변함

// 연산자 오버로딩 2가지 방법
//	  맴버함수, 전역함수 두가지 방법으로 구현 가능하다. 


#include<iostream> 
using namespace std;

class MyClass
{
	int num;
public:
	MyClass(int x = 0) : num(x) { }
	void Show() { cout << num << endl; }

	//1. 맴버함수 // operator+라는 이름의 함수 //연산자 재정의
	MyClass operator+(const MyClass& ref)
	{
		MyClass pos(num + ref.num);
		return pos;
	}

	friend MyClass operator+(const MyClass& obj1, const MyClass& obj2);
};

//2. 전역함수 // private 맴버를 사용한다면 friend 선언 필요
MyClass operator+(const MyClass& obj1, const MyClass& obj2)
{
	MyClass pos(obj1.num + obj2.num);
	return pos;
}

void main()
{
	MyClass a(1); a.Show();
	MyClass b(2); b.Show();

	MyClass c = a + b; c.Show();			// MyClass 객체에 대하여 + 연산하기

	//MyClass c = a.operator+(b);			//1. 맴버함수  //인스턴스가 첫번째 피연산자

	//MyClass c = operator+(a, b);			//2. 전역함수  //매개변수가 피연산자


	MyClass d = a + 5; d.Show();			// 5 -> MyClass(5) , 암시적 형변환
	//MyClass d = a.operator+(1);
}


//연산자 오버로드를 하는 이유
//		연산자 만들어 주면 사용자 편리. 직관적. 유지보수비용 절감 ***
