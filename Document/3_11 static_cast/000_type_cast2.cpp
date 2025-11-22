//C++의 네가지 타입변환 연산자 
//	    satic_cast, dynamic_cast, reinterpret_cast, const_cast

//const_cast<new_type>(expression)
//		포인터(pointer) 또는 참조형(reference)의 	상수성(const)를 잠깐 제거해주는데 사용
//		volatile 키워드를 잠깐 제거해 주는 데에도 사용이 가능

#include <iostream>
using namespace std;

int main(void)
{
	// 포인터(pointer) 상수성(const) 제거

	char str[] = "apple";
	const char* ptr = str;
	cout << "before : " << str << endl;

	//ptr[0] = 'Q';		// error

	char* c = const_cast<char*>(ptr);
	c[0] = 'Q';
	cout << "after : " << str << endl;


	//참조형(reference) 상수성(const) 제거

	int tmp = 15;
	const int& ref = tmp;
	cout << "before : " << tmp << endl;

	// ref = 20;	// error

	int& r = const_cast<int&>(ref);
	r = 30;
	cout << "after : " << tmp << endl;

	return 0;
}

//% 원래 const로 선언된 객체의 값을 강제로 바꾸면 UB(Undefined Behavior) 발생 가능
//
//1. const 로 선언된 변수에 대해서는 const_cast를 사용하지 않는다.
//2. const_cast를 사용할 때는 변수에 대해 포인터를 새로 만들고 사용해야 한다


//const_cast 안전한 사용 --------------

void print(int* p) {
	*p = 100;
	cout << *p << endl;
}

int main() {
	const int a = 10;
	print(const_cast<int*>(&a)); 
	// const_cast를 써도 실제로는 non-const 메모리를 바꾸는 것 → 안전

	return 0;
}

//도대체 상수로 선언한 값을 왜 바꾸고 싶어하는 걸까 ?
//	const_casting에서는 non-const 변수에 대해 pointer 나 reference로 접근하는 포인터에 대해 적용한다.
//
//	원래 수정가능했던 변수를 
//  수정하지 못하도록 const로 선언했던 pointer나 reference 에서 
//	다시 원래 변수를 수정하고 싶을 때 사용한다.

#include<iostream>
#include<cstdio>
using namespace std;

int main(void)
{
	struct type
	{
		int i;
		type(int i) : i(i) {};

		void foo() {
			i++;
		}
		void bar() const {
			const_cast<type*>(this)->i++;
		}
	};

	type t1 = type(3);
	t1.foo();
	t1.bar();
	std::cout << t1.i << '\n';

	// not correctly use //잘못된 사용 예시

	const type t2 = type(3);
	//t2.foo(); //error
	t2.bar();
	type* ptr_t2 = const_cast<type*>(&t2);
	ptr_t2->foo();
	std::cout << t2.i << '\n';			//t2 가 수정됨 - const 해놓고 수정 ???

	// correctly use  //올바른 사용 예시

	type t3 = type(3);
	const type& ref_t3 = t3;
	//ref_t3.foo(); //error
	ref_t3.bar();
	type* ptr_t3 = const_cast<type*>(&ref_t3);  //const type&
	ptr_t3->foo();
	std::cout << t3.i << '\n';			//t3 가 수정됨 // ok
}


/*
// volatile
//		휘발성, 값을 항상 메모리에만 보관하라는 의미
//		volatile 선언하면 항상 메모리에 접근해야 하므로 컴파일러는 최적화하지 않음.

	#include <iostream>
	using namespace std;

	int main()
	{
		volatile int i = 0;		// volatile로 선언하여 항상 메모리에 접근하도록 만듦

		while (i < 10)			// volatile 선언하면 항상 i의 메모리에 접근해야 하므로 컴파일러는 반복문을 없애지 않음
			i++;

		//int i = 10;			// 선언 안하면 컴파일러는 반복문을 없애버리고 10을 할당 (Visual Studio의 /O2 옵션, GCC의 -O3 옵션)

		printf("%d\n", i);		// 10

		return 0;
	}
*/