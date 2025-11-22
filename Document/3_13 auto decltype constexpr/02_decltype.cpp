// decltype  
// 
//		식의 구체적인 타입을 알려준다.  		
//		타입 연산에서만 사용해야지, 실제로 런타임에 사용하면 오류
// 
//		decltype( 타입을 알고자 하는 식별자 표현식 )

#include <iostream>
using namespace std;

struct A {
	double d;
};

int main() 
{
	//괄호로 둘러쌓이지 않은 식별자 표현식(id-expression) 이라면 해당 식의 타입을 얻을 수 있습니다
	//    어떠한 연산을 하지 않고 단순히 객체 하나만을 가리키는 식
	//    변수의 이름, 함수의 이름, enum 이름, 클래스 멤버 변수 등 ***

	int a = 3;
	decltype(a) b = 2;			// int

	int& ra = a;
	decltype(ra) rb = b;		// int&

	int&& x = 3;
	decltype(x) y = 2;			// int&&

	A* aa;
	decltype(aa->d) dd = 0.1;   // double
}

/*
https://modoocode.com/294

// decltype ---------------------------------------------

//괄호로 둘러쌓이지 않은 식별자 표현식(id-expression) 이라면 해당 식의 타입을 얻을 수 있습니다 ***

	어떠한 연산을 하지 않고 단순히 객체 하나만을 가리키는 식
	변수의 이름, 함수의 이름, enum 이름, 클래스 멤버 변수 등

//식별자 표현식이 아닌 식을 전달하면	***

	만일 식의 값 종류가 prvalue 라면	decltype 는 T 가 됩니다.
	만일 식의 값 종류가 lvalue 라면	decltype 는 T& 가 됩니다.
	만일 식의 값 종류가 xvalue 라면	decltype 는 T&& 가 됩니다.


	int a, b;
	decltype(a + b) c;		// c 의 타입은?		//a + b 는 prvalue --> int

	int a;
	decltype((a)) b;		// b 의 타입은?		//int&  //괄호 때문에 (a) 는 lvalue --> int&
		
// Value Category ---------------------------------------
https://docs.microsoft.com/ko-kr/cpp/cpp/lvalues-and-rvalues-visual-cpp?view=msvc-170
   
	C++ 의 모든 식에는 두 가지 꼬리표가 따라다니는데 하나는 타입이고, 다른 하나는 값 카테고리(value category)	

	lvalue 는						좌측값, 
	xvalue (eXpiring value) 는		소멸하는 값, 
	prvalue (pure rvalue) 는			순수 우측값,
	glvalue (generalized lvalue) 는 일반화된 좌측값 (lvalue + xvalue)
	rvalue 는						우측값 (prvalue + xvalue)
				
	    glvalue   rvalue
		/    \	  /    \	
	lvalue   xvalue  prvalue

---------------------------------------------------------
					이동 시킬 수 있다		이동 시킬 수 없다
정체를 알 수 있다		xvalue				lvalue
정체를 알 수 없다		prvalue				쓸모 없음!

// prvalue 식

	정체를 알 수 없는, 즉 주소값을 취할 수 없습니다, 좌측에 올 수 없습니다.
	우측값 레퍼런스와 상수 좌측값 레퍼런스를 초기화 하는데 사용

	int&& rr = 42;
	const int& r = 42;	
	// int& rrr = 42; <-- 불가능

	문자열 리터럴을 제외 한 모든 리터럴들. ( 예를 들면, 42, true, nullptr 등 )
	레퍼런스가 아닌 것을 리턴하는 함수의 호출식. ( 예를 들어서 str.substr(1, 2), str1 + str2 )
	후위 증감 연산자 식. ( a++, a-- )
	산술 연산자, 논리 연산자 식들. a + b, a && b, a < b 같은 것들을 말합니다. 물론, 이들은 연산자 오버로딩 된 경우들 말고 디폴트로 제공되는 것들.
	주소값 연산자 식. ( &a )
	a.m, p->m 과 같이 멤버를 참조할 때. 이 때 m 은 enum 값이거나 static 이 아닌 멤버 함수여야함.
	this
	enum 값
	람다식 ( 예를 들면, []() { return 0;};  )


	int f() { return 10; }
	f();					// <-- ?


// lvalue 식

	이름을 가진 대부분의 객체, 해당 객체의 주소값을 취할 수 있다. ( ex) int i; )

	변수, 함수의 이름, 어떤 타입의 데이터 멤버. ( 예컨대 std::endl, std::cin 등등 )
	좌측값 레퍼런스를 리턴하는 함수의 호출식.  ( std::cout << 1 이나 ++it 같은 것들 )
	a = b, a += b, a *= b 같이 복합 대입 연산자 식들.
	++a, --a 같은 전위 증감 연산자 식들.
	a.m, p->m 과 같이 멤버를 참조할 때. 이 때 m 은 enum 값이거나 static 이 아닌 멤버 함수인 경우 제외.
	a[n] 과 같은 배열 참조 식들.
	문자열 리터럴. ( "hi" )


	class A {
	  int f();			// static 이 아닌 멤버 함수
	  static int g();	// static 인 멤버 함수
	}
	A a;
	a.f;				// <-- ?	lvalue 아님 (prvalue) (비정적맴버함수)
	a.g;				// <-- ?	lvalue (static 맴버함수)

	void f(int&& a) {
		a;				// <-- ?	a 의 값 카테고리 는 lvalue (변수), 타입 은 우측값 레퍼런스.
	}


// xvalue 식

	좌측값 처럼 정체가 있지만 이동도 시킬 수 있는 것, 좌측값 이동하기 위해서는 xvalue 로 변경해서 사용해야 함 

		표현식 안에서 구체화된 rvalue의 임시객체
		rvalue 참조
		rvalue 참조 캐스팅.  (캐스팅 결과가 rvalue이므로 임시객체로 만든다.)	

	우측값 레퍼런스를 리턴하는 함수의 호출식, 대표적으로 std::move(x)

		template <class T>
		constexpr typename std::remove_reference<T>::type&& move(T&& t) noexcept;

	lvalue 처럼 좌측값 레퍼런스를 초기화 하는데 사용할 수도 있고, 
	prvalue 처럼 우측값 레퍼런스에 붙이거나 이동 생성자에 전달해서 이동 시킬 수 있습니다.


// 상황에 따라 달라지는 표현식 --------------------------------------------------------------------

	콤마 연산자 ( a, b, c, ...)
		맨 우측 값이 lvalue이면, 전체 표현식도 lvalue.
		맨 우측 값이 xvalue이면, 전체 표현식도 xvalue.
		맨 우측 값이 prvalue이면, 전체 표현식도 prvalue.

	삼항 연산자 ( a ? b : c )
		b와 c가 lvalue이면, 전체 표현식도 lvalue.
		b와 c가 xvalue 이면, 전체 표현식도 xvalue.
		b와 c가 prvalue이면, 전체 표현식도 prvalue.

	배열 첨자 연산자 ( arr[n] )
		arr[n]이 lvalue이면, 전체 표현식도 lvalue.  // 다차원배열에서 arr[n]은 또다른 배열의 이름이므로 lvalue
		arr[n]이 xvalue이면, 전체 표현식도 xvalue.
		arr[n]이 prvalue이면, 전체 표현식도 prvalue.


// decltype 필요한 경우 -----------------------------------------------------------------------
//		주로 주어진 템플릿 인자에 기반한 generic programming의 어려움을 해소하기 위해 도입

	//auto와 구별하기 - auto 는 엄밀히 말하자면 정확한 타입을 표현하지 않습니다
	//
	//auto		가 값에 상응하는 타입을 추론시켜주는 키워드라면,
	//decaltype 은 값으로부터 타입을 추출해 낼 수 있는 키워드

	const int i = 4;
	auto j = i;					// int			j = i;
	decltype(i) k = i;			// const int	k = i;		//decltype 의 경우 const 그대로 보존

	int arr[10];
	auto arr2 = arr;			// int*		arr2 = arr;
	decltype(arr) arr3;			// int		arr3[10];		//decltype 의 경우 배열 타입 그대로를 전달


	//어떤 객체의 타입이 템플릿 인자들에 의해서 결정되는 경우

	template <typename T, typename U>
	void add(T t, U u, ??? result) {					// 무슨 타입이 와야 할까요? 
		*result = t + u;
	}

	template <typename T, typename U>
	void add(T t, U u, decltype(t + u)* result) {		//decltype 로 해결
		*result = t + u;
	}


	template <typename T, typename U>
	decltype(t + u) add(T t, U u) {			 // error
		return t + u;
	}

	template <typename T, typename U>
	auto add(T t, U u) -> decltype(t + u)    //함수의 리턴값을 인자들 정의 부분 뒤에 //C++ 14 부터 추가된 문법
	{
	  return t + u;
	}


// declval -----------------------------------------------------------------------
//		- 타입의 생성자 호출을 우회해서 멤버 함수의 타입에 접근
//		T 의 생성자를 직접 호출하지 않더라도 T 가 생성된 객체를 나타낼 수 있습니다
//		실제로 런타임에 사용하면 오류

//		decltype 안에 들어가는 식은, 그냥 식의 형태로만 존재할 뿐, 
//		컴파일 시에 decltype() 전체 식이 타입으로 변환되기 때문에, 
//		decltype 안에 있는 식은 런타임 시에 실행되는 것이 아닙니다.

	#include <utility>

	template <typename T>
	decltype(std::declval<T>().f()) call_f_and_return(T& t) {
	  return t.f();
	}

	struct A {
	  int f() { return 0; }
	};
	struct B {
	  B(int x) {}
	  int f() { return 0; }
	};

	int main() {
	  A a;
	  B b(1);

	  call_f_and_return(a);  // ok
	  call_f_and_return(b);  // ok
	}

//참고로 C++14 부터는 함수의 리턴 타입을 컴파일러가 알아서 유추해주는 기능이 추가되었습니다. 
//이 경우 그냥 함수 리턴 타입을 auto 로 지정해주면 됩니다.

	template <typename T>
	auto call_f_and_return(T& t) {
	  return t.f();
	}

// decltype(auto) 
//		- auto 타입은 템플릿 타입 추론에 의해 결정이므로 그대로 전달하려면 decltype로 감싸면 됨

//즉, auto 타입 반환을 하려거든 다음 둘 중 하나를 선택하면 된다. 
//
//		C++11의 후행 반환 형식을 지정해 주던가
//		C++14의 decltype(auto)의 형태로 반환하던가 ***

*/
