#include <iostream>
using namespace std;

void TestFunc(int)
{}

void main(void)
{
	//초기화 ----------------------------------------
	int a = 1;
	int a(1);	//C++
	int a{1};	//C++11

	int b(a);	//copy
	int(10);	//이름없는 인스턴스

	//auto -----------------------------------------  
	int a = 1;
	auto c(a);	//int //형 자동 설정	

	//void(*pfTest)(int) = TestFunc;
	auto pfTest(TestFunc);		//함수포인터 처럼 복잡한 표현인 경우 유용

	//auto ----------------------------------------
	int buffer[5] = { 0,1,2,3,4 };
	for (auto i : buffer)		//형 자동 설정 //다양한 자료형에 자동 대응
	{
		cout << i << endl;
	}

	//r-value 참조 --------------------------------
	int d = 10;			//값 할당
	int &r   = d;			//l-value 참조	// 주소를 가지고 있는 것들.
	int &&rr = 5;		//r-value 참조	// 임시객체에 대한 참조, 상수 //곧 사라질 대상.
	const int& cr = 5;	//const l-value 참조 // 상수값 수명 연장.


	//auto 타입 추론 -------------------------------
	auto r1 = d;		//int		//추론할 때 &,const 무시된다.
	auto& r2 = d;		//int&		//&,const로 받기 위해서는 선언할 때 붙여야 한다.
	
	//보편참조 -------------------------------------
	auto&& ur1 = d;		//double&		//l-value 면 l-value 참조로 
	auto&& ur2 = 1.5;		//double&&		//r-value 면 r-value 참조로 
}


/*

//타입 추론(type inference)
//		auto 키워드를 사용하면 초깃값의 형식에 맟춰 선언하는 인스턴스(변수)의 형식이 '자동'으로 결정된다
//		auto 추론을 할때 &,const 는 사라진다. (추론규칙 별도 숙지 필요, 템플릿과 유사)

//아래와 같이 for문에서 auto를 사용해 자료형을 추론해 출력할 수 있다.

	#include <iostream>
	int main() {
		auto arr = { 1, 2, 3, 4 };		//
		for (auto number : arr)
			std::cout << number << '\n';
		return 0;
	}

//auto 키워드는 포인터와 참조자를 붙일 수 있다.

	#include <iostream>
	using namespace std;
	int main() 
	{	
		int a = 1.2;
		auto& b = a;		// &,const 는 선언할 때 붙여야 한다. ***
		auto* c = &b;		// *는 붙이지 않아도 *로 추론되지만, *를 표기하면 명확해짐  
	}

//auto 키워드가 함수의 반환 타입을 자동으로 추론할 수 있도록 확장됨. ***
	auto add(int x, int y) { return x + y; }

//auto 키워드는 함수 매개 변수와 함께 사용할 수 없다. (대상이 있어야 함.)
	void addAndPrint(auto x, auto y) { std::cout << x + y; }		//error

//auto 키워드는 구조체나 공용체, 클래스도 가능하다.
//auto 키워드는 구조체나 클래스의 멤버 변수로 사용 불가(해당 객체 자료형 크기를 모르기 때문)
	struct S { auto n; };		//error


//람다 
//
//함수 (참조자 리턴 시)
//		함수의 인자가 속한 괄호에 -> 를 명시해주고 리턴자료형 &를 붙여줌
//참조자 외에는 자료형을 명시하지 않아도 
//		return값을 기준으로 auto 자동으로 리턴자료형을 판단함
//		이 때 주의점은 auto&를 하게 되면 함수의 참조자가 되는 것이지 리턴형의 참조자가 되는 것은 아님!

	#include <iostream>
	using namespace std;
	int main() 
	{
		auto test = [](int* a)->int& {return *a; };			// test 는 람다 타입 이다.
		return 0;
	}

cf) typeid(변수이름).name()을 사용하면 '런타임'에 개체의 형식을 확인할 수 있다.

	#include <iostream>
	using namespace std;

	void main()
	{
		cout<< typeid(int).name() << endl;			//기본 자료형
		cout<< typeid(type_info).name() << endl;	//클래스
		cout<< typeid(main).name() << endl;			//함수
		cout<< typeid(cout).name() << endl;			//객체

		//그 밖에 enum, 사용자 정의 클래스, 멤버 함수, 람다 함수까지도 받을 수 있는 연산자
	}
*/
